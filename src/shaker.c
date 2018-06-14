/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shaker.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsobel <jsobel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:41:47 by jsobel            #+#    #+#             */
/*   Updated: 2018/06/12 19:30:05 by juliensobel      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	shake_it_all(t_push **a, t_push **b, int *count)
{
	while (*a && !ft_is_sort_increasing(*a))
	{
		if ((*a)->next && (*a)->value > (*a)->next->value && *b && (*b)->next && (*b)->value < (*b)->next->value)
			ss(a, b);
		else if ((*a)->next && (*a)->value > (*a)->next->value)
			sa(a);
		else if (*b && (*b)->next && (*b)->value < (*b)->next->value)
			sb(b);
		else
			pb(a, b);
		(*count)++;
	}
	while (*b && !ft_is_sort_decreasing(*b))
	{
		if (*a && (*a)->next && (*a)->value > (*a)->next->value && (*b)->next && (*b)->value < (*b)->next->value)
			ss(a, b);
		else if (*a && (*a)->next && (*a)->value > (*a)->next->value)
			sa(a);
		else if ((*b)->next && (*b)->value < (*b)->next->value)
			sb(b);
		else
			pa(a, b);
		(*count)++;
	}
	if (!check(a, b, count))
		shake_it_all(a, b, count);
}

int		divide_to_conquer(t_push **a, t_push **b, int med, int *c)
{
	int		flag;
	t_push	*tmp;

	flag = 1;
	while (flag)
	{
		if (check(a, b, c))
			return (1);
		flag = 0;
		if ((*a)->value <= med)
			pb(a, b);
		else
			ra(a);
		tmp = *a;
		while (tmp)
		{
			if (tmp->value <= med)
				flag = 1;
			tmp = tmp->next;
		}
		(*c)++;
	}
	return (0);
}

int		ft_shaker(t_push **a, t_push **b, int mediane)
{
	int count;

	count = 0;
	if (divide_to_conquer(a, b, mediane, &count))
		return (count);
	shake_it_all(a, b, &count);
	return (count);
}