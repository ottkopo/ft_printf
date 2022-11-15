/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 09:49:34 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/04 13:21:53 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	handle_variable(const char *str, va_list ap, int i)
{
	while (str[i] && str[i] != 'd' && str[i] != 'i' && str[i] != '%' && \
		str[i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != \
		'o' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' && \
		str[i] != 'f')
		i++;
	if (str[i] == 'd' || str[i] == 'i')
		return (insert_int(str, ap));
	if (str[i] == 'c')
		return (insert_char(str, ap));
	if (str[i] == 's')
		return (insert_string(str, ap));
	if (str[i] == 'p')
		return (insert_pointer(str, ap));
	if (str[i] == 'o')
		return (insert_octal(str, ap));
	if (str[i] == 'u')
		return (insert_unsigned_int(str, ap));
	if (str[i] == 'x' || str[i] == 'X')
		return (insert_hexadecimal(str, ap, str[i]));
	if (str[i] == 'f')
		return (insert_float(str, ap));
	else if (str[i] == '%')
		return (insert_percent(str));
	return (0);
}

static int	writechar(char c)
{
	ft_putchar(c);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += handle_variable(&str[++i], ap, 0);
			while (str[i] && str[i] != 'd' && str[i] != 'i' && str[i] != '%' && \
				str[i] != 'c' && str[i] != 's' && str[i] != 'p' && str[i] != \
				'o' && str[i] != 'u' && str[i] != 'x' && str[i] != 'X' && \
				str[i] != 'f')
				i++;
			if (str[i])
				i++;
		}
		if (str[i] && str[i] != '%')
			count += writechar(str[i++]);
	}
	va_end(ap);
	return (count);
}
