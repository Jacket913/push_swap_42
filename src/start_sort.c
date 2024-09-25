/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:42 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 16:16:17 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		sa(a);
}

void	sort_three(t_stack	**a)
{
	if ((*a)->value > (*a)->next->value && \
		(*a)->value > (*a)->next->next->value)
	{
		ra(a);
		sort_two(a);
	}
	else if ((*a)->value < (*a)->next->value && \
		(*a)->next->value > (*a)->next->next->value)
	{
		rra(a);
		sort_two(a);
	}
	else if ((*a)->value < (*a)->next->next->value && \
		(*a)->next->value < (*a)->next->next->value)
		sort_two(a);
}

void	start_sort(t_stack **a)
{
	if (stack_size(*a) == 2)
		sort_two(a);
	else if (stack_size(*a) == 3)
		sort_three(a);
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
