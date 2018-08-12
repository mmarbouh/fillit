#include "fillit.h"

int		is_valid_char(char c)
{
	/*
	 * checks if a char is allowed. 1 if yes else 0.
	*/
	return ((c == '\n' || c == '#'|| c == '.')? 1 : 0);
}

int		check_all_chars(char *str)
{
	/*
	 * checks if chars are valid
	 * returns 1 if yes otherwise 0
	*/
	int		i;

	i = -1;
	while (str[++i])
	{
		if(!(is_valid_char(str[i])))
			return (0);
	}
	return (1);
}

int		check_all_tetriminos(char *str, int bytes)
{
	/*
	 *checks each block for 4 # and 12 .
	 * count1 counts tetriminoes parts
	 * count2 counts empty cells
	 */
	
	int n;
	int i;
	int count1;
	int count2;

	n = 0;
	while (n < bytes)
	{
		i = -1;
		count1 = 0;
		count2 = 0;
		while (++i < 19)
		{
			if (str[n + i] == '#')
				count1++;
			if (str[n + i] == '.')
				count2++;
		}
		if (count1 != 4)
			return (false);
		if (count2 != 12)
			return (false);
		n += 21;
	}
	return (true);
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
	if (str[--i] != '\n')
		++count;
	return (count/5);
}
