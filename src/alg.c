/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <akivioja@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/03/20 17:35:25 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/18 17:09:05 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	two_items(t_stack **dlist)
{
	t_stack	*temp;

	temp = *dlist;
	if (temp->data < temp->next->data)
		return ;
	else if (temp->data > temp->next->data)
	{
		swap(temp, 0);
		return ;
	}
}

void	three_items(t_stack **dlist)
{
	t_stack	*temp;
	int		top;
	int		middle;
	int		bottom;

	temp = *dlist;
	top = temp->data;
	middle = temp->next->data;
	bottom = temp->prev->data;
	if (top > middle && middle < bottom && bottom > top)
		swap(*dlist, 0);
	else if (top > middle && middle > bottom && bottom < top)
	{
		swap(*dlist, 0);
		reverse_rotate(dlist, 0);
	}
	else if (top > middle && middle < bottom && bottom < top)
		rotate(dlist, 0);
	else if (top < middle && middle > bottom && bottom > top)
	{
		swap(*dlist, 0);
		rotate(dlist, 0);
	}
	else if (top < middle && middle > bottom && bottom < top)
		reverse_rotate(dlist, 0);
}

void	five_items_helper(t_stack **stackA, t_stack **stackB)
{
	t_stack	*temp;
	int		count;

	temp = *stackA;
	count = 0;
	while (temp->index != 1)
	{
		count++;
		temp = temp->next;
	}
	if (count == 3)
		reverse_rotate(stackA, 0);
	else
		while (count--)
			rotate(stackA, 0);
	push(stackA, stackB, 0);
	three_items(stackA);
	push(stackB, stackA, 1);
	push(stackB, stackA, 1);
}

void	five_items(t_stack **stackA, t_stack **stackB)
{
	t_stack	*temp;
	int		count;

	temp = *stackA;
	count = 0;
	while (temp->index != 0)
	{
		count++;
		temp = temp->next;
	}
	if (count > 2)
		while (count++ < 5)
			reverse_rotate(stackA, 0);
	else
		while (count--)
			rotate(stackA, 0);
	push(stackA, stackB, 0);
	five_items_helper(stackA, stackB);
}
