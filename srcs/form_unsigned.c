/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:31:25 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/17 15:53:19 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		form_unsigned(t_utils *utils, t_flags flags, va_list arg)
{
	utils->c = 'd';
	utils->nb = va_arg(arg, unsigned int);
	utils->str = ft_itoa_base(utils->nb, "0123456789");
	utils->len = ft_strlen(utils->str);
	if (flags.precision == 1 && flags.nb_pre == 0 && utils->str[0] == '0')
		ft_bzero(utils->str, utils->len);
	if (flags.precision == 1)
		utils->rtn = int_precision(utils, flags);
	utils->rtn = form_final_conv(utils, flags);
	return (utils->rtn);
}
