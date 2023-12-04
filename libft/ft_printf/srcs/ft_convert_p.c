/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:51:59 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:53:41 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	ft_print_width(t_format *flags, int *count, char *result)
{
	int	len_result;

	len_result = (int)ft_strlen(result);
	while (flags->width && flags->width > len_result && !flags->minus)
		ft_print_space(count, flags);
	(*count) += write(1, result, len_result);
	while (flags->width && flags->width > len_result && flags->minus)
		ft_print_space(count, flags);
}

void	convert_p(t_format *flags, int *count)
{
	char				*result;
	unsigned long long	b_result;

	b_result = va_arg(flags->args, unsigned long long);
	if (!b_result)
		return (ft_print_nill(count, flags));
	result = ft_itoa_boost(b_result);
	if (!result)
		return ;
	result = ft_convert_base(result, "0123456789", "0123456789abcdef");
	if (!result)
		return ;
	result = ft_add_ox(result, 'x');
	if (!result)
		return ;
	ft_print_width(flags, count, result);
	free(result);
}
