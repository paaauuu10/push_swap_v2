/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbotargu <pbotargu@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 23:20:51 by paubotargue       #+#    #+#             */
/*   Updated: 2023/12/28 01:13:14 by pbotargu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *str)
{
	int		i;
	int		negative;
	long	num;

	i = 0;
	negative = 1;
	num = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		negative = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * negative);
}

void	ft_init_stack(t_stack **a, char **argv, int flag)
{
	long	nbr;
	int		i;

	i = 0;
	if (!flag)
		argv++;
	while (argv[i])
	{
		if (ft_syntax_error(argv[i]))
			ft_error_free(a, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			ft_error_free(a, argv, flag);
		if (ft_find_repetition(*a, (int)nbr))
			ft_error_free(a, argv, flag);
		ft_add_to_final(a, (int)nbr);
		i++;
	}
	if (flag)
		free_split(argv);
}
