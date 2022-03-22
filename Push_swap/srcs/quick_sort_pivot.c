/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_pivot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:50:16 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:52:49 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	*init_arr(t_stack *a, int len)
{
	int	*arr;
	int	i;

	arr = (int *)malloc(sizeof(int) * len);
	if (arr == NULL)
		std_err();
	i = 0;
	while (i < len)
	{
		arr[i] = a->data;
		a = a->next;
		i++;
	}
	return (arr);
}

void	assign_pvt(int len, t_data_struct *data_struct, int *arr)
{
	int	i;
	int	j;
	int	cnt_less_than_std_num;

	i = 0;
	while (i < len)
	{
		j = 0;
		cnt_less_than_std_num = 0;
		while (j < len)
		{
			if (arr[i] > arr[j])
				cnt_less_than_std_num++;
			j++;
		}
		if (cnt_less_than_std_num == data_struct->small_pvt_idx)
			data_struct->small_pvt = arr[i];
		else if (cnt_less_than_std_num == data_struct->big_pvt_idx)
			data_struct->big_pvt = arr[i];
		i++;
	}
}

void	set_pvt(t_stack *a, int len, char stack_flag,
					t_data_struct *data_struct)
{
	int	*arr;
	int	std_pvt;

	arr = init_arr(a, len);
	std_pvt = len / 3;
	if (len % 3 == 2)
		std_pvt++;
	if (stack_flag == 'a')
	{
		data_struct->small_pvt_idx = (len - 1) - (2 * std_pvt);
		data_struct->big_pvt_idx = (len - 1) - std_pvt;
	}
	else if (stack_flag == 'b')
	{
		data_struct->small_pvt_idx = std_pvt;
		data_struct->big_pvt_idx = 2 * std_pvt;
	}
	assign_pvt(len, data_struct, arr);
	free(arr);
	arr = NULL;
}
