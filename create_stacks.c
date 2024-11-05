/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stacks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:59:12 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/05 16:26:05 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_a	*create_stack_a(void)
{
	stack_a	*root;

	root = malloc(sizeof(stack_a));
	if (!root)
		return (NULL);
	root->prev = root;
	root->next = root;
	return (root);
}

void	*add_node(stack_a *root, int value)
{
	stack_a	*new;

	new = malloc(sizeof(stack_a));
	if (!new)
		return (0);
	new->nb = value;
	new->prev = root->prev;
	new->next = root;
	root->prev->next = new;
	root->prev = new;
	return (new);
}
