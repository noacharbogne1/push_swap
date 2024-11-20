/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:39:44 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/20 15:45:29 by ncharbog         ###   ########.fr       */
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
		add_back(root, 0);
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
