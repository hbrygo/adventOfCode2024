#include <iostream>
#include <fstream>
#include <regex>
#include <string>

int main() {
    std::string filename = "input.txt"; // Nom du fichier à lire
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
        return 1;
	}
	std::string fullFile;
	std::string line;
	while (std::getline(file, line)) {
		fullFile += line + "\n";
	}
	printf("file:\n%s", fullFile.c_str());
}