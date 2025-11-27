#include <map>
#include <string>
#include <iostream>

int main() {
    std::map<std::string, std::string> data;

    data.insert({"charles", "geneve"});
    data.insert({"diane", "neuchatel"});
    data.insert({"etienne", "fribourg"});
    data.insert({"marie", "sion"});
    data.insert({"lucas", "montreux"});
    data.insert({"sophie", "vevey"});
    data.insert({"antoine", "nyon"});
    data.insert({"julie", "morges"});
    data.insert({"kevin", "zurich"});
    data.insert({"camille", "winterthour"});
    data.insert({"nathan", "lugano"});
    data.insert({"pierre", "baden"});
    data.insert({"claire", "aarau"});
    data.insert({"martin", "bienne"});
    data.insert({"lea", "delémont"});
    data.insert({"hugo", "sierre"});
    data.insert({"emma", "martigny"});
    data.insert({"maxime", "thun"});
    data.insert({"louise", "bulle"});
    data.insert({"victor", "zoug"});
    data.insert({"manon", "coire"});
    data.insert({"quentin", "schaffhouse"});
    data.insert({"elise", "st-gall"});
    data.insert({"adrien", "st-moritz"});
    data.insert({"pauline", "locarno"});
    data.insert({"renaud", "laris"});
    data.insert({"ines", "arth"});
    data.insert({"damien", "brig"});
    data.insert({"anaïs", "wetzikon"});
    data.insert({"gaspard", "uster"});
    data.insert({"jade", "frauenfeld"});
    data.insert({"thomas", "kreuzlingen"});
    data.insert({"maud", "wil"});
    data.insert({"fabrice", "glaris"});
    data.insert({"salomé", "herisau"});
    data.insert({"raphael", "altstätten"});
    data.insert({"noémie", "pfäffikon"});
    data.insert({"julien", "rapperswil"});
    data.insert({"celine", "lenzburg"});
    data.insert({"arnaud", "opfikon"});
    data.insert({"isabelle", "olten"});
    data.insert({"remi", "dietikon"});

    std::cout << "Entrer un nom (Ctrl+D pour terminer) :" << std::endl;
    for (std::string name; std::cin >> name;) {
        const auto it = data.find(name);
        if (it != data.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "Nom inconnu" << std::endl;
        }
        std::cout << "Entrer un nom (Ctrl+D pour terminer) :" << std::endl;
    }

    data["bob"] = "geneve"
}
