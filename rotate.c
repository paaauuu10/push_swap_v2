/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:39 by pbotargu          #+#    #+#             */
/*   Updated: 2023/12/28 01:13:28 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*last_one;

	if (*a == NULL || a == NULL)
		return ;
	if (ft_stack_len(*a) == 1)
		return ;
	last_one = ft_find_last(*a);
	last_one->next = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	last_one->next->prev = last_one;
	last_one->next->next = NULL;
	if (flag == 1)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int flag)
{
	t_stack	*last_one;

	if (*b == NULL || b == NULL)
		return ;
	if (ft_stack_len(*b) == 1)
		return ;
	last_one = ft_find_last(*b);
	last_one->next = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	last_one->next->prev = last_one;
	last_one->next->next = NULL;
	if (flag == 1)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	ra(a, 0);
	rb(b, 0);
	write(1, "rr\n", 3);
}
