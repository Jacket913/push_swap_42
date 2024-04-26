/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andymalgonne <andymalgonne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:27:14 by gmoulin           #+#    #+#             */
/*   Updated: 2024/04/26 10:46:23 by andymalgonn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (!*src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->next = *dest;
	if (*dest)
		(*dest)->prev = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	ft_putendl_fd("pa", 1);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	ft_putendl_fd("pb", 1);
}
