/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:24:29 by botilia           #+#    #+#             */
/*   Updated: 2021/11/26 17:27:22 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_type(const char *format, va_list *ap, int j, int k)
{
	while (format[k])
	{
		if (format[k] == '%')
		{
			k++;
			if (format[k] == 'c')
				j += ft_work_with_char(va_arg(*ap, int));
			if (format[k] == 's')
				j += ft_work_with_str(va_arg(*ap, char *));
			if (format[k] == 'p')
				j += ft_work_with_pointer(va_arg(*ap, unsigned long));
			if ((format[k] == 'd') || (format[k] == 'i'))
				j += ft_work_with_di(va_arg(*ap, int));
			if (format[k] == 'u')
				j += ft_work_with_u(va_arg(*ap, unsigned int));
			if (format[k] == 'x' || format[k] == 'X')
				j += ft_work_with_x(va_arg(*ap, unsigned int), format[k]);
			if (format[k] == '%')
				j += write (1, "%", 1);
		}
		else
			j += write (1, &format[k], 1);
		k++;
	}
	return (j);
}

int	ft_work_with_char(char c)
{
	int	j;

	j = 0;
	j += (write(1, &c, 1));
	return (j);
}

int	ft_work_with_str(const char *str)
{
	char	*sec_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		str = "(null)";
	sec_str = ft_strdup(str);
	while (sec_str[i] != '\0')
	{
		j += write (1, &sec_str[i], 1);
		i++;
	}
	free(sec_str);
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		k;
	int		j;
	int		i;

	k = 0;
	j = 0;
	va_start(ap, format);
	i = find_type(format, &ap, j, k);
	va_end (ap);
	return (i);
}
