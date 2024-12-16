/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:39:44 by ncharbog          #+#    #+#             */
/*   Updated: 2024/12/16 11:17:07 by ncharbog         ###   ########.fr       */
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

int	ft_iszero(char *str, t_list *sa, t_list *sb)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	if (str && (*str == '+' || *str == '-'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result == 0 && (str[i] == ' ' || str[i] == '\0')
		&& ft_check_dup(result, sa) == 0)
	{
		add_back(sa, result);
		return (i);
	}
	if ((str[i] == ' ' || str[i] == '\0') && ft_check_dup(result, sa) == 0)
	{
		errors_result(sa, sb, result);
		add_back(sa, result);
		return (i);
	}
	return (-1);
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
