/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:29:48 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:56:42 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tempsrc;
	unsigned char	*tempdst;

	i = 0;
	if (!dest && !src)
		return (NULL);
	tempsrc = (unsigned char *)src;
	tempdst = (unsigned char *)dest;
	while (i++ < n)
	{
		*tempdst = *tempsrc;
		tempdst++;
		tempsrc++;
	}
	return (dest);
}
