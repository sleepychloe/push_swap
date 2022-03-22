/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:41:24 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:42:36 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_operation_s(t_stack *head)
{
	int	temp;

	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	return (1);
}

t_stack	*ft_take_node(t_stack **src_stack_head)
{
	t_stack	*node_to_take;

	node_to_take = *src_stack_head;
	if (*src_stack_head == (*src_stack_head)->next)
		*src_stack_head = NULL;
	else
	{
		(*src_stack_head)->prev->next = (*src_stack_head)->next;
		(*src_stack_head)->next->prev = (*src_stack_head)->prev;
		*src_stack_head = (*src_stack_head)->next;
		node_to_take->prev = node_to_take;
		node_to_take->next = node_to_take;
	}
	return (node_to_take);
}

int	ft_operation_p(t_stack **dest_stack_head, t_stack *taken_node)
{
	if (*dest_stack_head != NULL)
	{
		(*dest_stack_head)->prev->next = taken_node;
		taken_node->prev = (*dest_stack_head)->prev;
		(*dest_stack_head)->prev = taken_node;
		taken_node->next = *dest_stack_head;
	}
	*dest_stack_head = taken_node;
	return (1);
}

int	ft_operation_r(t_stack **head)
{
	*head = (*head)->next;
	return (1);
}

int	ft_operation_rr(t_stack **head)
{
	*head = (*head)->prev;
	return (1);
}
