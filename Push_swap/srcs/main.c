/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhwang <yhwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:32:58 by yhwang            #+#    #+#             */
/*   Updated: 2022/03/21 16:36:52 by yhwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	std_err(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_count_len(char **argv)
{
	int		len;
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

static void	check_duplicate(t_stack *a)
{
	t_stack	*last;
	t_stack	*curr;

	last = a->prev;
	curr = a->next;
	while (1)
	{
		if (a == last)
			break ;
		while (1)
		{
			if (curr == last->next)
				break ;
			if (a->data == curr->data)
				std_err();
			curr = curr->next;
		}
		a = a->next;
		curr = a->next;
	}
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
		quick_sort_a_to_b(a, b, len);
}

int	main(int argc, char **argv)
{
	int			len;
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
