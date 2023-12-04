/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:47:52 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/21 16:47:55 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	convert_c(t_format *flags, int *count)
{
	char	result;

	result = (char)va_arg(flags->args, int);
	while (flags->width > 1 && !flags->minus)
		ft_print_space(count, flags);
	write(1, &result, 1);
	(*count)++;
	while (flags->width > 1 && flags->minus)
		ft_print_space(count, flags);
}
