/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:44:03 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/21 10:18:12 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	min(t_list *root)
{
	t_list	*tmp;
	long	min;

	min = 2147483648;
	tmp = root->next;
	while (tmp != root)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	return (min);
}

long	max(t_list *root)
{
	t_list	*tmp;
	long	max;

	max = -2147483649;
	tmp = root->next;
	while (tmp != root)
	{
		if (max < tmp->nb)
			max = tmp->nb;
		tmp = tmp->next;
	}
	return (max);
}
