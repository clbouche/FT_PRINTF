/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:30:18 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/17 17:32:33 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_precision(t_utils *utils, t_flags flags)
{
	flags.zero = 0;
	if (utils->str[0] == '-')
	{
		ft_putchar_printf('-', utils);
		utils->str++;
		utils->len--;
		flags.number -= 1;
	}
	if (flags.nb_pre != 0)
	{
		if (utils->len > flags.nb_pre)
			flags.nb_pre = utils->len;
		while (flags.number > flags.nb_pre)
		{
			if (flags.minus == 0 && flags.zero == 0)
				ft_putchar_printf(' ', utils);
			flags.number--;
		}
		while (utils->len < flags.nb_pre)
		{
			ft_putchar_printf('0', utils);
			utils->len++;
		}
	}
	return (utils->rtn);
}

int		form_int(t_utils *utils, t_flags flags, va_list arg)
{
	utils->c = 'd';
	utils->nb = va_arg(arg, int);
	utils->str = ft_itoa(utils->nb);
	utils->len = ft_strlen(utils->str);
	if (flags.precision == 1 && flags.nb_pre == 0 && utils->str[0] == '0')
	{
		ft_bzero(utils->str, utils->len);
		utils->len--;
	}
	if (flags.precision == 1)
		utils->rtn = int_precision(utils, flags);
	utils->rtn = form_final_conv(utils, flags);
	return (utils->rtn);
}
