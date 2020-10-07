/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 14:24:37 by okoponen          #+#    #+#             */
/*   Updated: 2020/09/02 15:06:59 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

int			insert_percent(const char *str)
{
	t_flags		f;
	char		*flags;
	char		*final;
	int			len;

	final = malloc(sizeof(char) * 2);
	final[0] = '%';
	final[1] = '\0';
	flags = ft_strsub(str, 0, flaglen(str));
	f = check_flags(flags, 0);
	f.fw = find_fw(flags, 0, 0, 0);
	final = handle_fieldwidth(f, final, 0, 0);
	ft_putstr(final);
	free(flags);
	len = ft_strlen(final);
	free(final);
	return (len);
}
