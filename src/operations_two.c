/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations_two.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akivioja <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/18 16:30:40 by akivioja      #+#    #+#                 */
/*   Updated: 2023/05/18 16:30:56 by akivioja      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_stack **dlist, int RraRrb)
{
	t_stack	*temp;

	temp = *dlist;
	*dlist = temp->prev;
	if (RraRrb == 0)
		write(1, "rra\n", 4);
	else if (RraRrb == 1)
		write(1, "rrb\n", 4);
	else if (RraRrb == 2)
		write(1, "rrr\n", 4);
	else
		return ;
}

void	reverse_rotate_both(t_stack **stackA, t_stack **stackB)
{
	reverse_rotate(stackA, 2);
	reverse_rotate(stackB, 3);
}
