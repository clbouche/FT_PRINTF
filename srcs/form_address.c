/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_address.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:31:03 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/17 13:52:06 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		add_minus(t_utils *utils, t_flags flags)
{
	if (flags.minus == 1)
	{
		ft_putchar_printf('0', utils);
		ft_putchar_printf('x', utils);
		ft_putstr_printf(utils);
		utils->len += 2;
		ft_justify(flags, utils);
	}
	else if (flags.minus == 0)
	{
		utils->len += 2;
		utils->rtn = ft_justify(flags, utils);
		ft_putchar_printf('0', utils);
		ft_putchar_printf('x', utils);
		ft_putstr_printf(utils);
	}
	return (utils->rtn);
}

int		form_address(t_utils *utils, t_flags flags, va_list arg)
{
	utils->nb = va_arg(arg, unsigned long long);
	if (!utils->nb)
		utils->str = ft_strdup("0");
	else
		utils->str = ft_itoa_base(utils->nb, "0123456789abcdef");
	utils->len = ft_strlen(utils->str);
	utils->rtn = add_minus(utils, flags);
	return (utils->rtn);
}
