/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_len_5_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:47:39 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:49:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_descend(t_stack *head, int len)
{
	while (len > 1)
	{
		if (head->data < head->next->data)
			return (0);
		head = head->next;
		len--;
	}
	return (1);
}

int	ft_is_ascend(t_stack *head, int len)
{
	while (len > 1)
	{
		if (head->data > head->next->data)
			return (0);
		head = head->next;
		len--;
	}
	return (1);
}

void	reverse_stack_a(t_stack **a, t_stack **b, int len)
{
	int	cnt_op_pb;

	if (len == 2)
		ft_do_operation("sa", a, b);
	else if (len == 3)
	{
		ft_do_operation("sa", a, b);
		ft_do_operation("rra", a, b);
	}
	else
	{
		cnt_op_pb = 0;
		while (cnt_op_pb < len - 1)
		{
			ft_do_operation("pb", a, b);
			cnt_op_pb++;
		}
		while (cnt_op_pb > 0)
		{
			ft_do_operation("pa", a, b);
			ft_do_operation("ra", a, b);
			cnt_op_pb--;
		}
	}
}

int	ft_get_stack_len(t_stack *head)
{
	int	stack_len;
	int	last_data;

	if (head == NULL)
		return (0);
	stack_len = 1;
	last_data = head->prev->data;
	while (1)
	{
		head = head->next;
		stack_len++;
		if (head->data == last_data)
			break ;
	}
	return (stack_len);
}

static void	operation_pa_min_max(t_stack **a, t_stack **b, int min_data)
{
	if ((*b)->data == min_data)
		ft_do_operation("pa", a, b);
	else
	{
		ft_do_operation("pa", a, b);
		ft_do_operation("ra", a, b);
	}
}
