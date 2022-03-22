/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_len_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:46:10 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:47:15 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	sort_len_5(t_stack **a, t_stack **b)
{
	int	min_data;
	int	max_data;
	int	cnt_op_pb;

	min_data = ft_min_data(*a);
	max_data = ft_max_data(*a);
	cnt_op_pb = 0;
	while (ft_get_stack_len(*a) > 3)
	{
		if ((*a)->data == min_data || (*a)->data == max_data)
		{
			ft_do_operation("pb", a, b);
			cnt_op_pb++;
		}
		else
			ft_do_operation("ra", a, b);
	}
	if (ft_is_descend(*a, 3))
		reverse_stack_a(a, b, 3);
	else if (!ft_is_ascend(*a, 3))
		sort_len_3(a, b);
	while (cnt_op_pb-- > 0)
		operation_pa_min_max(a, b, min_data);
}
