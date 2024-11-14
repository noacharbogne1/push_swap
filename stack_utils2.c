/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:11:12 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/14 10:23:53 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	len_lst(t_list *root)
{
	int		len;
	t_list	*tmp;

	len = 0;
	tmp = root;
	if (tmp->next == root)
		return (1);
	while (tmp->next != root)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	min(t_list *root)
{
	t_list *tmp;
	int		min;

	min = 2147483647;
	tmp = root->next;
	while (tmp != root)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

int max(t_list *root)
{
	t_list *tmp;
	int		max;

	max = -2147483648;
	tmp = root->next;
	while (tmp != root)
	{
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}
