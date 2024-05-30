/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 16:32:13 by gmoulin           #+#    #+#             */
/*   Updated: 2024/05/30 16:12:24 by gmoulin          ###   ########.fr       */
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

void	print(t_stack *x)
{
	t_stack	*tmp;

	tmp = x;
	while (tmp)
	{
		ft_printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	ft_putchar_fd('\n', 1);
}


int	main()
{
	t_stack *a;
	t_stack *b;

	a = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	a->next = malloc(sizeof(t_stack));
	b->next = malloc(sizeof(t_stack));
	a->next->next = malloc(sizeof(t_stack));
	b->next->next = malloc(sizeof(t_stack));

	a->next->prev = a;
    a->next->next->prev = a->next;
    a->next->next->next = NULL;
    a->value = 5;
    a->next->value = 6;
    a->next->next->value = 7;

    b->next->prev = b;
    b->next->next->prev = b->next;
    b->next->next->next = NULL;
    b->value = 5;
    b->next->value = 6;
    b->next->next->value = 7;

	//pa(&a, &b);
	//pb(&b, &a);
	//ra(&a);
	//rb(&b);
	//rra(&a);
	//rrb(&b);
	sa(&a);
	//sb(&b);
	(print(a), print(b));
}
