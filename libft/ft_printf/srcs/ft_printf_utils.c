/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:48:29 by rgiraud           #+#    #+#             */
/*   Updated: 2023/11/21 16:47:31 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putchar_max(char *format, int *count, int *index_format)
{
	write(1, &(format[*index_format]), 1);
	(*count)++;
	(*index_format)++;
}

void	ft_print_space(int *count, t_format *flags)
{
	write(1, " ", 1);
	(*count)++;
	flags->width--;
}

void	ft_print_zero(int *count, t_format *flags)
{
	write(1, "0", 1);
	(*count)++;
	flags->width--;
}

void	ft_print_zero_precision(int *count, t_format *flags)
{
	write(1, "0", 1);
	(*count)++;
	flags->precision--;
}

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}
