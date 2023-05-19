/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   radix_sort.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 17:04:59 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/18 17:31:30 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_min(t_stack **dlist)
{
	t_stack	*temp;
	t_stack	*min_node;
	int		min;

	temp = *dlist;
	min_node = NULL;
	min = 2147483647;
	while (1)
	{
		if (temp->data < min && temp->index == -1)
		{
			min_node = temp;
			min = temp->data;
		}
		temp = temp->next;
		if (temp == *dlist)
			break ;
	}
	if (min_node == NULL)
		return (NULL);
	return (min_node);
}

int	assign_index(t_stack **dlist)
{
	t_stack	*min;
	int		index;

	min = *dlist;
	index = 0;
	while (1)
	{
		min = find_min(dlist);
		if (!min)
			break ;
		min->index = index;
		index++;
	}
	return (index);
}

int	size_of_index(int maxIndex)
{
	int	size_of_index;

	size_of_index = 0;
	while (maxIndex > 0)
	{
		maxIndex = maxIndex >> 1;
		size_of_index++;
	}
	return (size_of_index);
}

int	radix_pimp(t_stack **stackA, t_stack **stackB, int size, int bit_pos)
{
	int		index;
	t_stack	*temp;

	temp = *stackA;
	while (size > 0)
	{
		index = temp->index;
		temp = temp->next;
		if ((index & (1 << bit_pos)) == 0 && size != 1)
			push(stackA, stackB, 0);
		else if ((index & (1 << bit_pos)) == 0 && size == 1)
			break ;
		else
			rotate(stackA, 0);
		size--;
	}
	return (bit_pos);
}

void	radix_sort(t_stack **stackA, t_stack **stackB, int max_index)
{
	t_stack	*temp;
	int		size;
	int		index_size;
	int		bit_position;

	index_size = size_of_index(max_index);
	bit_position = 0;
	while (bit_position < index_size)
	{
		temp = *stackA;
		size = ft_dlstsize(*stackA);
		bit_position = radix_pimp(stackA, stackB, size, bit_position);
		size = ft_dlstsize(*stackB);
		while (size-- > 0)
			push(stackB, stackA, 1);
		*stackB = NULL;
		bit_position++;
	}
}
