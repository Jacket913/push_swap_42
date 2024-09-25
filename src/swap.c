/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:49 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 12:31:05 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a)
{
	t_stack	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	tmp->prev = *a;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	ft_putendl_fd("sa", 1);
}

void	sb(t_stack **b)
{
	t_stack	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = (*b)->next;
	(*b)->next = tmp;
	tmp->prev = *b;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	ft_putendl_fd("sb", 1);
}

void	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
}
