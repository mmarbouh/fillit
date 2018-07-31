/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaher-a <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:12:52 by wdaher-a          #+#    #+#             */
/*   Updated: 2018/07/02 22:14:42 by wdaher-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*res;
	int		neg;
	int		i;
	int		n_len;

	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		neg = 1;
		n = -1 * n;
	}
	n_len = floor(log10(abs(n))) + 3;
	if (n_len < 0)
		n_len = 3;
	if (!(res = (char *)malloc(sizeof(char) * n_len)))
		return (NULL);
	if (!neg)
		i = n_len - 3;
	else
	{
		i = n_len - 2;
		res[0] = '-';
	}
	while (i > -1)
	{
		if (res[i] != '-')
			res[i] += '0'+ n % 10;
		n = n / 10;
		--i;
	}
	res[n_len - 1] = '\0';
	return (res);
}
/*
   int		main()
   {
   char *i1 = ft_itoa(-623);
   char *i2 = ft_itoa(156);
   char *i3 = ft_itoa(-0);
   char *i4 = ft_itoa(1585390713);

   printf("ft_itoa(-623) = %s\n",i1);
   printf("ft_itoa(156) = %s\n",i2);
   printf("ft_itoa(-0) = %s\n",i3);
   printf("ft_itoa(1585390713) = %s\n",i4);


   return 0;
   }


int		main()
{
	char *i1 = ft_itoa(-1234);

	if (strcmp(i1, "-1234"))
		puts("TEST_FAILED");
	else
		puts("TEST_SUCCESS");
	return (0);
}
*/

