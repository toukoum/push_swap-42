/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 10:17:32 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:56:39 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*chaine1;
	unsigned char	*chaine2;
	size_t			i;

	chaine1 = (unsigned char *)s1;
	chaine2 = (unsigned char *)s2;
	i = 0;
	if (!n)
		return (0);
	while (i < n - 1 && chaine1[i] == chaine2[i])
	{
		i++;
	}
	return (chaine1[i] - chaine2[i]);
}
