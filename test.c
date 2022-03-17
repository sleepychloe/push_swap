/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/05 18:52:08 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/17 07:00:23 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int	data;
	struct	s_stack	*prev;
	struct	s_stack	*next;
}	t_stack;

void	std_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_count_len(char **argv)
{
	int	len;
	char	*backup;

	len = 0;
	while (*argv)
	{
		if (**argv == '\0')
			std_err();
		backup = *argv;
		while (**argv)
		{
			while (**argv && **argv == ' ')
				(*argv)++;
			if (**argv && **argv != ' ')
				len++;
			while (**argv && **argv != ' ')
				(*argv)++;
		}
		*argv = backup;
		argv++;
	}
	return (len);
}

int	ft_modified_atoi(const char *str)
{
	int	sign;
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
	nbr =  sign * ret;
	if (nbr < -2148483648 || nbr > 2147483647)
		std_err();
	return (nbr);
}

static t_stack	*create_new_node(int changed_to_int)
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
	int		changed_to_int;
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

static void	check_duplicate(t_stack *a)
{
	t_stack	*last;
	t_stack	*curr;

	last = a->prev;
	curr = a->next;
	while (1)
	{
		if (a == last)
			break;
		while (1)
		{
			if (curr == last->next)
				break;
			if (a->data == curr->data)
				std_err();
			curr = curr->next;
		}
		a = a->next;
		curr = a->next;
	}
}

static int	ft_operation_s(t_stack *head)
{
	int	temp;

	temp = head->data;
	head->data = head->next->data;
	head->next->data = temp;
	return (1);
}

t_stack	*ft_take_node(t_stack **src_stack_head)
{
	t_stack *node_to_take;

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

static int	ft_operation_r(t_stack **head)
{
	*head = (*head)->next;
	return (1);
}

static int	ft_operation_rr(t_stack **head)
{
	*head = (*head)->prev;
	return (1);
}

//erase ft_strcmp() later
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
//erase ft_strcmp() later

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

int	ft_min_data(t_stack *head)
{
	t_stack	*curr;
	int	min_data;

	curr = head->next;
	min_data = head->data;
	while (1)
	{
		if (curr == head)
			break;
		if (min_data > curr->data)
			min_data = curr->data;
		curr = curr->next;
	}
	return (min_data);
}

int	ft_max_data(t_stack *head)
{
	t_stack *curr;
	int	max_data;

	curr = head->next;
	max_data = head->data;
	while(1)
	{
		if (curr == head)
			break;
		if (max_data < curr->data)
			max_data = curr->data;
		curr = curr->next;
	}
	return (max_data);
}

static void	sort_len_3(t_stack **a, t_stack **b)
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
			break;
	}
	return (stack_len);
}

static void	op_pa_min_max(t_stack **a, t_stack **b, int min_data)
{
	if ((*b)->data == min_data)
		ft_do_operation("pa", a, b);
	else
	{
		ft_do_operation("pa", a, b);
		ft_do_operation("ra", a, b);
	}
}

void	sort_len_5(t_stack  **a, t_stack **b)
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
		op_pa_min_max(a, b, min_data);
}

void	sort(t_stack **a, t_stack **b, int len)
{
	if (len == 3)
		sort_len_3(a, b);
	else if (len == 4)
		sort_len_4(a, b);
	else if (len == 5)
		sort_len_5(a, b);
	else
		a_to_b(a, b, len);
}

int	main(int argc, char **argv)
{
	int		len;
	t_stack		*a;
	t_stack		*b;

	len = 0;
	if (argc < 2)
		return (0);
	argv++;
	len = ft_count_len(argv);
	init_stack(argv, &a, &b);
	check_duplicate(a);
	if (len >= 2 && ft_is_descend(a, len))
		reverse_stack_a(&a, &b, len);
	else if (len >= 3 && !ft_is_ascend(a, len))
		sort(&a, &b, len);
	return (0);
}
