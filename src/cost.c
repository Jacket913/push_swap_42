/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:39:26 by gmoulin           #+#    #+#             */
/*   Updated: 2024/06/19 18:40:46 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
