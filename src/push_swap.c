/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:13:55 by pbotargu          #+#    #+#             */
/*   Updated: 2023/12/28 01:13:21 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_rr_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rr(a, b);
	ft_current_position(*a);
	ft_current_position(*b);
}

static void	ft_rrr_stacks(t_stack **a, t_stack **b, t_stack *cheapest)
{
	while (*a != cheapest->target && *b != cheapest)
		rrr(a, b);
	ft_current_position(*a);
	ft_current_position(*b);
}

static void	ft_put_top(t_stack **stack, t_stack *top, int a_b)
{
	while (*stack != top)
	{
		if (a_b == 1)
		{
			if (top->above_median)
				ra(stack, 1);
			else
				rra(stack, 1);
		}
		else if (a_b == 0)
		{
			if (top->above_median)
				rb(stack, 1);
			else
				rrb(stack, 1);
		}
	}
}

static void	ft_move_nodes(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = *b;
	while (cheap->cheapest == 0)
		cheap = cheap->next;
	if (cheap->above_median && cheap->target->above_median)
		ft_rr_stacks(a, b, cheap);
	else if (!(cheap->above_median) && !(cheap->target->above_median))
		ft_rrr_stacks(a, b, cheap);
	ft_put_top(a, cheap->target, 1);
	ft_put_top(b, cheap, 0);
	pa(a, b);
}

void	ft_push_swap(t_stack **a, t_stack **b)
{
	t_stack	*smallest_one;
	int		len_a;

	len_a = ft_stack_len(*a);
	while (len_a-- > 3)
		pb(b, a);
	ft_sort_three(a);
	while (*b)
	{
		ft_info_nodes(*a, *b);
		ft_move_nodes(a, b);
	}
	ft_current_position(*a);
	smallest_one = ft_find_small(*a);
	if (smallest_one->above_median)
	{
		while (*a != smallest_one)
			ra(a, 1);
	}
	else
		while (*a != smallest_one)
			rra(a, 1);
}
