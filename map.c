#include "fillit.h"

void	print_map(char **map, size_t size)
{
	size_t	i;

	i = -1;
	while (++i < size)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

void	delete_map(char **map)
{
	size_t	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		++i;
	}
	free(map);
}

char	**new_map(size_t size)
{
	int		i;
	int		j;
	int		n_size;
	char	**map;

	n_size = size + 3;
	if (!(map = (char **)malloc(sizeof(char*) * (n_size + 1))))
		return (NULL);
	ft_bzero(map, n_size);
	i = -1;
	while (++i < (int)size)
	{
		CHK1((map[i] = ft_strnew(n_size)) == 0, delete_map(map), 0);
		j = -1;
		while (++j < (int)size)
			map[i][j] = '.';
	}
	while (i < n_size)
	{
		CHK1((map[i] = ft_strnew(n_size)) == 0, delete_map(map), 0);
		++i;
	}
	map[i] = 0;
	return (map);
}

size_t	initial_board_size(size_t nb_blocks)
{
	size_t min_size;
	size_t i;

	i = 2;
	min_size = nb_blocks * 4;
	while (min_size > (i * i))
		i++;
	return (i);
}

char	get_letter(char *str)
{
	while (*str == '.')
		str++;
	return (*str);
}