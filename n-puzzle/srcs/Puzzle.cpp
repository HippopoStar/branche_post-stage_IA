#include "Puzzle.hpp"

/**
 * Constructor(s) & Destructor(s)
 */

Puzzle::Puzzle(const char *filename)
{
	this->is_puzzle = ((this->parse_file(filename)) ? 1 : 0);
}

Puzzle::~Puzzle(void)
{
}

/**
 * Public method(s)
 */

void	Puzzle::solve(void)
{
}

/**
 * Private method(s)
 */

int		Puzzle::parse_file(const char *filename)
{
	std::ifstream	input_file;
	std::string	line;

	input_file.open(filename, std::ios::in);
	if (input_file.is_open())
	{
		while (std::getline(input_file, line))
		{
			std::cout << line << std::endl;
		}
		input_file.close();
		return (1);
	}
	else
	{
		std::cout << "Unable to open file: " << filename << std::endl;
	}
	return (0);
}
