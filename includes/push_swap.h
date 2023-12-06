/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgiraud <rgiraud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 18:33:53 by rgiraud           #+#    #+#             */
/*   Updated: 2023/12/06 12:50:37 by rgiraud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft_mandatory/includes/libft.h"

typedef struct s_parse_list
{
	int			*tab;
	int			len;
}				t_parse_list;

// =========================== PARSING ===========================
void			delete_content(int content);
void			handle_error(t_list **lst_tab);
t_parse_list	*ft_parse(int argc, char **argv);
void			ft_find_disturb(char *arg, t_list **lst_tab);
int				find_dubble(t_list *lst_tab, int n);
void			ft_add_arg(t_list **lst_tab, char *arg);

// ===============================================================

#endif