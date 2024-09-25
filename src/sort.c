/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:33 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 16:16:10 by gmoulin          ###   ########.fr       */
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

void	sort_in_position(t_stack **a)
{
	t_stack		*tmp;
	size_t		smallest_pos;
	size_t		len;

	tmp = *a;
	len = 0;
	smallest_pos = 0;
	while (tmp)
	{
		if (tmp->index == 0)
			smallest_pos = len;
		len++;
		tmp = tmp->next;
	}
	if ((len + 1) / 2 < smallest_pos)
		while (smallest_pos++ < len)
			rra(a);
	else
		while (smallest_pos-- > 0)
			ra(a);
}
