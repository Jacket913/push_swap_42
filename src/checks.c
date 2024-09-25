/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:17:14 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/23 19:21:01 by gmoulin          ###   ########.fr       */
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
	int	i;

	i = a->value;
	while (a)
	{
		if (i > a->value)
			return (0);
		i = a->value;
		a = a->next;
	}
	return (1);
}

void	error_arg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
