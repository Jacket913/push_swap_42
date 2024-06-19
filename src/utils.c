/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 17:42:17 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/19 18:56:45 by gmoulin          ###   ########.fr       */
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

int	stacksize(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

void	print(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp)
	{
		ft_printf("Value : %d,  Index : %d / ", tmp->value, tmp->index);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}

void	error_arg(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
