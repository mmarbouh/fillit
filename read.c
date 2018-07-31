#include "fillit.h"

void	error(void)
{
	ft_putstr("error\n");
}

char	*read_input(char *filename)
{
	int		fd;
	int   i;
	char	buffer[BUFF_SIZE_FILL];
	char	*tmp;

	fd = open(filename, O_RDONLY);
	tmp = NULL;
	if (fd == -1)
	{
		puts("readfile: Error: could not open file");
		exit(0);
  	}

	if (!(tmp = (char *)malloc(sizeof(char)*(26*6))))
    	return (NULL);
 	i = 0;
	while (read(fd, buffer, BUFF_SIZE_FILL) != 0)
    	*(tmp + i++) = *buffer;
  	close(fd);
	return (tmp);
}


void	trim_newline(char **src)
{
	int		i;
	int		j;
	int		k;
	char	tmp[20];

	i = 0;
	while (src[i])
	{
		j = 0;
		k = 0;
		while (src[i][j])
		{
			if (src[i][j] == '\n')
				++j;
			tmp[k] = src[i][j];
			++k;
			++j;
		}
		ft_strcpy(src[i], tmp);
		i++;
	}
}

void	rename_blocks(char **src)
{
	int		i;
	char	n;
	char	*tmp;

	i = 0;
	n = 'A';
	while (src[i])
	{
		tmp = src[i];
		while (*tmp)
		{
			if (*tmp == '#')
				*tmp = n;
			tmp++;
		}
		++n;
		++i;
	}
}


char	**load_input(char *input)
{
	/*
		+splits tetriminos
	*/
	int		i;
	int		j;
	int		k;
	char	**ret;

	if(!(ret = (char**)malloc(sizeof(char *) * has_newlines(input))))
		return (NULL);
	i = 0;
	k = 0;
	while (input[i])
	{
		j = 0;
		if(!(ret[k] = (char *)malloc(sizeof(char) * 21)))
			return (NULL);
		while(j < 20 && input[i] != '\0')
		{
			ret[k][j] = input[i];
			++j;
			++i;
		}
		ret[k][j] = '\0';
		++i;
		++k;
	}
	ret[has_newlines(input)] = '\0';
	return (ret);
}