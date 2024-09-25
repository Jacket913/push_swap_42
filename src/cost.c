/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:25:52 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/23 19:37:40 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotatelist(t_stack **x, t_move *move, int is_a)
{
	if (!move->up)
	{
		while (move->move--)
		{
			if (is_a)
				ra(x);
			else
				rb(x);
		}
	}
	else
	{
		while (move->move--)
		{
			if (is_a)
				rra(x);
			else
				rrb(x);
		}
	}
}

int	find_location(t_stack *a, int index, int *biggest)
{
	t_stack	*tmp;
	int		first_b;

	tmp = a;
	first_b = -1;
	while (a)
	{
		if (a->index > index && (first_b == -1 || first_b > a->index))
			first_b = a->index;
		a = a->next;
	}
	*biggest = 0;
	if (first_b == -1)
		*biggest = 1;
	if (*biggest == 0)
		return (first_b);
	first_b = tmp->index;
	while (tmp)
	{
		if (tmp->index > first_b)
			first_b = tmp->index;
		tmp = tmp->next;
	}
	return (first_b);
}

void	ra_or_rra(t_stack *x, t_move *dir_x, int index)
{
	t_move	tmp;

	dir_x->up = 0;
	dir_x->move = 0;
	tmp.up = 1;
	tmp.move = 1;
	tmp.biggest = dir_x->biggest;
	while (x->next)
	{
		if (x->index == index)
			break ;
		dir_x->move++;
		x = x->next;
	}
	while (x->next)
		x = x->next;
	while (x->prev)
	{
		if (x->index == index)
			break ;
		tmp.move++;
		x = x->prev;
	}
	if (dir_x->move > tmp.move)
		*dir_x = tmp;
}

void	cheapermove(t_stack *a, t_stack *b, t_move *dir_a, t_move *dir_b)
{
	t_stack	*tmp;
	t_move	lower;
	int		index;

	tmp = b;
	lower.move = -1;
	while (b)
	{
		ra_or_rra(tmp, dir_b, b->index);
		ra_or_rra(a, dir_a, find_location(a, b->index, &dir_a->biggest));
		if (lower.move == -1 || dir_b->move + dir_a->move < lower.move)
		{
			lower.move = dir_b->move + dir_a->move;
			index = b->index;
		}
		b = b->next;
	}
	ra_or_rra(tmp, dir_b, index);
	ra_or_rra(a, dir_a, find_location(a, index, &dir_a->biggest));
}
