/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:33:53 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/09 12:54:45 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft_mandatory/includes/libft.h"
# include "stdlib.h"

typedef struct s_stack
{
	int	*tab;
	int	len;
}		t_stack;

// =========================== PARSING ===========================
void	delete_content(int content);
void	handle_error(t_list **lst_tab);
t_stack	*ft_parse(int argc, char **argv);
void	ft_find_disturb(char *arg, t_list **lst_tab);
int		find_dubble(t_list *lst_tab, int n);
void	ft_add_arg(t_list **lst_tab, char *arg);
// ===============================================================

// =========================== UTILS =============================
void	handle_error_stack(t_stack *stack_a, t_stack *stack_b);
void	init_stack_b(t_stack *stack_a, t_stack **stack_b);
void	free_stack(t_stack *stack_a, t_stack *stack_b);
int		check_sort(t_stack *stack_a);
int		check_r_sort(t_stack *stack_a);
// ===============================================================

// ======================== INSTRUCTIONS =========================
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
// ===============================================================

// ============================ SORT =============================
void	ft_sort_two(t_stack *stack_a);
void	ft_sort_three(t_stack *stack_a);
void	ft_sort_four(t_stack *stack_a, t_stack *stack_b);
void	ft_sort_five(t_stack *stack_a, t_stack *stack_b);
void	ft_radix_sort(t_stack *stack_a, t_stack *stack_b);

// ===============================================================

// ========================= SORT UTILS ==========================
int		find_min(t_stack *stack);
void	normalize(t_stack *a, t_stack *b);

// ===============================================================

#endif