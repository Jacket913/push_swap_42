/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:09:32 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/11 14:44:29 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->value > (*a)->next->value)
		swap(a);
}

void	sort_3(t_stack **a)
{
	if ((*a)->value > (*a)->next->value && (*a)->value > (*a)->next->next->value)
	{
		ra(a);
		sort_2(a);
	}
	else if ((*a)->value < (*a)->next->value && (*a)->next->value > (*a)->next->next->value)
	{
		rra(a);
		sort_2(a);
	}
	else if ((*a)->value < (*a)->next->next->value && (*a)->next->value < (*a)->next->next->value)
		sort_2(a);
}

void	start_sort(t_stack **a)
{
	if (stacksize(*a) == 2)
		sort_2(a);
	else if (stacksize(*a) == 3)
		sort_3(a);
}
