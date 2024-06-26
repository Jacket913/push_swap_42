/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:30:53 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/26 11:05:12 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/* LIBRARIES */
# include "libft.h"

/* FUNCTIONS */
typedef struct	s_stack
{
	struct	s_stack	*next;
	struct	s_stack	*prev;
	int		value;
	int		index;
}				t_stack;

typedef struct s_move
{
	int		rotate;
}				t_move;

void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	push(t_stack **src, t_stack **dest);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
int		check_dup(t_stack *a);
int		check_sorted(t_stack *a);
int		stacksize(t_stack *stack);
void	sort_2(t_stack **a);
void	sort_3(t_stack **a);
void	start_sort(t_stack **a);
void	free_list(t_stack *x);
void	print(t_stack *x);
void	error_arg(void);
void	indexing(t_stack **a);
void	whichrotate(t_stack *x, t_move *m, int index);
void	cheaper_move(t_stack *a, t_stack *b, t_move *ma, t_move *mb);
void	rotatelist(t_stack **x, t_move *m, int which_list);
void	pre_sort(t_stack **a, t_stack **b);
void	move_from_cheapest(t_stack **a, t_stack **b);
#endif
