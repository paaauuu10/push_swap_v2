/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:55:41 by pbotargu          #+#    #+#             */
/*   Updated: 2023/12/28 01:13:24 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b)
{
	t_stack	*push;

	if (*b == NULL)
		return ;
	push = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	push->prev = NULL;
	if (*a == NULL)
	{
		*a = push;
		push->next = NULL;
	}
	else
	{
		push->next = *a;
		push->next->prev = push;
		*a = push;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack **b, t_stack **a)
{
	t_stack	*push;

	if (*a == NULL)
		return ;
	push = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	push->prev = NULL;
	if (*b == NULL)
	{
		*b = push;
		push->next = NULL;
	}
	else
	{
		push->next = *b;
		push->next->prev = push;
		*b = push;
	}
	write(1, "pb\n", 3);
}
