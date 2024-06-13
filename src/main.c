/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acroue <acroue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:32:13 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/13 18:59:11 by acroue           ###   ########.fr       */
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

int	init(int value, t_stack **a)
{
	t_stack	*new;
	t_stack	*oldlast;

	if (!*a)
		return (0);
	oldlast = *a;
	while (oldlast->next)
		oldlast = oldlast->next;
	new = ft_calloc(1, sizeof(t_stack));
	if (!new)
		return (0);
	oldlast->next = new;
	new->prev = oldlast;
	new->value = value;
	new->next = NULL;
	return (1);
}

int	check_arg(char *av, t_stack **a)
{
	char	*tmp;
	int		x;
	char	**split;
	int		i;

	split = ft_split(av, ' ');
	if (!split || !split[0])
		return (ft_fsplit(split), 0);
	i = 0;
	while (split[i])
	{
		x = ft_atoi(split[i]);
		tmp = ft_itoa(x);
		if (!tmp)
			return (0);
		if (ft_strncmp(tmp, split[i], ft_strlen(split[i])))
			return (free(tmp), ft_fsplit(split), 0);
		if (!init_stack(x, a))
			return (free(tmp), ft_fsplit(split), 0);
		free(tmp);
		i++;
	}
	ft_fsplit(split);
	return (1);
}

int	push_swap(int ac, char *av[], t_stack **a, t_stack **b)
{
	int	i;

	i = 0;
	if (ac < 2)
		return (0);
	while (++i < ac)
	{
		if (!check_arg(av[i], a))
			return (free_list(*a), error_arg(), 0);
	}
	if (check_dup(*a))
		return (free_list(*a), free_list(*b), error_arg(), 0);
	if (!check_sorted(*a))
		return (free_list(*a), free_list(*b), error_arg(), 0);
	indexing(a);
	pushonb(a, b);
	start_sort(a);
	return (1);
}

void	printindex(t_stack *tab)
{

	size_t	alec	= stacksize(tab);
	for (size_t i = 0; i < alec; i++)
	{
		printf("%d\n", tab->index);
		tab = tab->next;
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (push_swap (ac, av, &a, &b) == 0)
		return (0);
	(print(a), print(b));
	printindex(a), printindex(b);
	(free_list(a), free_list(b));
	return (0);
}
