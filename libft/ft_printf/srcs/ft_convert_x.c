/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:32:51 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:19 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	convert_x_minus(t_format *flags, int *count, char *result,
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

void	convert_x_zero(t_format *flags, int *count, char *result,
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

void	convert_x_normal(t_format *flags, int *count, char *result,
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

void	convert_x(t_format *flags, int *count, char conv_letter)
{
	char	*result;
	int		len_result;

	result = ft_itoa_boost(va_arg(flags->args, unsigned int));
	if (!result)
		return ;
	if (conv_letter == 'x')
		result = ft_convert_base(result, "0123456789", "0123456789abcdef");
	else
		result = ft_convert_base(result, "0123456789", "0123456789ABCDEF");
	if (!result)
		return ;
	if (flags->hashtag && result[0] != '0')
		result = ft_add_ox(result, conv_letter);
	if (!result)
		return ;
	len_result = ft_strlen(result);
	if (flags->minus)
		convert_x_minus(flags, count, result, len_result);
	else if (!flags->precision && flags->zero)
		convert_x_zero(flags, count, result, len_result);
	else
		convert_x_normal(flags, count, result, len_result);
	free(result);
}
