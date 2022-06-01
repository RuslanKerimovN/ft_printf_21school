/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_pointer_x.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 10:49:15 by botilia           #+#    #+#             */
/*   Updated: 2021/11/26 17:29:07 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_sixteen(char *str, unsigned long tmp, int divide, int i)
{
	while (tmp != 0)
	{
		if ((tmp % divide) < 10)
			str[i - 1] = (tmp % divide) + 48;
		else
			str[i - 1] = (tmp % divide) + 87;
		tmp /= divide;
		i--;
	}
	return (str);
}

char	*sixteen(unsigned long nmbr, int divide)
{
	unsigned long	tmp;
	int				i;
	char			*str;

	tmp = nmbr;
	i = 0;
	if (nmbr == 0)
		return (ft_strdup("0"));
	while (nmbr != 0)
	{
		nmbr /= divide;
		i++;
	}
	str = (char *)malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	str = ft_sixteen(str, tmp, divide, i);
	return (str);
}

int	ft_work_with_pointer(unsigned long p)
{
	char	*p2;
	int		j;
	int		k;

	j = 0;
	k = 0;
	j += write (1, "0x", 2);
	p2 = sixteen(p, 16);
	while (p2[k])
	{
		j += write (1, &p2[k], 1);
		k++;
	}
	free(p2);
	return (j);
}

char	*ft_str_TOUPPER(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_toupper(str[i]);
		i++;
	}
	return (str);
}

int	ft_work_with_x(unsigned long p, char c)
{
	char	*p2;
	int		j;
	int		k;

	j = 0;
	k = 0;
	p2 = sixteen(p, 16);
	if (c == 'X')
		p2 = ft_str_TOUPPER(p2);
	while (p2[k])
	{
		j += write (1, &p2[k], 1);
		k++;
	}
	free(p2);
	return (j);
}
