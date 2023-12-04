/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:40:20 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:35 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	check_priority(t_format *flags)
{
	if (flags->minus && flags->zero)
		flags->zero = 0;
	if (flags->plus && flags->space)
		flags->space = 0;
}

void	first_flags(char *format, int *index_format, t_format *flags)
{
	while (format[*index_format] && ft_strchr("#+- 0", format[*index_format]))
	{
		if (format[*index_format] == '#')
			flags->hashtag = 1;
		else if (format[*index_format] == '+')
			flags->plus = 1;
		else if (format[*index_format] == '-')
			flags->minus = 1;
		else if (format[*index_format] == ' ')
			flags->space = 1;
		else
			flags->zero = 1;
		(*index_format)++;
	}
}

void	parse_width(char *format, int *index_format, t_format *flags)
{
	while (format[*index_format] && ft_isdigit(format[*index_format]))
	{
		flags->width = flags->width * 10 + format[*index_format] - 48;
		(*index_format)++;
	}
}

void	parse_precision(char *format, int *index_format, t_format *flags)
{
	if (format[*index_format] == '.')
	{
		flags->point = 1;
		(*index_format)++;
		while (format[*index_format] && ft_isdigit(format[*index_format]))
		{
			flags->precision = flags->precision * 10 + format[*index_format]
				- 48;
			(*index_format)++;
		}
	}
}

void	ft_construct_param(t_format *flags, char *format, int *count,
		int *index_format)
{
	(*index_format)++;
	if (format[*index_format] == '%')
		return (ft_putchar_max(format, count, index_format));
	first_flags(format, index_format, flags);
	parse_width(format, index_format, flags);
	parse_precision(format, index_format, flags);
	check_priority(flags);
	ft_convert(flags, format, count, index_format);
}
