/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:02:48 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 17:52:56 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/incs/libft.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_data_struct
{
	int	small_pvt;
	int	big_pvt;
	int	small_pvt_idx;
	int	big_pvt_idx;
	int	cnt_op_ra;
	int	cnt_op_rb;
	int	cnt_op_pa;
	int	cnt_op_pb;
}	t_data_struct;

int			ft_modified_atoi(const char *str);
t_stack		*create_new_node(int changed_to_int);
void		append_new_node(t_stack **a, t_stack *new_node);
void		init_stack(char **argv, t_stack **a, t_stack **b);
int			ft_operation_s(t_stack *head);
t_stack		*ft_take_node(t_stack **src_stack_head);
int			ft_operation_p(t_stack **dest_stack_head, t_stack *taken_node);
int			ft_operation_r(t_stack **head);
int			ft_operation_rr(t_stack **head);
void		ft_do_operation(char *str, t_stack **a, t_stack **b);
int			ft_min_data(t_stack *head);
int			ft_max_data(t_stack *head);
void		sort_len_3(t_stack **a, t_stack **b);
void		sort_len_4(t_stack **a, t_stack **b);
int			ft_is_descend(t_stack *head, int len);
int			ft_is_ascend(t_stack *head, int len);
void		reverse_stack_a(t_stack **a, t_stack **b, int len);
int			ft_get_stack_len(t_stack *head);
void		operation_pa_min_max(t_stack **a, t_stack **b, int min_data);
void		sort_len_5(t_stack **a, t_stack **b);
int			*init_arr(t_stack *a, int len);
void		assign_pvt(int len, t_data_struct *data_struct, int *arr);
void		set_pvt(t_stack *a, int len, char stack_flag,
				t_data_struct *data_struct);
void		divide_a(t_stack **a, t_stack **b, int len,
				t_data_struct *data_struct);
void		rewind_stack(t_stack **a, t_stack **b, int len);
void		sort_a(t_stack **a, t_stack **b, int len);
void		quick_sort_a_to_b(t_stack **a, t_stack **b, int len);
void		divide_b(t_stack **a, t_stack **b, int len,
				t_data_struct *data_struct);
void		sort_b(t_stack **a, t_stack **b, int len);
void		quick_sort_b_to_a(t_stack **a, t_stack **b, int len);
void		std_err(void);
int			ft_count_len(char **argv);
void		check_cuplicate(t_stack *a);
void		sort(t_stack **a, t_stack **b, int len);
int			main(int argc, char **argv);

#endif
