/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:32:13 by gmoulin           #+#    #+#             */
/*   Updated: 2024/05/23 17:17:59 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_num(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (1);
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

void	ft_memdel(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

int	main(int ac, char *av)
{
	size_t	i;

	i = 0;
	if (ac < 2)
		return (0);
	while (ac > 1)
		if (!check_num(av[i]))
			return (0);
		ac--;
		i++;
	}
	//while (*av && ac > 1)
	//{
	//	t_list *list_a = NULL;
	//	list_a = lst_new(ft_atoi(*av));
	//	if(!list_a)
	//		return (0);
	//	av++;
	//	while(ac--)
	//	{
	//		list_a = lst_add(ft_atoi(*av),  &list_a);
	//		if(!list_a)
	//			return (0);
	//	}
	//	if (!check_num(*av))
	//		return (0);
	//	av++;
	//}
	return (0);
}
