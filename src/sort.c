/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:26:29 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/13 19:35:13 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushonb(t_stack **a, t_stack **b)
{
	while (stacksize(*a) > 3)
		pa(a, b);
}

t_stack	*get_new(t_stack *a)
{
	while (a->next)
	{
		if (a->index == 0)
			return (a);
		a = a->next;
	}
	return (a);
}

void	indexing(t_stack **a)
{
	t_stack	*lowest;
	t_stack	*tmp;
	size_t		i;

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
