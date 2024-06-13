/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:05:58 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/13 18:29:07 by acroue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_dup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}

int	check_sorted(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = (a)->next;
		while (tmp)
		{
			if ((a)->value > tmp->value)
				return (1);
			tmp = tmp->next;
		}
		a = (a)->next;
	}
	return (0);
}
