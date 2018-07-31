#ifndef FILLIT_H
# define FILLIT_H
# define BUFF_SIZE_FILL 1
# define BLOCK '#'
# define EMPTY '.'
# define NEWLINE '\n' 
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"

/*checking functions*/

# define V1(a) (a == '#' || a == '.')
# define V2(a) (a == '\n')
# define V3(a) (a == '#' || a == '.' || a == '\n')
# define DOT(a) (a == '.')
# define DO2(a, b) if(1){a; b;}
# define DO3(a, b, c) if(1){a; b; c;}
# define CHK(a, b) if(1){if(a){return(b);}}
# define CHK1(a, b, c) if(1){if(a){b; return(c);}}
# define CHK2(a, b, c, d) if(1){if(a){b; c; return(d);}}
# define CHK3(a, b, c, d, e) if(1){if(a){b; c; d; return(e);}}
# define CHK4(a, b, c, d, e, f) if(1){if(a){b; c; d; e; return(f);}}

/*Reading fuctions*/
char	*read_input(char *filename);
char	**load_input(char *input);
void	trim(char *str);

void	rename_blocks(char **src);
void	trim_newline(char **src);


/*Checking functions*/
int		has_newlines(char *str);
int		check_all_tetriminos(char *str);
int		check_tetriminos(char	*str);
int		check_chars(char *str);
int		is_valid_char(char c);

/*Validity*/
int		valid_pattern(char **src, int blocks);
void	populate_valid(int i, char valid[20][15]);
//t_bool		bool_strstr(const char *src, const char *to_find);

/*MAP*/
void	print_map(char **map, size_t size);
void	delete_map(char **map);
char	**new_map(size_t size);
size_t	initial_board_size(size_t nb_blocks);
char	get_letter(char *str);
/*bool struct*/
typedef	enum	e_bool
{
	false,
	true
} 				t_bool;
/*solving*/
t_bool	recursion(char **tbl, char **map, int col, int row);
t_bool	is_safe(char **map, char *tetri, int col, int row);
void	place(char **map, char *tetri, int col, int row);
void	remove_tetri(char **map, char *tetri, int col, int row);
int		solve(char **tbl, size_t blocks);
/*error handling and usage printing*/
void	error(void);


#endif