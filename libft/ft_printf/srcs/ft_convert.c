/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:42:35 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:22 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	ft_convert(t_format *flags, char *format, int *count, int *index_format)
{
	char	*conversion_letter;
	char	*i_conv;

	conversion_letter = "cspdiuxX";
	i_conv = ft_strchr(conversion_letter, format[*index_format]);
	if (!i_conv)
		return ;
	else if (*i_conv == 'c')
		convert_c(flags, count);
	else if (*i_conv == 's')
		convert_s(flags, count);
	else if (*i_conv == 'd' || *i_conv == 'i')
		convert_id(flags, count);
	else if (*i_conv == 'p')
		convert_p(flags, count);
	else if (*i_conv == 'u')
		convert_u(flags, count);
	else if (*i_conv == 'x' || *i_conv == 'X')
		convert_x(flags, count, *i_conv);
	(*index_format)++;
}
