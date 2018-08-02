#include "fillit.h"

int		main(int ac, char **av)
{
	char *input;

	if(ac != 2)
	{
		puts("print usage nigga !!");
		return (0);
	}
	input = read_input(av[1]);
	size_t len = has_newlines(input);

	char **test = load_input(input);
	trim_newline(test);
	rename_blocks(test);
	//char **map = new_map(len);
	//print_map(map, initial_board_size(len));
	solve(test, len);
	free(input);
	return (0);
}