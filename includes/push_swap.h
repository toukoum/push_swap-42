/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:33:53 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/12 16:21:55 by rgiraud          ###   ########.fr       */
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

typedef struct s_max_value
{
	int	min;
	int	max_first;
	int	max_second;
	int	max_third;
	int	max_fourth;
	int	max_fifth;
	int	median;
	int	*copy_tab;
	int	len;
}		t_max_value;

typedef struct s_best_moves
{
	int	nrb;
	int	nrrb;
	int	nra;
	int	nrra;
	int	nrr;
	int	nrrr;
	int	tt;
}		t_best_moves;

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
void	handle_big_error(t_stack *a, t_stack *b, t_max_value *mv,
			t_best_moves *bm);
void	init_stack_b(t_stack *stack_a, t_stack **stack_b);
void	free_stack(t_stack *stack_a, t_stack *stack_b);
int		check_sort(t_stack *stack_a);
int		check_r_sort(t_stack *stack_a);
void	calculate_best_moves(t_stack *a, t_stack *b, t_best_moves *bm,
			t_max_value *mv);
void	init_best_moves(t_best_moves *bm);
int		next_x(int x, t_stack *a);

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
void	opti_sort(t_stack *a, t_stack *b);
void	quick_sort(int *tab, int start, int end);
void	apply_best_moves(t_stack *a, t_stack *b, t_best_moves *bm);

// ===============================================================

// ========================= SORT UTILS ==========================
int		find_min(t_stack *stack);
int		is_max_value(int x, t_max_value *mv);
void	ft_copy_best_move(t_best_moves *bm, t_best_moves *bm_temp);

// ===============================================================

#endif