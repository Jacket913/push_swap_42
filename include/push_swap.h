/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:56 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/23 19:37:40 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_move
{
	int	up;
	int	move;
	int	biggest;
}	t_move;

// Moves
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	dlstadd_front(t_stack **lst, t_stack *new);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		check_dup(t_stack *a);
t_stack	*dlstlast(t_stack *lst);

// Sort
void	sort_two(t_stack **a);
void	sort_three(t_stack	**a);
void	pre_sort(t_stack **a, t_stack **b);
void	assign_index(t_stack *a);
void	start_sort(t_stack **a);
void	cost_and_sort(t_stack **a, t_stack **b);

// Cost
void	cheapermove(t_stack *a, t_stack *b, t_move *dir_a, t_move *dir_b);
void	ra_or_rra(t_stack *x, t_move *dir_x, int index);
int		find_location(t_stack *a, int index, int *biggest);
void	rotatelist(t_stack **x, t_move *dir, int is_a);

// Error_And_Check
void	error_arg(void);
int		check_sorted(t_stack *a);
void	free_list(t_stack *x);
int		check_arg(char *av, t_stack **a);
int		stack_size(t_stack *a);
void	print_stack(t_stack *a);

#endif
