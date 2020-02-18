/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 10:14:54 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/18 12:57:26 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			first_putchar(char c, t_utils *utils)
{
	if (c != '%')
	{
		write(1, &c, 1);
		utils->rtn++;
	}
	return (utils->rtn);
}

void		ft_putchar_printf(char c, t_utils *utils)
{
	write(1, &c, 1);
	utils->rtn++;
}

void		ft_putstr_printf(t_utils *utils)
{
	int i;

	i = 0;
	while (utils->str[i])
	{
		write(1, &utils->str[i], 1);
		i++;
		utils->rtn++;
	}
}

t_utils		*init_utils(void)
{
	t_utils *utils;

	if (!(utils = malloc(sizeof(t_utils))))
		return (0);
	utils->rtn = 0;
	utils->i = 0;
	utils->str = 0;
	utils->nb = 0;
	utils->len = 0;
	utils->c = 0;
	return (utils);
}

int			ft_printf(const char *fmt, ...)
{
	va_list		arg;
	t_utils		*utils;
	t_flags		flags;
	int			i;

	va_start(arg, fmt);
	utils = init_utils();
	i = 0;
	while (fmt[i])
	{
		utils->rtn = first_putchar(fmt[i], utils);
		if (fmt[i] == '%' && fmt[i + 1])
		{
			i++;
			flags = init_flags(flags);
			flags = check_flags(fmt, &i, flags, arg);
			utils->rtn = check_conv(fmt[i], utils, flags, arg);
		}
		i++;
	}
	free(utils);
	return (utils->rtn);
}
