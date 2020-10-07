/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 13:24:04 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/08 17:04:13 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			find_fw(char *flags, int i, int j, int neg)
{
	char	*field_width;
	int		fw;

	field_width = ft_memalloc(flaglen(flags));
	while (flags[i])
	{
		if (flags[i] == '.')
			return (0);
		neg = (flags[i] == '-') ? 1 : neg;
		if (flags[i] >= '1' && flags[i] <= '9')
		{
			while (flags[i] >= '0' && flags[i] <= '9')
				field_width[j++] = flags[i++];
			field_width[j] = '\0';
			fw = ft_atoi(field_width);
			free(field_width);
			fw = (neg) ? fw * -1 : fw;
			return (fw);
		}
		i++;
	}
	free(field_width);
	return (0);
}

char		*handle_fieldwidth(t_flags f, char *final, int i, int len)
{
	char	insert;
	char	*newstring;

	len = ft_strlen(final);
	newstring = NULL;
	insert = (f.zero && (f.precision == 0 || f.f != 0) && !f.minus) ? '0' : ' ';
	if (f.fw - len > 0 && f.fw > 0)
	{
		newstring = (char *)malloc(sizeof(char) * (f.fw - len + 1));
		while (len + i < f.fw)
			newstring[i++] = insert;
		newstring[i] = '\0';
		final = finaljoin(newstring, final);
	}
	if (f.fw < 0 && (f.fw * -1 - len > 0))
	{
		newstring = (char *)malloc(sizeof(char) * (-1 * f.fw - len + 1));
		while (len + i < f.fw * -1)
			newstring[i++] = insert;
		newstring[i] = '\0';
		final = finaljoin_reverse(final, newstring);
	}
	free(newstring);
	return (final);
}

char		*handle_stringwidth(t_flags f, char *final, int i, int len)
{
	char	insert;
	char	*newstring;

	len = ft_strlen(final);
	newstring = NULL;
	insert = (f.zero && (f.precision == 0 || f.f != 0) && !f.minus) ? '0' : ' ';
	if (f.fw - len > 0 && f.fw > 0)
	{
		newstring = (char *)malloc(sizeof(char) * (f.fw - len + 1));
		while (len + i < f.fw)
			newstring[i++] = insert;
		newstring[i] = '\0';
		final = ft_strjoin(newstring, final);
	}
	if (f.fw < 0 && (f.fw * -1 - len > 0))
	{
		newstring = (char *)malloc(sizeof(char) * (-1 * f.fw - len + 1));
		while (len + i < f.fw * -1)
			newstring[i++] = insert;
		newstring[i] = '\0';
		final = ft_strjoin(final, newstring);
	}
	free(newstring);
	return (final);
}

char		*handle_floatwidth(t_flags f, char *final, int i, int len)
{
	char	insert;
	char	*newstring;

	len = ft_strlen(final);
	newstring = NULL;
	insert = (f.zero && !f.minus) ? '0' : ' ';
	if (f.fw - len > 0 && f.fw > 0)
	{
		newstring = (char *)malloc(sizeof(char) * (f.fw - len + 1));
		while (len + i < f.fw)
			newstring[i++] = insert;
		newstring[i] = '\0';
		final = finaljoin(newstring, final);
	}
	if (f.fw < 0 && (f.fw * -1 - len > 0))
	{
		newstring = (char *)malloc(sizeof(char) * (-1 * f.fw - len + 1));
		while (len + i < f.fw * -1)
			newstring[i++] = insert;
		newstring[i] = '\0';
		final = finaljoin_reverse(final, newstring);
	}
	free(newstring);
	return (final);
}
