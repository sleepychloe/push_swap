/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:43:02 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:43:31 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_do_operation(char *str, t_stack **a, t_stack **b)
{
	if (!ft_strcmp(str, "sa") && ft_operation_s(*a))
		write(1, "sa\n", 3);
	else if (!ft_strcmp(str, "sb") && ft_operation_s(*b))
		write(1, "sb\n", 3);
	else if (!ft_strcmp(str, "ss") && ft_operation_s(*a) && ft_operation_s(*b))
		write(1, "ss\n", 3);
	else if (!ft_strcmp(str, "pa") && ft_operation_p(a, ft_take_node(b)))
		write(1, "pa\n", 3);
	else if (!ft_strcmp(str, "pb") && ft_operation_p(b, ft_take_node(a)))
		write(1, "pb\n", 3);
	else if (!ft_strcmp(str, "ra") && ft_operation_r(a))
		write(1, "ra\n", 3);
	else if (!ft_strcmp(str, "rb") && ft_operation_r(b))
		write(1, "rb\n", 3);
	else if (!ft_strcmp(str, "rr") && ft_operation_r(a) && ft_operation_r(b))
		write(1, "rr\n", 3);
	else if (!ft_strcmp(str, "rra") && ft_operation_rr(a))
		write(1, "rra\n", 4);
	else if (!ft_strcmp(str, "rrb") && ft_operation_rr(b))
		write(1, "rrb\n", 4);
	else if (!ft_strcmp(str, "rrr") && ft_operation_rr(a) && ft_operation_rr(b))
		write(1, "rrr\n", 4);
}
