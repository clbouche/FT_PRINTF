/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:50:40 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/18 11:30:06 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		init_flags(t_flags flags)
{
	flags.minus = 0;
	flags.zero = 0;
	flags.precision = 0;
	flags.nb_pre = -1;
	flags.width = 0;
	flags.number = 0;
	return (flags);
}

int			ft_justify(t_flags flags, t_utils *utils)
{
	if (flags.number == 1 && (utils->len == 1 || utils->len == 0))
		ft_putchar_printf(' ', utils);
	else if (flags.zero == 1)
	{
		if (utils->c == 'd' && utils->str[0] == '-')
		{
			ft_putchar_printf('-', utils);
			utils->str++;
		}
		while (utils->len < flags.number)
		{
			ft_putchar_printf('0', utils);
			utils->len++;
		}
	}
	else if (flags.zero == 0)
	{
		while (utils->len < flags.number)
		{
			ft_putchar_printf(' ', utils);
			utils->len++;
		}
	}
	return (utils->rtn);
}

int			is_flags(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*' || ft_isdigit(c))
		return (1);
	return (0);
}

t_flags		make_width(t_flags flags, va_list arg)
{
	if (flags.precision)
	{
		flags.nb_pre = va_arg(arg, int);
		if (flags.nb_pre < 0)
		{
			flags.precision = 0;
			flags.nb_pre = -1;
		}
	}
	else if (flags.width < 1)
	{
		flags.width = va_arg(arg, int);
		if (flags.width < 0)
		{
			flags.width *= -1;
			flags.minus = 1;
		}
	}
	return (flags);
}

t_flags		check_flags(const char *fmt, int *i, t_flags flags, va_list arg)
{
	while (fmt[*i] && is_flags(fmt[*i]))
	{
		if (fmt[*i] == '0' && !ft_isdigit(fmt[*i - 1]))
		{
			if (!flags.precision || flags.width > 1)
				flags.zero = 1;
			if (flags.precision == 1)
				flags.zero = 0;
		}
		else if (fmt[*i] == '-')
			flags.minus = 1;
		else if (fmt[*i] == '.')
		{
			flags.precision = 1;
			flags.nb_pre = 0;
		}
		else if (ft_isdigit(fmt[*i]) && !flags.precision)
			flags.number = (flags.number * 10) + (fmt[*i] - '0');
		else if (fmt[*i] == '*')
			flags = make_width(flags, arg);
		else if (ft_isdigit(fmt[*i]) && flags.precision == 1)
			flags.nb_pre = (flags.nb_pre * 10) + (fmt[*i] - '0');
		++*i;
	}
	return (flags);
}
