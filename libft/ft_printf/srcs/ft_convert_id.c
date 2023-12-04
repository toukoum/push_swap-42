/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:50:41 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:53:34 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	convert_id_minus(t_format *flags, int *count, char *result)
{
	int	len_result;
	int	total;

	len_result = ft_strlen(result);
	if (flags->point && !flags->precision && len_result == 1 && result[0] == 48)
		return (zero_clc(flags, count));
	total = (*count);
	if (result[0] == '-')
	{
		ft_putchar_count('-', count);
		result += 1;
		len_result--;
	}
	else if (flags->plus)
		ft_putchar_count('+', count);
	else if (flags->space)
		ft_putchar_count(' ', count);
	while (flags->precision > len_result)
		ft_print_zero_precision(count, flags);
	(*count) += write(1, result, len_result);
	total = (*count) - total;
	while (flags->width > total)
		ft_print_space(count, flags);
}

void	convert_id_zero(t_format *flags, int *count, char *result)
{
	int	len_result;
	int	total;

	len_result = ft_strlen(result);
	if (flags->point && !flags->precision && len_result == 1 && result[0] == 48)
		return (zero_clc(flags, count));
	total = len_result;
	if ((flags->plus || flags->space) && result[0] != '-')
		total++;
	if (result[0] == '-')
	{
		ft_putchar_count('-', count);
		result += 1;
		len_result--;
	}
	else if (flags->plus)
		ft_putchar_count('+', count);
	else if (flags->space)
		ft_putchar_count(' ', count);
	while (flags->width > total)
		ft_print_zero(count, flags);
	(*count) += write(1, result, len_result);
}

void	convert_id_normal(t_format *flags, int *count, char *result,
		int len_result)
{
	int	total;

	if (flags->point && !flags->precision && len_result == 1 && result[0] == 48)
		return (zero_clc(flags, count));
	total = len_result;
	if (result[0] == '-')
		len_result--;
	if ((flags->plus || flags->space) && result[0] != '-')
		total++;
	if ((flags->precision - len_result) > 0)
		total += flags->precision - len_result;
	while (flags->width > total)
		ft_print_space(count, flags);
	if (result[0] == '-')
	{
		ft_putchar_count('-', count);
		result += 1;
	}
	else if (flags->plus)
		ft_putchar_count('+', count);
	else if (flags->space)
		ft_putchar_count(' ', count);
	while (flags->precision > len_result)
		ft_print_zero_precision(count, flags);
	(*count) += write(1, result, len_result);
}

void	convert_id(t_format *flags, int *count)
{
	char	*result;
	int		len_result;

	result = ft_itoa(va_arg(flags->args, int));
	if (!result)
		return ;
	if (flags->minus)
		convert_id_minus(flags, count, result);
	else if (!flags->precision && flags->zero)
		convert_id_zero(flags, count, result);
	else
	{
		len_result = ft_strlen(result);
		convert_id_normal(flags, count, result, len_result);
	}
	free(result);
}
