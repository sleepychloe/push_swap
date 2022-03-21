/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_b_to_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:56:45 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:58:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	divide_b(t_stack **a, t_stack **b, int len, t_data_struct *data_struct)
{
	while (len > 0)
	{
		if ((*b)->data >= data_struct->big_pvt)
		{
			ft_do_operation("pa", a, b);
			(data_struct->cnt_op_pa)++;
		}
		else if ((*b)->data < data_struct->small_pvt)
		{
			ft_do_operation("rb", a, b);
			(data_struct->cnt_op_rb)++;
		}
		else
		{
			ft_do_operation("pa", a, b);
			(data_struct->cnt_op_pa)++;
			ft_do_operation("ra", a, b);
			(data_struct->cnt_op_ra)++;
		}
		len--;
	}
}

static void	sort_b(t_stack **a, t_stack **b, int len)
{
	if (len == 2 || len == 3)
	{
		if ((*b)->data < (*b)->next->data)
			ft_do_operation("sb", a, b);
		if (len == 3)
		{
			if (!ft_is_descend(*b, len))
			{
				ft_do_operation("rb", a, b);
				ft_do_operation("sb", a, b);
				ft_do_operation("rrb", a, b);
				if ((*b)->data < (*b)->next->data)
					ft_do_operation("sb", a, b);
			}
			ft_do_operation("pa", a, b);
		}
		ft_do_operation("pa", a, b);
	}
	ft_do_operation("pa", a, b);
}

void	quick_sort_b_to_a(t_stack **a, t_stack **b, int len)
{
	t_data_struct	data_struct;

	if (len <= 3)
	{
		sort_b(a, b, len);
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
	set_pvt(*b, len, 'b', &data_struct);
	divide_b(a, b, len, &data_struct);
	quick_sort_a_to_b(a, b, data_struct.cnt_op_pa - data_struct.cnt_op_ra);
	rewind_stack(a, b, data_struct.cnt_op_ra);
	quick_sort_a_to_b(a, b, data_struct.cnt_op_ra);
	quick_sort_b_to_a(a, b, data_struct.cnt_op_rb);
}
