#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

enum class Alignment {
    LEFT,
    CENTER,
    RIGHT
};

class Table {
public:
    Table(std::string title) : title(title) {}

    void add_row(const std::string& name, Alignment align = Alignment::LEFT) {
        rows.push_back(name);
        aligns.push_back(align);
    }

    void add_column(std::initializer_list<std::string> data) {
        columns.push_back(data);
    }

    void print(std::ostream& os) {
        os << "=== " << title << " ===" << std::endl;

        // Find max width per column
        std::vector<size_t> colWidths;
        for (const auto& col : columns) {
            size_t maxLen = 0;
            for (const auto& item : col) {
                if (item.size() > maxLen) maxLen = item.size();
            }
            colWidths.push_back(maxLen);
        }

        // Print header row (if you want)
        if (!rows.empty()) {
            for (size_t i = 0; i < rows.size(); ++i) {
                os << align_text(rows[i], colWidths[i], aligns[i]) << " | ";
            }
            os << "\n";
        }

        // Determine number of rows to print
        size_t maxRows = 0;
        for (const auto& col : columns) {
            if (col.size() > maxRows) maxRows = col.size();
        }

        // Print data rows
        for (size_t row = 0; row < maxRows; ++row) {
            for (size_t col = 0; col < columns.size(); ++col) {
                std::string cell = (row < columns[col].size()) ? columns[col][row] : "";
                Alignment a = (col < aligns.size()) ? aligns[col] : Alignment::LEFT;
                os << align_text(cell, colWidths[col], a) << " | ";
            }
            os << "\n";
        }
    }

private:
    std::string align_text(const std::string& text, size_t width, Alignment a) {
        std::ostringstream oss;
        switch (a) {
            case Alignment::LEFT:
                oss << std::left << std::setw(width) << text;
                break;
            case Alignment::CENTER: {
                size_t space = (width > text.size()) ? (width - text.size()) / 2 : 0;
                oss << std::string(space, ' ') << text << std::string(width - text.size() - space, ' ');
                break;
            }
            case Alignment::RIGHT:
                oss << std::right << std::setw(width) << text;
                break;
        }
        return oss.str();
    }

    std::string title;
    std::vector<std::string> rows;
    std::vector<std::vector<std::string>> columns;
    std::vector<Alignment> aligns;
};

int main() {
    Table table("Exemple de tableau");

    table.add_row("Nom", Alignment::LEFT);
    table.add_row("Age", Alignment::CENTER);
    table.add_row("Ville", Alignment::RIGHT);

    table.add_column({"Alice", "Bob", "Charlie"});
    table.add_column({"25", "30", "22"});
    table.add_column({"Paris", "Lyon", "Marseille"});

    table.print(std::cout);
}
