/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:26:29 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/26 11:15:36 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	indexing(t_stack **a)
{
	t_stack	*lowest;
	t_stack	*tmp;
	int		i;

	i = 1;
	while (i <= stacksize(*a))
	{
		tmp = *a;
		lowest = *a;
		while (lowest->index)
			lowest = lowest->next;
		while (tmp)
		{
			if (lowest->value > tmp->value && !tmp->index)
				lowest = tmp;
			tmp = tmp->next;
		}
		lowest->index = i;
		i++;
	}
}

void	rotatelist(t_stack **x, t_move *m, int which_list)
{
	if (m->rotate > 0)
	{
		while (m->rotate-- > 0)
		{
			if (which_list == 0)
				ra(x);
			else
				rb(x);
		}
	}
	else
	{
		while (m->rotate++ < 0)
		{
			if (which_list == 0)
				rra(x);
			else
				rrb(x);
		}
	}
}

void	pre_sort(t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	indexing(a);
	start_sort(a);
	if (stacksize(*a) > 3)
	{
		while (stacksize(*a) - i > 3 && i < stacksize(*a) / 2)
		{
			if ((*a)->index < stacksize(*a) / 2)
			{
				i++;
				pb(a, b);
			}
			else
				ra(a);
		}
		while (++i <= stacksize(*a) - 3)
			pb(a, b);
		sort_3(a);
	}
}

void	move_from_cheapest(t_stack **a, t_stack **b)
{
	t_move	move_a;
	t_move	move_b;

	while (*b)
	{
		cheaper_move(*a, *b, &move_a, &move_b);
		rotatelist(a, &move_a, 0);
		rotatelist(b, &move_b, 1);
		pa(a, b);
	}
}
