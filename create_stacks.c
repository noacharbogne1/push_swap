/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:59:12 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/06 15:36:07 by noacharbogn      ###   ########.fr       */
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
	return (root);
}

void	*add_node(t_list *root, int value)
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