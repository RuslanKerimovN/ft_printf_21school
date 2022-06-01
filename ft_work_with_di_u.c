/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_with_di_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:56:26 by botilia           #+#    #+#             */
/*   Updated: 2021/11/26 17:27:40 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_work_with_di(int p)
{
	char	*str;
	int		j;
	int		k;

	j = 0;
	k = 0;
	str = ft_itoa(p);
	while (str[k])
	{
		j += write (1, &str[k], 1);
		k++;
	}
	free(str);
	return (j);
}

int	UfnsizeU(unsigned int n)
{
	int	sizemol;

	if (n > 0)
		sizemol = 0;
	else
		sizemol = 1;
	while (n)
	{
		n /= 10;
		sizemol++;
	}
	return (sizemol);
}

char	*Uft_itoaU(unsigned int n)
{
	int		i;
	long	j;
	char	*str;

	i = UfnsizeU(n);
	j = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (j == 0)
		str[0] = '0';
	str[i] = '\0';
	while (j)
	{
		str[i - 1] = ((j % 10) + 48);
		j /= 10;
		i--;
	}
	return (str);
}

int	ft_work_with_u(unsigned int p)
{
	char	*str;
	int		j;
	int		k;

	j = 0;
	k = 0;
	str = Uft_itoaU(p);
	while (str[k])
	{
		j += write (1, &str[k], 1);
		k++;
	}
	free(str);
	return (j);
}
