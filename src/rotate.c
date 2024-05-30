/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:26:38 by gmoulin           #+#    #+#             */
/*   Updated: 2024/05/30 16:04:27 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack *nlast;
	t_stack *last;

	if(!*a || !(*a)->next)
		return ;
	nlast = *a;
	last = *a;
	while (last->next)
		last = last->next;
	*a = nlast->next;
	last->next = nlast;
	nlast->prev = last;
	nlast->next = NULL;
	(*a)->prev = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_stack **b)
{
	t_stack *nlast;
	t_stack *last;

	if(!*b || !(*b)->next)
		return ;
	nlast = *b;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = nlast;
	nlast->prev = last;
	*b = nlast->next;
	nlast->next = NULL;
	(*b)->prev = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_putendl_fd("rr", 1);
}
