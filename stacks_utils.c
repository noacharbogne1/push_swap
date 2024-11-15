/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:43:37 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/15 14:36:06 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(void)
{
	t_list	*root;

	root = malloc(sizeof(t_list));
	if (!root)
		return (NULL);
	root->prev = root;
	root->next = root;
	root->nb = 2147483649;
	return (root);
}

void	*add_node(t_list *root, long value)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->nb = value;
	if (root->next == root)
	{
		root->next = new;
		root->prev = new;
		new->next = root;
		new->prev = root;
	}
	else
	{
		new->prev = root->prev;
		new->next = root;
		root->prev->next = new;
		root->prev = new;
	}
	return (new);
}

void	del_node(t_list *element)
{
	element->prev->next = element->next;
	element->next->prev = element->prev;
	free(element);
}

void	ft_free(t_list **root)
{
	t_list	*tmp;
	t_list	*next;

	if (*root == NULL)
		return ;
	tmp = *root;
	if (tmp->next == (*root))
	{
		free(tmp);
		*root = NULL;
		return ;
	}
	next = tmp->next;
	while (next != (*root))
	{
		tmp = next;
		next = tmp->next;
		free(tmp);
	}
	free(*root);
	*root = NULL;
}

int	check_order(t_list *root)
{
	t_list	*tmp;

	tmp = root;
	if (tmp->next == tmp)
		return (1);
	while (tmp)
	{
		if (tmp->nb < tmp->next->nb)
		{
			tmp = tmp->next;
			if (tmp->next == root)
				return (1);
		}
		else
			return (0);
	}
	return (0);
}
