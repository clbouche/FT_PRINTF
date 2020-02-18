/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbouche <clbouche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:30:45 by clbouche          #+#    #+#             */
/*   Updated: 2020/02/17 18:54:48 by clbouche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_justify(t_utils *utils, t_flags flags)
{
	int i;

	i = 0;
	utils->len = flags.nb_pre;
	ft_justify(flags, utils);
	flags.number = 0;
	while (i < flags.nb_pre)
	{
		write(1, &utils->str[i], 1);
		i++;
		utils->rtn++;
	}
	utils->str = "";
	return (utils->rtn);
}

int		write_pre(t_utils *utils, t_flags flags)
{
	int i;

	i = 0;
	if (!flags.number || flags.minus == 1)
	{
		while (i < flags.nb_pre)
		{
			write(1, &utils->str[i], 1);
			i++;
			utils->rtn++;
		}
		utils->len = i;
		utils->str = "";
	}
	else if (flags.number > 0)
		utils->rtn = write_justify(utils, flags);
	return (utils->rtn);
}

int		str_precision(t_utils *utils, t_flags flags)
{
	int i;

	i = 0;
	if (utils->len > flags.nb_pre)
		utils->rtn = write_pre(utils, flags);
	else if (utils->len < flags.nb_pre)
	{
		while (utils->str[i])
		{
			write(1, &utils->str[i], 1);
			i++;
			utils->rtn++;
		}
		utils->str = "";
	}
	return (utils->rtn);
}

int		form_string(t_utils *utils, t_flags flags, va_list arg)
{
	utils->c = 's';
	utils->str = va_arg(arg, char *);
	if (utils->str == NULL)
		utils->str = "(null)";
	utils->len = ft_strlen(utils->str);
	if (flags.precision == 1)
		utils->rtn = str_precision(utils, flags);
	utils->rtn = form_final_conv(utils, flags);
	return (utils->rtn);
}
