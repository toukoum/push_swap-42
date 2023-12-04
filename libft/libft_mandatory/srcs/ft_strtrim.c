/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 19:09:53 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/01 12:57:53 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	in_sep(const char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && in_sep(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && in_sep(s1[end - 1], set))
		end--;
	result = (char *)malloc((end - start + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1 + start, end - start + 1);
	return (result);
}
