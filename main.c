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
	size_t n_blocks = has_newlines(input);
	char **test = load_input(input);
	rename_blocks(test);
	trim_newline(test);
	solve(test, n_blocks);
	//change_end(&input, n_blocks);
		
	/*DONT FORGET TO FREE input and test*/
	//free_afterload(test);
	return (0);
}