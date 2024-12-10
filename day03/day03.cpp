#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>

bool verifierChaine(const std::string &chaine)
{
    // Expression régulière : un ou plusieurs chiffres, suivis d'une virgule et de chiffres
    std::regex pattern("^\\d+,\\d+$");

    // Vérifie si la chaîne correspond au motif
    return std::regex_match(chaine, pattern);
}

int main()
{
    std::string text, line;
    std::ifstream input("input.txt");
    while (std::getline(input, line))
        text += line;
    std::string tmp = "";
    int final = 0;
    while (tmp != text)
    {
        text.erase(0, text.find("mul("));
        std::string tmp = text.substr(0, text.find_first_of(')'));
        std::string ers = tmp;
        tmp.erase(0, 4);
        if (verifierChaine(tmp) == 1)
        {
            std::cout << tmp << std::endl;
            int temp = stoi(tmp.substr(0, tmp.find(','))) * stoi(tmp.erase(0, tmp.find(',') + 1));
            final += temp;
        }
        text.erase(0, ers.length());
    }
    std::cout << final << std::endl;
}