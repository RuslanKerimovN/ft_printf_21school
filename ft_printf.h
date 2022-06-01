/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: botilia <botilia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:28:19 by botilia           #+#    #+#             */
/*   Updated: 2021/11/26 17:28:16 by botilia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stddef.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
int		ft_toupper(int c);
int		fnsize(int n);
char	*ft_itoa(int n);
int		ft_work_with_char(char c);
int		ft_work_with_str(const char *str);
int		ft_work_with_pointer(unsigned long p);
int		ft_work_with_di(int p);
int		ft_work_with_u(unsigned int p);
int		ft_work_with_x(unsigned long p, char c);
char	*ft_sixteen(char *str, unsigned long tmp, int divide, int i);
char	*sixteen(unsigned long nmbr, int divide);
int		ft_printf(const char *format, ...);

#endif