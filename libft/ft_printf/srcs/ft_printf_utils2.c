/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:06:13 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:42 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

// a re checker par rapport a la width
void	ft_print_null(int *count, t_format *flags)
{
	if ((flags->point && flags->precision < 6) && flags->width < 6)
		return ;
	while (flags->width > 6 && !flags->minus)
		ft_print_space(count, flags);
	(*count) += write(1, "(null)", 6);
	while (flags->width > 6 && flags->minus)
		ft_print_space(count, flags);
}

void	ft_print_nill(int *count, t_format *flags)
{
	if ((flags->point && flags->precision < 5 && flags->width < 5))
		return ;
	while (flags->width > 5 && !flags->minus)
		ft_print_space(count, flags);
	(*count) += write(1, "(nil)", 5);
	while (flags->width > 5 && flags->minus)
		ft_print_space(count, flags);
}

void	zero_clc(t_format *flags, int *count)
{
	while (flags->width)
		ft_print_space(count, flags);
}

char	*ft_strcpy(char *dest, const char *src)
{
	char	*original_dest;

	original_dest = dest;
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (original_dest);
}

char	*ft_add_ox(char *s, char conv_letter)
{
	size_t	len_s;
	char	*result;

	len_s = ft_strlen(s);
	result = (char *)malloc(len_s + 3);
	if (!result)
		return (NULL);
	result[0] = '0';
	result[1] = conv_letter;
	ft_strcpy(result + 2, s);
	free(s);
	return (result);
}
