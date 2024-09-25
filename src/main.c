/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:26:02 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/25 16:12:23 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(int value, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = ft_calloc(1, sizeof(t_stack));
	if (!tmp)
		return (0);
	tmp->value = value;
	tmp->next = NULL;
	tmp->prev = NULL;
	if (!*a)
		return (*a = tmp, 1);
	last = (*a);
	while (last->next)
		last = last->next;
	last->next = tmp;
	return (tmp->prev = last, 1);
}

void	push_swap(int ac, char *av[], t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ac < 2)
		return ;
	while (++i < ac)
	{
		if (!check_arg(av[i], a))
			(free_list(*a), error_arg());
	}
	if (check_dup(*a))
		return (free_list(*a), free_list(*b), error_arg());
	if (check_sorted(*a))
		return (free_list(*a), free_list(*b));
	if (check_sorted(*a))
		return (free_list(*a));
	pre_sort(a, b);
	cost_and_sort(a, b);
	if (!check_sorted(*a))
		sort_in_position(a);
	return (free_list(*a), free_list(*b));
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	push_swap (ac, av, &a, &b);
	return (0);
}
