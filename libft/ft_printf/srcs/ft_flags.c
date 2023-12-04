/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:49:29 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:27 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

t_format	init_flags(va_list *args)
{
	t_format	flags;

	ft_bzero(&flags, sizeof(t_format));
	va_copy(flags.args, *args);
	return (flags);
}

void	reset_flags(t_format *flags)
{
	flags->hashtag = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->point = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->zero = 0;
}
