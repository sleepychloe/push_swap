/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_len_3_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:44:06 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:45:53 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_min_data(t_stack *head)
{
	t_stack	*curr;
	int		min_data;

	curr = head->next;
	min_data = head->data;
	while (1)
	{
		if (curr == head)
			break ;
		if (min_data > curr->data)
			min_data = curr->data;
		curr = curr->next;
	}
	return (min_data);
}

int	ft_max_data(t_stack *head)
{
	t_stack	*curr;
	int		max_data;

	curr = head->next;
	max_data = head->data;
	while (1)
	{
		if (curr == head)
			break ;
		if (max_data < curr->data)
			max_data = curr->data;
		curr = curr->next;
	}
	return (max_data);
}

void	sort_len_3(t_stack **a, t_stack **b)
{
	if ((*a)->data == ft_min_data(*a))
	{
		ft_do_operation("sa", a, b);
		ft_do_operation("ra", a, b);
	}
	else if ((*a)->data == ft_max_data(*a))
		ft_do_operation("ra", a, b);
	else
	{
		if ((*a)->next->data == ft_min_data(*a))
			ft_do_operation("sa", a, b);
		else
			ft_do_operation("rra", a, b);
	}
}

void	sort_len_4(t_stack **a, t_stack **b)
{
	if ((*a)->data > (*a)->next->data)
		ft_do_operation("sa", a, b);
	ft_do_operation("pb", a, b);
	if ((*a)->data > (*a)->next->data)
		ft_do_operation("sa", a, b);
	ft_do_operation("pb", a, b);
	if ((*a)->data > (*a)->next->data && (*b)->data < (*b)->next->data)
		ft_do_operation("ss", a, b);
	else if ((*a)->data > (*a)->next->data)
		ft_do_operation("sa", a, b);
	else if ((*b)->data < (*b)->next->data)
		ft_do_operation("sb", a, b);
	ft_do_operation("pa", a, b);
	if ((*a)->data > (*a)->next->data)
		ft_do_operation("sa", a, b);
	ft_do_operation("pa", a, b);
	if ((*a)->data > (*a)->next->data)
		ft_do_operation("sa", a, b);
}
