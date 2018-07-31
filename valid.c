#include "fillit.h"


t_bool	bool_strstr(const char *src, const char *to_find)
{
	int			len;

	while (*src)
	{
		len = 0;
		while (*src == *to_find)
		{
			to_find++;
			src++;
			len++;
			if (!*to_find)
				return (true);
		}
		src = src - len;
		to_find = to_find - len;
		src++;
	}
	return (false);
}

void	populate_valid(int i, char valid[20][15])
{
	while (++i < 20)
	{
		ft_bzero(valid[i], sizeof(valid[i]));
	}
	strcpy(valid[0], "###...#");
	strcpy(valid[1], ".#...#..##");
	strcpy(valid[2], "#...###");
	strcpy(valid[3], "##..#...#");
	strcpy(valid[4], "###.#");
	strcpy(valid[5], "##...#...#");
	strcpy(valid[6], "..#.###");
	strcpy(valid[7], "#...#...##");
	strcpy(valid[8], "###..#");
	strcpy(valid[9], ".#..##...#");
	strcpy(valid[10], ".#..###");
	strcpy(valid[11], "#...##..#");
	strcpy(valid[12], ".##.##");
	strcpy(valid[13], "#...##...#");
	strcpy(valid[14], "##..##");
	strcpy(valid[15], "#...#...#...#");
	strcpy(valid[16], "####");
	strcpy(valid[17], ".#..##..#");
	strcpy(valid[18], "##...##");
}

int		valid_pattern(char **src, int blocks)
{
	char	valid[20][15];
	int		i;
	int		j;
	int		valid_flg;

	populate_valid(-1, valid);
	i = -1;
	while (++i < blocks)
	{
		valid_flg = 0;
		j = -1;
		while (++j < 19)
		{
			if (bool_strstr(src[i], valid[j]) == true)
			{
				ft_bzero(src[i], ft_strlen(src[i]));
				ft_strcpy(src[i], valid[j]);
				valid_flg = 1;
				break ;
			}
		}
		if (!valid_flg)
			return (0);
	}
	return (1);
}