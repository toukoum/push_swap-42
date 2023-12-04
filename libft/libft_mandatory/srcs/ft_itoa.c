/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:54:53 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:55:58 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_nlen(int n)
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

char	*ft_swap(char *result, size_t len)
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

char	*ft_itoa(int n)
{
	char	*result;
	size_t	len;
	int		i;
	long	long_n;

	long_n = (long)n;
	if (long_n == 0)
		return (ft_strdup("0"));
	i = 0;
	len = ft_nlen(long_n);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (long_n < 0)
	{
		result[len - 1] = '-';
		long_n *= -1;
	}
	while (long_n)
	{
		result[i++] = long_n % 10 + '0';
		long_n /= 10;
	}
	return (ft_swap(result, len));
}
