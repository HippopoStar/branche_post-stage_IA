#include "n_puzzle.hpp"

int		main(int argc, char **argv)
{
	Puzzle	*puzzle;
	int	i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			puzzle = new Puzzle(*(argv + i));
			puzzle->solve();
			delete puzzle;
			i++;
		}
	}
	else
	{
		std::cout << "usage: ./npuzzle <file.txt>" << std::endl;
	}
	return (0);
}
