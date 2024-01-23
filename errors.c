/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:20:43 by paubotargue       #+#    #+#             */
/*   Updated: 2024/01/10 11:49:34 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_syntax_error(char *s)
{
	if (!(*s == '+'
			|| *s == '-'
			|| (*s >= '0' && *s <= '9')))
		return (1);
	if ((*s == '+'
			|| *s == '-')
		&& !(s[1] >= '0' && s[1] <= '9'))
		return (1);
	while (*++s)
	{
		if (!(*s >= '0' && *s <= '9'))
			return (1);
	}
	return (0);
}

int	ft_find_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return ;
	while (argv[i] != NULL)
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	ft_free_stack(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*current;

	if (a == NULL)
		return ;
	current = *a;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*a = NULL;
}

void	ft_error_free(t_stack **a, char **argv, int flag)
{
	ft_free_stack(a);
	if (flag == 1)
	{
		free_split(argv);
	}
	write(2, "Error\n", 6);
	exit(1);
}
