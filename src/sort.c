/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:33 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/23 19:37:40 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	size_t	size;
	int		min;
	t_stack	*highest;
	t_stack	*nbr;

	size = stack_size(a);
	while (--size)
	{
		min = -2147483648;
		highest = NULL;
		nbr = a;
		while (nbr)
		{
			if (min < nbr->value && !nbr->index)
			{
				min = nbr->value;
				highest = nbr;
			}
			nbr = nbr->next;
		}
		highest->index = size;
	}
}

void	pre_sort(t_stack **a, t_stack **b)
{
	size_t	size;
	size_t	i;

	i = 0;
	size = stack_size(*a);
	assign_index(*a);
	start_sort(a);
	if (size > 3)
	{
		while (size - i > 3 && i < size / 2)
		{
			if ((*a)->index < (int)size / 2)
			{
				i++;
				pb(a, b);
			}
			else
				ra(a);
		}
		while (++i <= size - 3)
			pb(a, b);
		sort_three(a);
	}
}

void	cost_and_sort(t_stack **a, t_stack **b)
{
	t_move	dir_a;
	t_move	dir_b;

	while (*b)
	{
		dir_a.biggest = 0;
		dir_b.biggest = 0;
		cheapermove(*a, *b, &dir_a, &dir_b);
		rotatelist(a, &dir_a, 1);
		rotatelist(b, &dir_b, 0);
		pa(a, b);
		if (dir_a.biggest)
			sa(a);
	}
}
