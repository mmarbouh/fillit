#include "fillit.h"

int		is_valid_char(char c)
{
	/*
		+checks if char is allowed. 1 if yes else 0.
	*/
	return ((c == '\n' || c == '#'|| c == '.')? 1 : 0);
}

int		check_chars(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if(!(is_valid_char(str[i])))
			return (0);
		++i;
	}
	return (1);
}

int		check_tetriminos(char	*str)
{
	/*
		+Checks that a given tetriminos has 4 blocks.
		+Returns 1 if valid or 0 if not.
		+Params str is the pointer to the beginning 
			of the block in question.
	*/	
	int		i;
	int		count_blocks;
	int		count_newlines;

	if (strlen(str) < 20)
		return (0);
	i = 0;
	count_blocks = 0;
	count_newlines = 0;
	while (count_newlines < 5)
	{
		if (str[i] == '\n')
			++count_newlines;
		if (str[i] == '#')
			++count_blocks;
		++i;
	}
	return (count_blocks == 4);
}

int		check_all_tetriminos(char *str)
{
	/*
		+counts the number of #.
		+then compares it to the output of has_newlines times 4.
	*/
	int 	i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '#')
			++count;
		++i;
	}
	return ((has_newlines(str)*4 ==  count));
}

int		has_newlines(char *str)
{
	/*
		+Checks if there is a newline after each block.
		+Returns 0 at the first occurence of anomalie else rets count.
		+counts is the number of tetriminos.
		+No specified behavior for invalid input.
	*/
	int		i;
	int		count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (str[i] == '\n')
			++count;
		if (!((count) % 5) && str[i] != '\n')
			return (0);
		++i;
	}
	return (count/5);
}