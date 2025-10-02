#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <clocale>   // setlocale
#include <cwchar>    // mbrtowc, wcwidth
#include <locale>

// ─────────────────────────────────────────────────────────────────────────────
// Table jolis cadres (gris) + gestion correcte des largeurs Unicode
// ─────────────────────────────────────────────────────────────────────────────

enum class Alignment { LEFT, CENTER, RIGHT };

struct Column {
    std::string header;
    Alignment align;
};

class Table {
public:
    explicit Table(std::string title)
        : title_(std::move(title)) {}

    void add_column(const std::string& name, Alignment align = Alignment::LEFT) {
        columns_.push_back({name, align});
    }

    void add_row(const std::vector<std::string>& row) {
        data_.push_back(row);
    }

    void print(std::ostream& os) const {
        const auto widths = col_widths();
        const std::size_t inner = inner_width(widths);

        // Couleurs
        constexpr const char* GREY  = "\x1b[90m";
        constexpr const char* RESET = "\x1b[0m";

        // Top border
        os << GREY << "┌" << repeat('─', inner) << "┐" << RESET << "\n";

        // Title line (texte normal, bordures grises)
        os << GREY << "│" << RESET;
        std::size_t used = 0;
        os << " " << title_ << RESET;
        used = 1 + display_width(title_);
        if (inner > used) os << repeat(' ', inner - used);
        os << GREY << "│" << RESET << "\n";

        // Separator under title: joints "┬" (pas de barre vers le haut)
        os << GREY << "├";
        for (std::size_t i = 0; i < columns_.size(); ++i) {
            os << repeat('─', widths[i] + 2 * kPadding);
            os << (i + 1 == columns_.size() ? "┤" : "┬");
        }
        os << RESET << "\n";

        // Header row
        os << GREY << "│" << RESET;
        for (std::size_t i = 0; i < columns_.size(); ++i) {
            os << " " << align_text(columns_[i].header, widths[i], columns_[i].align) << " ";
            if (i + 1 != columns_.size()) os << GREY << "│" << RESET;
        }
        os << GREY << "│" << RESET << "\n";

        // Header/Data divider (croix complètes "┼")
        os << GREY << "├";
        for (std::size_t i = 0; i < columns_.size(); ++i) {
            os << repeat('─', widths[i] + 2 * kPadding);
            os << (i + 1 == columns_.size() ? "┤" : "┼");
        }
        os << RESET << "\n";

        // Data rows
        for (const auto& row : data_) {
            os << GREY << "│" << RESET;
            for (std::size_t i = 0; i < columns_.size(); ++i) {
                const std::string cell = (i < row.size()) ? row[i] : "";
                os << " " << align_text(cell, widths[i], columns_[i].align) << " ";
                if (i + 1 != columns_.size()) os << GREY << "│" << RESET;
            }
            os << GREY << "│" << RESET << "\n";
        }

        // Bottom border
        os << GREY << "└";
        for (std::size_t i = 0; i < columns_.size(); ++i) {
            os << repeat('─', widths[i] + 2 * kPadding);
            os << (i + 1 == columns_.size() ? "┘" : "┴");
        }
        os << RESET << "\n";
    }

private:
    // Paramètres “propres”
    static constexpr int kPadding = 1; // espaces de chaque côté du contenu

    std::string title_;
    std::vector<Column> columns_;
    std::vector<std::vector<std::string>> data_;

    // Calcule la largeur d’affichage (terminal) d’une chaîne UTF-8
    static std::size_t display_width(const std::string& s) {
        std::mbstate_t st{};
        const char* ptr = s.data();
        const char* end = s.data() + s.size();
        std::size_t width = 0;

        while (ptr < end) {
            wchar_t wc;
            std::size_t len = std::mbrtowc(&wc, ptr, end - ptr, &st);
            if (len == static_cast<std::size_t>(-1) || len == static_cast<std::size_t>(-2)) {
                // Séquence invalide/incomplète : on avance d’un octet pour éviter la boucle infinie
                ++ptr;
                st = std::mbstate_t{};
                continue;
            }
            int w = ::wcwidth(wc);
            if (w > 0) width += static_cast<std::size_t>(w);
            // wcwidth retourne 0 pour combinaisons/contrôles invisibles → on n'ajoute rien
            ptr += (len == 0 ? 1 : len);
        }
        return width;
    }

    static std::string repeat(char ch, std::size_t n) {
        return std::string(n, ch);
    }

    std::string align_text(const std::string& text, std::size_t width, Alignment a) const {
        const std::size_t w = display_width(text);
        if (w >= width) return text;

        const std::size_t space = width - w;
        switch (a) {
            case Alignment::LEFT:
                return text + std::string(space, ' ');
            case Alignment::CENTER:
                return std::string(space / 2, ' ') + text + std::string((space + 1) / 2, ' ');
            case Alignment::RIGHT:
                return std::string(space, ' ') + text;
        }
        return text; // fallback
    }

    std::vector<std::size_t> col_widths() const {
        std::vector<std::size_t> widths(columns_.size(), 0);
        for (std::size_t i = 0; i < columns_.size(); ++i) {
            widths[i] = display_width(columns_[i].header);
        }
        for (const auto& row : data_) {
            for (std::size_t i = 0; i < row.size() && i < columns_.size(); ++i) {
                widths[i] = std::max(widths[i], display_width(row[i]));
            }
        }
        return widths;
    }

    // Largeur interne entre les deux bordures verticales
    static std::size_t inner_width(const std::vector<std::size_t>& widths) {
        std::size_t sum = 0;
        for (auto w : widths) sum += w + 2 * kPadding;       // contenu + padding
        if (!widths.empty()) sum += widths.size() - 1;       // séparateurs internes '│'
        return sum;
    }
};

int main() {
    // IMPORTANT : activer la locale pour UTF-8 (utilise la locale de l’environnement)
    std::setlocale(LC_ALL, "");
    try {
        std::locale::global(std::locale(""));
        std::cout.imbue(std::locale());
    } catch (...) {
        // Si la locale n'est pas dispo, on continuera quand même (UTF-8 souvent OK)
    }

    Table table("Exemple de tableau");

    table.add_column("Nom", Alignment::LEFT);
    table.add_column("Âge", Alignment::CENTER);
    table.add_column("Ville", Alignment::RIGHT);

    table.add_row({"Alice", "25", "Paris"});
    table.add_row({"Bob", "30", "Lyon"});
    table.add_row({"Charlie", "22", "Marseille"});

    table.print(std::cout);
}
