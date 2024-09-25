/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:42 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 12:30:50 by gmoulin          ###   ########.fr       */
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
