/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:46:56 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 16:21:06 by gmoulin          ###   ########.fr       */
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

// checks.c
int			check_dup(t_stack *a);
int			check_sorted(t_stack *a);
int			check_arg(char *av, t_stack **a);
void		error_arg(void);

// cost.c
void		rotatelist(t_stack **x, t_move *dir, int is_a);
int			find_location(t_stack *a, int index, int *biggest);
void		ra_or_rra(t_stack *x, t_move *dir_x, int index);
void		cheapermove(t_stack *a, t_stack *b, t_move *dir_a, t_move *dir_b);

// push.c
static void	push(t_stack **a, t_stack **b);
void		pa(t_stack **a, t_stack **b);
void		pb(t_stack **a, t_stack **b);

// rotate.c
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);

// rrotate.c
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);

// sort.c
void		assign_index(t_stack *a);
void		cost_and_sort(t_stack **a, t_stack **b);
void		sort_in_position(t_stack **a);

// start_sort.c
void		sort_two(t_stack **a);
void		sort_three(t_stack	**a);
void		start_sort(t_stack **a);
void		pre_sort(t_stack **a, t_stack **b);

// swap.c
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);

// utils.c
void		free_list(t_stack *x);
int			stack_size(t_stack *a);
t_stack		*dlstlast(t_stack *lst);
void		dlstadd_front(t_stack **lst, t_stack *new);
void		print_stack(t_stack *a);

#endif
