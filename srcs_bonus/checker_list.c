/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 21:05:29 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/13 10:20:30 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_instruct	*ft_lstnew_instruct(char *content)
{
	t_instruct	*result;

	result = (t_instruct *)malloc(sizeof(t_instruct));
	if (!result)
		return (NULL);
	result->instruct = content;
	result->next = NULL;
	return (result);
}

void	clear_content(char *content)
{
	free(content);
}

void	ft_lstadd_back_instruct(t_instruct **lst, t_instruct *new)
{
	t_instruct	*last;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	last = *lst;
	while (last->next)
		last = last->next;
	last->next = new;
}

void	ft_lstclear_instruct(t_instruct **lst, void (*del)(char *))
{
	t_instruct	*current;
	t_instruct	*next_node;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current)
	{
		next_node = current->next;
		del(current->instruct);
		free(current);
		current = next_node;
	}
	*lst = NULL;
}
