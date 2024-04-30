/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:26:46 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/30 18:54:05 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	rra(t_stack **a)
{
	t_stack *nfirst;
	t_stack *first;

	if(!*a)
		return ;
	if (*a && (*a)->next)
	{
		nfirst = *a;
		first = *a;
		while (nfirst->next)
			nfirst = nfirst->next;
		first->prev = nfirst;
		nfirst->next = first;
		*a = nfirst;
		nfirst->prev->next = NULL; //set new last ->next to NULL
		nfirst->prev = NULL;
		ft_putendl_fd("rra", 1);
	}
}

void	rrb(t_stack **b)
{
	t_stack *nfirst;
	t_stack *first;

	if(!*b)
		return ;
	if (*b && (*b)->next)
	{
		nfirst = *b;
		first = *b;
		while (nfirst->next)
			nfirst = nfirst->next;
		first->prev = nfirst;
		nfirst->next = first;
		*b = nfirst;
		nfirst->prev->next = NULL; //set new last ->next to NULL
		nfirst->prev = NULL;
		ft_putendl_fd("rrb", 1);
	}
}

void	rrr(t_stack **a, t_stack **b)
{
	rra(a);
	rrb(b);
	ft_putendl_fd("rrr", 1);
}
