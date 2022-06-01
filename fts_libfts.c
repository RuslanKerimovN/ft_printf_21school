/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_libfts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 10:46:20 by botilia           #+#    #+#             */
/*   Updated: 2021/11/26 17:29:10 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*s2;
	int		j;

	j = 0;
	i = ft_strlen(s1);
	s2 = (char *)malloc(i + 1 * sizeof(char));
	if (!s2)
		return (NULL);
	while (s1[j] != '\0')
	{
		s2[j] = s1[j];
		j++;
	}
	s2[j] = '\0';
	return (s2);
}

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	else
		return (c);
}

int	fnsize(int n)
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

char	*ft_itoa(int n)
{
	int		i;
	long	j;
	char	*str;

	i = fnsize(n);
	j = n;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (j < 0)
	{
		j = j * (-1);
		str[0] = '-';
	}
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
