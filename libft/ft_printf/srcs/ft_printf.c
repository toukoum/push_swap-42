/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:56:45 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:47 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

int	ft_printf(const char *format, ...)
{
	int			index_format;
	int			count;
	va_list		args;
	t_format	flags;
	char		*format2;

	format2 = (char *)format;
	va_start(args, format);
	flags = init_flags(&args);
	index_format = 0;
	count = 0;
	while (format[index_format])
	{
		if (format[index_format] == '%' && format[index_format + 1])
			ft_construct_param(&flags, format2, &count, &index_format);
		else
			ft_putchar_max(format2, &count, &index_format);
		reset_flags(&flags);
	}
	va_end(args);
	return (count);
}
