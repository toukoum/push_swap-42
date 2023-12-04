/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:00:27 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:57:46 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*chaine;

	chaine = (char *)haystack;
	if (!needle[0])
		return (chaine);
	i = 0;
	while (i < len && chaine[i])
	{
		j = 0;
		if (chaine[i] == needle[j])
		{
			while (chaine[i] && needle[j] && chaine[i + j] == needle[j] && i
				+ j < len)
			{
				j++;
			}
			if (needle[j] == '\0')
				return (chaine + i);
		}
		i++;
	}
	return (NULL);
}
