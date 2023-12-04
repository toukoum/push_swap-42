/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:56:17 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:57:49 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*temp;

	temp = (char *)s;
	i = ft_strlen(temp);
	temp += i;
	while (i >= 0)
	{
		if (*temp == (char)c)
			return (temp);
		temp--;
		i--;
	}
	return (NULL);
}
