/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_boost.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:33:52 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:54:32 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

size_t	ft_nlen2(unsigned long long n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_swap2(char *result, size_t len)
{
	size_t	i;
	char	temp;

	i = 0;
	while (i < len / 2)
	{
		temp = result[i];
		result[i] = result[len - i - 1];
		result[len - i - 1] = temp;
		i++;
	}
	return (result);
}

char	*ft_itoa_boost(unsigned long long n)
{
	char	*result;
	size_t	len;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	i = 0;
	len = ft_nlen2(n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n < 0)
	{
		result[len - 1] = '-';
		n *= -1;
	}
	while (n)
	{
		result[i++] = n % 10 + '0';
		n /= 10;
	}
	return (ft_swap2(result, len));
}
