/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 11:50:53 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/18 11:30:44 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		form_final_conv(t_utils *utils, t_flags flags)
{
	if (flags.minus == 1 && (flags.number > 0 || flags.width > 1))
	{
		flags.zero = 0;
		ft_putstr_printf(utils);
		utils->str = "";
		ft_justify(flags, utils);
	}
	if (flags.minus == 0 && flags.number > 1)
	{
		if (utils->c == 'd' && (!flags.precision || flags.nb_pre == 0))
			ft_justify(flags, utils);
		else if (utils->c == 's')
			ft_justify(flags, utils);
	}
	if (flags.width > 0)
	{
		flags.number = flags.width;
		ft_justify(flags, utils);
		ft_putstr_printf(utils);
	}
	else
		ft_putstr_printf(utils);
	return (utils->rtn);
}

int		unknown_conv(t_utils *utils, t_flags flags, va_list arg)
{
	(void)utils;
	(void)flags;
	(void)arg;
	return (0);
}

int		(*g_tab[256])(t_utils*, t_flags, va_list);

void	init_tab(t_tab *tab)
{
	int i;

	i = 0;
	while (i < 256)
	{
		tab[i] = &unknown_conv;
		i++;
	}
	tab['c'] = form_char;
	tab['s'] = form_string;
	tab['d'] = form_int;
	tab['i'] = form_int;
	tab['p'] = form_address;
	tab['u'] = form_unsigned;
	tab['x'] = form_hexa;
	tab['X'] = form_unsigned_hexa;
	tab['%'] = form_percent;
}

int		check_conv(int fmt, t_utils *utils, t_flags flags, va_list arg)
{
	t_tab tab[256];

	init_tab(tab);
	utils->rtn = tab[fmt](utils, flags, arg);
	return (utils->rtn);
}
