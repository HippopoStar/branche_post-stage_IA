#ifndef PUZZLE_H
# define PUZZLE_H

# include <fstream>
# include <iostream>
# include <string>
# include "Piece.hpp"

class	Puzzle
{
	public:

	Puzzle(const char *filename);
	~Puzzle(void);

	void	solve(void);

	private:

	Piece	**puzzle_board;
	int	is_puzzle;

	int	parse_file(const char *filename);
};

#endif
