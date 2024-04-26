/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:27:07 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/26 10:46:32 by andymalgonn      ###   ########.fr       */
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
	ft_putendl_fd("sa", 1);
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
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
