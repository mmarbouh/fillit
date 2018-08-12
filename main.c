#include "fillit.h"

static void		display_tbl(char **t)
{
	int		i;

	i = -1;
	while (t[++i])
	{
		ft_putstr(t[i]);
		ft_putchar('\n');
	}
}

int		main(int ac, char **av)
{
	char	*input;
	int		bytes;

	if(ac != 2)
	{
		puts("print usage nigga !!");
		return (0);
	}
	input = read_input(av[1]);
	/* checking input validity*/
	bytes = ft_strlen(input);
	if (!(check_all_chars(input) && check_all_tetriminos(input, bytes) \
		&& has_newlines(input)))
		error();
	size_t n_blocks = has_newlines(input);
	char **test = load_input(input);
	trim_newline(test);
	CHK3(!valid_pattern(test, n_blocks), error(), free_afterload(test), free(input), 0)
	rename_blocks(test);
	solve(test, n_blocks);
	/*DONT FORGET TO FREE input and test*/
	free_afterload(test);
	free(input);
	return (0);
}
