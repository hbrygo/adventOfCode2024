#include <iostream>
#include <fstream>
#include <regex>
#include <set>
#include <string>

int main(int argc, char **argv)
{
	std::string filename = argv[1]; // Nom du fichier à lire
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
		return 1;
	}
	std::string line;
	std::map<int, std::set<int>> order;
	while (std::getline(file, line) && !line.empty())
	{
		int key = atoi(line.c_str());
		int value = atoi(line.substr(line.find('|') + 1).c_str());
		order[key].insert(value);
	}
	int res = 0;
	while (std::getline(file, line))
	{
		std::vector<int> tab;
		while (!line.empty())
		{
			int value = atoi(line.c_str());
			tab.push_back(value);
			if (line.find(',') == std::string::npos)
				break;
			line.erase(0, line.find(',') + 1);
		}

		// for (auto v : tab)
		// {
		// 	std::cout << v << " ";
		// }
		// std::cout << std::endl;
		bool valid = 1;
		for (int i = tab.size() - 1; i > 0; --i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (order[tab[i]].count(tab[j]))
				{
					valid = false;
					int tmp = tab[j];
					tab[j] = tab[i];
					tab[i] = tmp;
					j = 0;
				}
			}
		}
		if (!valid)
			res += tab[tab.size() / 2];
	}
	std::cout << res << std::endl;
}