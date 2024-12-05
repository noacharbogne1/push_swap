/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:39:44 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/05 14:35:04 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(t_list *sa, t_list *sb)
{
	ft_free(&sa);
	ft_free(&sb);
	return (0);
}

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

int	ft_iszero(char *str, t_list *root)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (ft_check_dup(0, root))
		return (-1);
	add_back(root, result * sign);
	return (i);
}

void	add_front(t_list *root, long content)
{
	t_list	*new;

	if (!root)
		return ;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->nb = content;
	if (root->next == root)
	{
		root->next = new;
		root->prev = new;
		new->next = root;
		new->prev = root;
	}
	else
	{
		new->next = root->next;
		new->prev = root;
		root->next->prev = new;
		root->next = new;
	}
}
