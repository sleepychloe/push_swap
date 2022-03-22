/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_a_to_b.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:53:24 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:56:22 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	divide_a(t_stack **a, t_stack **b, int len,
						t_data_struct *data_struct)
{
	while (len > 0)
	{
		if ((*a)->data <= data_struct->small_pvt)
		{
			ft_do_operation("pb", a, b);
			(data_struct->cnt_op_pb)++;
		}
		else if ((*a)->data > data_struct->big_pvt)
		{
			ft_do_operation("ra", a, b);
			(data_struct->cnt_op_ra)++;
		}
		else
		{
			ft_do_operation("pb", a, b);
			(data_struct->cnt_op_pb)++;
			ft_do_operation("rb", a, b);
			(data_struct->cnt_op_rb)++;
		}
		len--;
	}
}

void	rewind_stack(t_stack **a, t_stack **b, int len)
{
	while (len > 0)
	{
		ft_do_operation("rrr", a, b);
		len--;
	}
}

void	sort_a(t_stack **a, t_stack **b, int len)
{
	if (len == 2 || len == 3)
	{
		if ((*a)->data > (*a)->next->data)
			ft_do_operation("sa", a, b);
		if (len == 3 && !ft_is_ascend(*a, len))
		{
			ft_do_operation("ra", a, b);
			ft_do_operation("sa", a, b);
			ft_do_operation("rra", a, b);
			if ((*a)->data > (*a)->next->data)
				ft_do_operation("sa", a, b);
		}
	}
	else if (len == 4)
		sort_len_4(a, b);
	else if (len == 5)
		sort_len_5(a, b);
}

void	quick_sort_a_to_b(t_stack **a, t_stack **b, int len)
{
	t_data_struct	data_struct;

	if (len <= 5)
	{
		if (!ft_is_ascend(*a, len))
			sort_a(a, b, len);
		return ;
	}
	data_struct.small_pvt = 0;
	data_struct.big_pvt = 0;
	data_struct.small_pvt_idx = 0;
	data_struct.big_pvt_idx = 0;
	data_struct.cnt_op_ra = 0;
	data_struct.cnt_op_rb = 0;
	data_struct.cnt_op_pa = 0;
	data_struct.cnt_op_pb = 0;
	set_pvt(*a, len, 'a', &data_struct);
	divide_a(a, b, len, &data_struct);
	rewind_stack(a, b, data_struct.cnt_op_rb);
	quick_sort_a_to_b(a, b, data_struct.cnt_op_ra);
	quick_sort_b_to_a(a, b, data_struct.cnt_op_rb);
	quick_sort_b_to_a(a, b, data_struct.cnt_op_pb - data_struct.cnt_op_rb);
}
