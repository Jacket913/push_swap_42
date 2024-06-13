/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:26:29 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/13 17:57:52 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushonb(t_stack **a, t_stack **b)
{
	while (stacksize(*a) > 3)
		pa(a, b);
}

void	indexing(t_stack **a)
{
	t_stack *lowest;
	t_stack	*tmp;
	int		i;
	int		size;

	i = 0;
	size = stacksize(*a);
	tmp = *a;
	lowest = *a;
	while (size--)
	{
		while (tmp)
			{
				if (lowest > tmp && !tmp->index)
					lowest = tmp;
				tmp = tmp->next;
			}
		lowest->index = i;
		i++;
	}
}
