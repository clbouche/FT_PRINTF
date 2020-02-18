/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:15:37 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/18 11:28:04 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct	s_flags
{
	int		minus;
	int		zero;
	int		precision;
	int		nb_pre;
	int		width;
	int		number;
}				t_flags;

typedef struct	s_utils
{
	int						rtn;
	int						len;
	int						i;
	char					c;
	char					*str;
	unsigned long long		nb;
}				t_utils;

typedef	int		(*t_tab)(t_utils*, t_flags, va_list);

void			ft_putchar_printf(char c, t_utils *utils);
void			ft_putstr_printf(t_utils *utils);
int				first_putchar(char c, t_utils *utils);
int				ft_printf(const char *fmt, ...);

int				check_conv(int fmt, t_utils *utils, t_flags flags, va_list arg);
int				form_final_conv(t_utils *utils, t_flags flags);

int				ft_justify(t_flags flags, t_utils *utils);
t_flags			init_flags(t_flags flags);
t_flags			check_flags(const char *fmt, int *i, t_flags flags,
				va_list arg);

int				form_char(t_utils *utils, t_flags flags, va_list arg);

int				form_string(t_utils *utils, t_flags flags, va_list arg);
int				str_precision(t_utils *utils, t_flags flags);

int				form_int(t_utils *utils, t_flags flags, va_list arg);
int				int_precision(t_utils *utils, t_flags flags);

int				form_address(t_utils *utils, t_flags flags, va_list arg);

int				form_unsigned(t_utils *utils, t_flags flags, va_list arg);

int				form_hexa(t_utils *utils, t_flags flags, va_list arg);
int				form_unsigned_hexa(t_utils *utils, t_flags flags, va_list arg);

int				form_percent(t_utils *utils, t_flags flags, va_list arg);

#endif
