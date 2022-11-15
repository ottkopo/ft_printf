/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okoponen <ottkopo@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 15:35:51 by okoponen          #+#    #+#             */
/*   Updated: 2022/07/07 16:25:44 by okoponen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <limits.h>

# define DIGITS_UPPER "0123456789ABCDEF"
# define DIGITS_LOWER "0123456789abcdef"

typedef struct s_flags
{
	char			*s;
	int				c;
	intmax_t		d;
	uintmax_t		p;
	long long		o;
	uintmax_t		u;
	uintmax_t		x;
	double			f;
	long double		cap_lf;
	int				hash;
	int				zero;
	int				plus;
	int				minus;
	int				space;
	int				hh;
	int				h;
	int				l;
	int				ll;
	int				cap_l;
	int				dot;
	int				isnegative;
	intmax_t		original_final;
	int				fw;
	int				precision;
	int				oglen;
}					t_flags;

int					ft_printf(const char *str, ...);
int					flaglen(const char *str);
void				initialize_flags(t_flags *f);
t_flags				check_flags(char *flags, int i);
int					insert_int(const char *str, va_list ap);
int					handle_variable(const char *str, va_list ap, int i);
int					ft_printf(const char *str, ...);
int					find_fw(char *flags, int i, int j, int neg);
char				*handle_fieldwidth(t_flags f, char *final, int i, int len);
char				*handle_stringwidth(t_flags f, char *final, int i, int len);
char				*handle_floatwidth(t_flags f, char *final, int i, int len);
int					find_precision(char *flags, t_flags *f, int i, int j);
char				*handle_precision(char *final, t_flags f);
intmax_t			cast_number(t_flags f, va_list ap);
uintmax_t			cast_unsigned_number(t_flags f, va_list ap);
char				*imaxtoa_base(intmax_t n, int base);
char				*uimaxtoa_base(uintmax_t n, int base);
char				*uimaxtoa_base_lower(uintmax_t n, int base);
int					insert_char(const char *str, va_list ap);
int					insert_string(const char *str, va_list ap);
char				*handle_stringprecision(t_flags f, char *final);
int					insert_pointer(const char *str, va_list ap);
int					insert_percent(const char *str);
int					insert_hexadecimal(const char *str, va_list ap, \
					char capital);
int					insert_unsigned_int(const char *str, va_list ap);
int					insert_octal(const char *str, va_list ap);
char				*ft_ftoa(long double n, int precision, t_flags *f);
int					insert_float(const char *str, va_list ap);
char				*cast_float(t_flags *f, va_list ap);
char				*finaljoin(char *str, char *final);
char				*finaljoin_reverse(char *final, char *str);
int					free_and_return_zero(char *freethis);

#endif
