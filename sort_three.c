/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:37:09 by paubotargue       #+#    #+#             */
/*   Updated: 2023/12/27 23:39:37 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*find_big_one(t_stack *a)
{
	int		big;
	t_stack	*big_one;

	if (a == NULL)
		return (NULL);
	big = -2147483648;
	while (a)
	{
		if (a->value > big)
		{
			big = a->value;
			big_one = a;
		}
		a = a->next;
	}
	return (big_one);
}

void	ft_sort_three(t_stack **a)
{
	t_stack	*big_one;

	big_one = find_big_one(*a);
	if (*a == big_one)
		ra(a, 1);
	else if ((*a)->next == big_one)
		rra(a, 1);
	if ((*a)->value > (*a)->next->value)
		sa(a, 1);
}
