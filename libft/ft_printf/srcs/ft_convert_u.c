/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:54:06 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:53:48 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	convert_u_minus(t_format *flags, int *count, char *result,
		int len_result)
{
	int	total;

	if (flags->point && !flags->precision && len_result == 1 && result[0] == 48)
		return (zero_clc(flags, count));
	total = (*count);
	while (flags->precision > len_result)
		ft_print_zero_precision(count, flags);
	(*count) += write(1, result, len_result);
	total = (*count) - total;
	while (flags->width > total)
		ft_print_space(count, flags);
}

void	convert_u_zero(t_format *flags, int *count, char *result,
		int len_result)
{
	int	total;

	if (flags->point && !flags->precision && len_result == 1 && result[0] == 48)
		return (zero_clc(flags, count));
	total = len_result;
	if ((flags->plus || flags->space) && result[0] != '-')
		total++;
	while (flags->width > total)
		ft_print_zero(count, flags);
	(*count) += write(1, result, len_result);
}

void	convert_u_normal(t_format *flags, int *count, char *result,
		int len_result)
{
	int	total;

	if (flags->point && !flags->precision && len_result == 1 && result[0] == 48)
		return (zero_clc(flags, count));
	total = len_result;
	if ((flags->precision - len_result) > 0)
		total += flags->precision - len_result;
	while (flags->width > total)
		ft_print_space(count, flags);
	while (flags->precision > len_result)
		ft_print_zero_precision(count, flags);
	(*count) += write(1, result, len_result);
}

void	convert_u(t_format *flags, int *count)
{
	char	*result;
	int		len_result;

	result = ft_itoa_boost(va_arg(flags->args, unsigned int));
	if (!result)
		return ;
	len_result = ft_strlen(result);
	if (flags->minus)
		convert_u_minus(flags, count, result, len_result);
	else if (!flags->point && flags->zero)
		convert_u_zero(flags, count, result, len_result);
	else
		convert_u_normal(flags, count, result, len_result);
	free(result);
}
