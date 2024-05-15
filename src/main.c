/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:32:13 by gmoulin           #+#    #+#             */
/*   Updated: 2024/05/15 18:18:29 by gmoulin          ###   ########.fr       */
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

void	lstaddvfront(t_stack **lst, int av)
{
	new->next = *lst;
	(*lst)->prev = *new;
	*lst = new;
}

int	init(int ac, char *av)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	i = 0;
	// create a and b stacks
	while (i < ac)
	{
		lstaddvfront(a, ft_atoi(av[i])
		i++;
	}
	//add front of each a and b stacks
}

void ft_memdel(void *ptr)
{
	free(ptr);
	ptr = NULL;
}

//*list = NULL;

int main(int ac, char *av)
{
	//int flag = 0;
	//ft_atoi_ps("12", &flag);

	while (*av && ac > 1)
	{
		t_list *list_a = NULL;
		list_a = lst_new(ft_atoi(*av));
		if(!list_a)
			return (0);
		av++;
		while(av)
		{
			list_a = lst_add(ft_atoi(*av),  &list_a);
			if(!list_a)
				return (0);
		}
		if (!check_num(*av))
			return (0);
		av++;
	}
	return (0);
}
