/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:39:44 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 14:54:27 by ncharbog         ###   ########.fr       */
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

long	min(t_list *root)
{
	t_list *tmp;
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
	t_list *tmp;
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

int	ft_iszero(char *str, t_list *root)
{
	int	i;
	int	result;

	i = 0;
	result = 18;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result != 180 || ft_check_dup(0, root))
		return (-1);
	if (str[i] >= '0' && str[i] <= '9')
		return (-1);
	else
		add_node(root, 0);
	return (i);
}
