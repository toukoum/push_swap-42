/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 20:49:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:56:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tempsrc;
	unsigned char	*tempdst;

	if (!dest && !src)
		return (NULL);
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dest;
	if (tempdst >= (tempsrc + n) || (tempdst + n) <= (tempsrc) || ((tempdst
				+ n) >= tempsrc && (tempdst + n) <= (tempsrc + n)))
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			*(tempdst + n - 1) = *(tempsrc + n - 1);
			n--;
		}
	}
	return (dest);
}
