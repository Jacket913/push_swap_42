/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:27:07 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 12:18:11 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_stack *x)
{
	t_stack	*tmp;

	if (!x)
		return ;
	while (x)
	{
		tmp = x->next;
		free(x);
		x = tmp;
	}
}

int	stack_size(t_stack *a)
{
	int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

t_stack	*dlstlast(t_stack *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	dlstadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	new->next = tmp;
	new->prev = NULL;
	if (tmp)
		tmp->prev = new;
	*lst = new;
}

void	print_stack(t_stack *a)
{
	while (a)
	{
		printf("Value: %d || Index: %d\n", a->value, a->index);
		a = a->next;
	}
}
