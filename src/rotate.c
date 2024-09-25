/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:18 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 12:31:40 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a)
{
	t_stack	*nlast;
	t_stack	*last;

	if (!*a || !(*a)->next)
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
	t_stack	*tmp;
	t_stack	*last;

	if (!(*b))
		return ;
	tmp = (*b)->next;
	last = dlstlast(*b);
	tmp->prev = NULL;
	(*b)->next = NULL;
	(*b)->prev = last;
	last->next = (*b);
	(*b) = tmp;
	ft_printf("rb\n");
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
