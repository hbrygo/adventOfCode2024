#include <iostream>
#include <fstream>
#include <regex>
#include <string>

static void solve(int x, int y, int dir, std::vector<std::string> &tab)
{
	for (;;)
	{
		// std::cout << x << " " << y << " " << dir << std::endl;
		if (x < 0 || x >= tab[0].size() || y < 0 || y >= tab.size())
			return;
		if (tab[y][x] == '#')
		{
			x -= (dir == 0) - (dir == 2);
			y -= (dir == 1) - (dir == 3);
			dir = (dir + 1) & 3;
		}
		tab[y][x] = '8';
		x += (dir == 0) - (dir == 2);
		y += (dir == 1) - (dir == 3);
	}
}

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
	std::vector<std::string> tab;
	while (std::getline(file, line))
		tab.push_back(line);

	int x = -1;
	int y = -1;
	int dir = -1;
	for (int i = 0; i < tab.size(); ++i)
	{
		for (int j = 0; j < tab[i].size(); ++j)
		{
			dir = std::string(">v<^").find(tab[i][j]);
			if (dir != std::string::npos)
			{
				x = j;
				y = i;
				// std::cout << "ici" << std::endl;
				break;
			}
		}
		if (dir != -1)
			break;
	}

	// 0 -> >
	// 1 -> v
	// 2 -> <
	// 3 -> ^
	int res = 0;
	solve(x, y, dir, tab);
	for (auto line : tab)
	{
		for (auto c : line)
		{
			res += (c == '8');
		}
	}
	std::cout << res << std::endl;
}