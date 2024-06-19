/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:26:29 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/19 17:48:45 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pushonb(t_stack **a, t_stack **b)
{
	while (stacksize(*a) > 3)
		pa(a, b);
}

//t_stack	*get_new(t_stack *a)
//{
//	while (a->next)
//	{
//		if (a->index == 0)
//			return (a);
//		a = a->next;
//	}
//	return (a);
//}

void	indexing(t_stack **a)
{
	t_stack	*lowest;
	t_stack	*tmp;
	size_t		i;

	i = 1;
	while (i <= stacksize(*a))
	{
		tmp = *a;
		lowest = *a;
		while (lowest->index)
			lowest = lowest->next;
		while (tmp)
		{
			if (lowest->value > tmp->value && !tmp->index)
				lowest = tmp;
			tmp = tmp->next;
		}
		lowest->index = i;
		i++;
	}
}

void	rotatelist(t_stack **x, t_move *m, int which_list)
{
	if (m->rotate > 0)
	{
		while (m->rotate-- > 0)
		{
			if (which_list == 0)
				ra(x);
			else
				rb(x);
		}
	}
	else
	{
		while (m->rotate++ < 0)
		{
			if (which_list == 0)
				rra(x);
			else
				rrb(x);
		}
	}
}

void	whichrotate(t_stack *x, t_move *m, int index)
{
	t_move	tmpm;
	t_stack	*tmpx;

	tmpx = x;
	while (tmpx->next)
		tmpx = tmpx->next;
	m->rotate = 0;
	tmpm.rotate = 0;
	while (tmpx->index != index)
	{
		tmpm.rotate--;
		tmpx = tmpx->prev;
	}
	while (x->index != index)
	{
		m->rotate++;
		x = x->next;
	}
	printf("m->rotate = %d\n", m->rotate);
	printf("tmpm.rotate = %d\n", tmpm.rotate);
	if (m->rotate > -tmpm.rotate)
		m->rotate = tmpm.rotate;
	printf("m->rotate = %d\n", m->rotate);
}

void	cheaper_move(t_stack *a, t_stack *b, t_move *ma, t_move *mb)
{
	t_move	cheaper;
	t_stack	*tmp;
	int	index;
	int	sum;

	tmp = b;
	cheaper.rotate = -1;
	while (tmp)
	{
		whichrotate(a, ma, tmp->index);
		whichrotate(b, mb, tmp->index);
		sum = abs(ma->rotate) + abs(mb->rotate);
		if (cheaper.rotate == -1 || cheaper.rotate > sum)
		{
			cheaper.rotate = ma->rotate + mb->rotate;
			index = tmp->index;
		}
		tmp = tmp->next;
	}
	whichrotate(a, ma, index);
	whichrotate(b, mb, index);
}
