/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:21:00 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/13 11:14:54 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_list_instruct(t_instruct **linst, char *instruct, t_stack *a,
		t_stack *b)
{
	t_instruct	*node;

	node = NULL;
	node = ft_lstnew_instruct(instruct);
	if (!node)
		handle_error_instruct(linst, a, b);
	ft_lstadd_back_instruct(linst, node);
}

void	do_op(t_stack *a, t_stack *b, char *instruct)
{
	if (ft_strncmp(instruct, "rra", 3) == 0)
		rra_quiet(a);
	else if (ft_strncmp(instruct, "rrb", 3) == 0)
		rrb_quiet(a);
	else if (ft_strncmp(instruct, "rrr", 3) == 0)
		rrr_quiet(a, b);
	else if (ft_strncmp(instruct, "ra", 2) == 0)
		ra_quiet(a);
	else if (ft_strncmp(instruct, "rb", 2) == 0)
		rb_quiet(b);
	else if (ft_strncmp(instruct, "rr", 2) == 0)
		rr_quiet(a, b);
	else if (ft_strncmp(instruct, "pa", 2) == 0)
		pa_quiet(a, b);
	else if (ft_strncmp(instruct, "pb", 2) == 0)
		pb_quiet(a, b);
	else if (ft_strncmp(instruct, "sa", 2) == 0)
		sa_quiet(a);
	else if (ft_strncmp(instruct, "sb", 2) == 0)
		sb_quiet(b);
	else if (ft_strncmp(instruct, "ss", 2) == 0)
		ss_quiet(a, b);
}

void	apply_instruct(t_instruct **linst, t_stack *a, t_stack *b)
{
	t_instruct	*temp;

	temp = *linst;
	while (temp)
	{
		do_op(a, b, temp->instruct);
		temp = temp->next;
	}
	if (check_sort(a) && b->len == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear_instruct(linst, &clear_content);
	free_stack(a, b);
}

void	parse_instruct(t_stack *a, t_stack *b)
{
	t_instruct	*linst;
	char		*instruct;

	linst = NULL;
	instruct = get_next_line(0);
	while (instruct)
	{
		add_list_instruct(&linst, instruct, a, b);
		if (!is_valid_instruct(instruct))
			handle_error_instruct(&linst, a, b);
		instruct = get_next_line(0);
	}
	apply_instruct(&linst, a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = ft_parse(argc, argv);
	init_stack_b(stack_a, &stack_b);
	parse_instruct(stack_a, stack_b);
	return (0);
}
