/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 22:23:56 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/13 11:15:29 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_valid_instruct(char *instruct)
{
	size_t	len;

	len = ft_strlen(instruct);
	return ((len == 3 && (!ft_strncmp(instruct, "ra\n", 3)
				|| !ft_strncmp(instruct, "rb\n", 3) || !ft_strncmp(instruct,
					"rr\n", 3) || !ft_strncmp(instruct, "sa\n", 3)
				|| !ft_strncmp(instruct, "sb\n", 3) || !ft_strncmp(instruct,
					"ss\n", 3) || !ft_strncmp(instruct, "pb\n", 3)
				|| !ft_strncmp(instruct, "pa\n", 3))) || (len == 4
			&& (!ft_strncmp(instruct, "rra\n", 4) || !ft_strncmp(instruct,
					"rrb\n", 4) || !ft_strncmp(instruct, "rrr\n", 4))));
}

void	handle_error_instruct(t_instruct **linst, t_stack *a, t_stack *b)
{
	ft_lstclear_instruct(linst, &clear_content);
	free_stack(a, b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}
