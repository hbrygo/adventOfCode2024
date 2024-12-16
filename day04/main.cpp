#include <iostream>
#include <fstream>
#include <regex>
#include <string>

static bool check(int x, int y, std::vector<std::string> &tab, int dx, int dy)
{
	const std::string xmas = "MAS";
	for (int i = 0; i < 3; ++i)
		if (tab[y + i * dy][x + i * dx] != xmas[i])
			return 0;
	return 1;
}

int main()
{
	std::string filename = "input.txt"; // Nom du fichier à lire
	std::ifstream file(filename);

	if (!file.is_open())
	{
		std::cerr << "Erreur : Impossible d'ouvrir le fichier." << std::endl;
		return 1;
	}
	std::string line;
	std::vector<std::string> tab;
	while (std::getline(file, line))
		tab.push_back(line);

	int res = 0;
	for (int i = 1; i < tab.size() - 1; ++i)
	{
		for (int j = 1; j < tab[i].size() - 1; ++j)
		{
			if (tab[i][j] == 'A')
			{
				int count = 0;
				count += check(j + 1, i + 1, tab, -1, -1);
				count += check(j - 1, i - 1, tab, 1, 1);
				count += check(j + 1, i - 1, tab, -1, 1);
				count += check(j - 1, i + 1, tab, 1, -1);
				res += count == 2;
			}
		}
	}
	std::cout << res << std::endl;
}