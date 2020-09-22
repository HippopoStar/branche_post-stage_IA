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
	size_t	puzzle_size;

	int	parse_file(const char *filename);
	int	parse_puzzle_size(const std::string &line);
	int	parse_puzzle_line(const std::string &line, size_t *parsed_lines);
	int	parse_word(const std::string &word, size_t parsed_lines, size_t *parsed_words);
};

#endif
