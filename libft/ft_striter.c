/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <wdaher-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 12:36:29 by svachere          #+#    #+#             */
/*   Updated: 2014/04/25 17:06:46 by svachere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		while (s[i])
		{
			(*f)(&s[i]);
			++i;
		}
	}
}