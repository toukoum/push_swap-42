/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:30:38 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:52:39 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../../libft_mandatory/includes/libft.h"

void	ft_reverse_str(char *result)
{
	int		len_result;
	int		i;
	int		j;
	char	temp;

	len_result = 0;
	i = 0;
	if (result[0] == '-')
		i++;
	while (result[len_result])
		len_result++;
	j = len_result - 1;
	while (i < j)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
		i++;
		j--;
	}
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
				|| base[j] == '+' || base[j] == '-' || base[i] <= ' '
				|| base[i] > 126 || base[j] <= ' ' || base[j] > 126)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_len_result(unsigned long long nbr, unsigned long long base_len)
{
	int	len_result;

	if (nbr == 0)
		return (1);
	len_result = 0;
	while (nbr)
	{
		nbr /= base_len;
		len_result++;
	}
	return (len_result);
}

char	*ft_putnbr_base(unsigned long long n, char *base)
{
	char				*result;
	int					i;
	unsigned long long	base_len;
	int					len_result;

	base_len = ft_strlen(base);
	if (n == 0)
		len_result = 1;
	else
		len_result = ft_len_result(n, base_len);
	result = malloc((len_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	if (n == 0)
		result[i++] = base[0];
	while (n)
	{
		result[i++] = base[n % base_len];
		n /= base_len;
	}
	result[i] = '\0';
	ft_reverse_str(result);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	unsigned long long	number;
	char				*result;

	if ((!ft_check_base(base_from) || !ft_check_base(base_to)))
		return (NULL);
	number = ft_atoi_base(nbr, base_from);
	result = ft_putnbr_base(number, base_to);
	free(nbr);
	return (result);
}
