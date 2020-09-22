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
	size_t		parsed_lines;

	input_file.open(filename, std::ios::in);
	if (input_file.is_open())
	{
		(*this).puzzle_size = 0;
		parsed_lines = 0;
		while (std::getline(input_file, line))
		{
			std::cout << line << std::endl;
			if (!(((*this).puzzle_size == 0 ? (*this).parse_puzzle_size(line) : (*this).parse_puzzle_line(line, &parsed_lines)))
				|| (!((*this).puzzle_size == 0) && parsed_lines > (*this).puzzle_size))
			{
				std::cout << "The above line is invalid" << std::endl;
				input_file.close();
				return (0);
			}
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

int		Puzzle::parse_puzzle_size(const std::string &line)
{
	size_t		word_begin;
	size_t		word_end;
	std::string	word;

	word_begin = 0;
	while (line.at(word_begin) == '\t' || line.at(word_begin) == '\n'
		|| line.at(word_begin) == '\v' || line.at(word_begin) == '\f'
		|| line.at(word_begin) == '\r' || line.at(word_begin) == ' ')
	{
		word_begin++;
	}
	word_end = word_begin;
	while ('0' <= line.at(word_end) && line.at(word_end) <= '9')
	{
		word_end++;
	}
	if (word_end > word_begin)
	{
		word = line.substr(word_begin, word_end - word_begin);
		if (!((*this).parse_word(word, 0, (size_t *)0)))
		{
			return (0);
		}
	}
	while (word_end < line.length() && !(line.at(word_end) == '#'))
	{
		if (!(line.at(word_end) == '\t' || line.at(word_end) == '\n'
			|| line.at(word_end) == '\v' || line.at(word_end) == '\f'
			|| line.at(word_end) == '\r' || line.at(word_end) == ' '))
		{
			return (0);
		}
		word_end++;
	}
	return (1);
}

int		Puzzle::parse_puzzle_line(const std::string &line, size_t *parsed_lines)
{
	size_t		word_begin;
	size_t		word_end;
	std::string	word;
	size_t		parsed_words;

	parsed_words = 0;
	word_end = 0;
	while (word_end < line.length() && !(line.at(word_end) == '#'))
	{
		word_begin = word_end;
		while (line.at(word_begin) == '\t' || line.at(word_begin) == '\n'
			|| line.at(word_begin) == '\v' || line.at(word_begin) == '\f'
			|| line.at(word_begin) == '\r' || line.at(word_begin) == ' ')
		{
			word_begin++;
		}
		word_end = word_begin;
		while ('0' <= line.at(word_end) && line.at(word_end) <= '9')
		{
			word_end++;
		}
		if (word_begin < word_end)
		{
			word = line.substr(word_begin, word_end - word_begin);
			if (!((*this).parse_word(word, *parsed_lines, &parsed_words))
				|| (!((*this).puzzle_size == 0) && parsed_words > (*this).puzzle_size))
			{
				return(0);
			}
		}
	}
	if (parsed_words > 0)
	{
		(*parsed_lines)++;
	}
	return ((!(word_end < line.length()) || line.at(word_end) == '#') ? 1 : 0);
}

int		Puzzle::parse_word(const std::string &word, const size_t parsed_lines, size_t *parsed_words)
{
	(void)word;
	(void)parsed_lines;
	(void)parsed_words;
	std::cout << word << std::endl;
	//(*parsed_words)++;
	return (1);
}
