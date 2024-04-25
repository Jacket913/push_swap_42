/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:27:07 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/25 16:57:47 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	tmp->next = (*a)->next;
	tmp->prev = (*a)->prev;
	(*a)->next = (*a)->next->next;
	(*a)->prev = (*a)->next->prev;
	(*a)->next->next = tmp->next;
	(*a)->next->prev = tmp->prev;
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	tmp->next = (*b)->next;
	tmp->prev = (*b)->prev;
	(*b)->next = (*b)->next->next;
	(*b)->prev = (*b)->next->prev;
	(*b)->next->next = tmp->next;
	(*b)->next->prev = tmp->prev;
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
