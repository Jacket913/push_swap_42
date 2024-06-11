/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:05:58 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/11 14:54:01 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**ft_fsplit(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

void	ft_memdel(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

size_t	stacksize(t_stack *stack)
{
	size_t	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

int	check_dup(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (*a)
	{
		tmp = (*a)->next;
		while (tmp)
		{
			if ((*a)->value == tmp->value)
				return (1);
			tmp = tmp->next;
		}
		*a = (*a)->next;
	}
	return (0);
}
