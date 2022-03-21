/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:37:14 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 17:53:27 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_modified_atoi(const char *str)
{
	int			sign;
	long long	ret;
	long long	nbr;

	sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	ret = 0;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
			ret = ret * 10 + (*str - '0');
		else
			std_err();
		str++;
	}
	nbr = sign * ret;
	if (nbr < -2148483648 || nbr > 2147483647)
		std_err();
	return (nbr);
}

t_stack	*create_new_node(int changed_to_int)
{
	t_stack		*new_node;

	new_node = malloc(sizeof(t_stack));
	if (new_node == NULL)
		std_err();
	new_node->data = changed_to_int;
	new_node->prev = new_node;
	new_node->next = new_node;
	return (new_node);
}

static void	append_new_node(t_stack **a, t_stack *new_node)
{
	if (*a == NULL)
		*a = new_node;
	else
	{
		(*a)->prev->next = new_node;
		new_node->prev = (*a)->prev;
		(*a)->prev = new_node;
		new_node->next = *a;
	}
}

static void	init_stack(char **argv, t_stack **a, t_stack **b)
{
	int			changed_to_int;
	t_stack		*new_node;

	*a = NULL;
	*b = NULL;
	while (*argv)
	{
		changed_to_int = ft_modified_atoi(*argv);
		new_node = create_new_node(changed_to_int);
		append_new_node(a, new_node);
		argv++;
	}
}
