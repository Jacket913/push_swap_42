/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:26:29 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/13 18:58:08 by acroue           ###   ########.fr       */
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
	int		i;
	int		size;

	size = stacksize(*a);
	i = size;
	while (size--)
	{
		tmp = *a;
		lowest = *a;
		printf("tmp:%d\n", tmp->value);
		while (lowest->index)
			lowest = lowest->next;
		while (tmp)
			{
				if (lowest > tmp && !tmp->index)
					lowest = tmp;
				tmp = tmp->next;
			}
		lowest->index = i;
		printf("%d\t%d\n", lowest->value, lowest->index);
		i--;
	}
}
