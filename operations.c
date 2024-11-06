/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:05 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/06 16:38:11 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *root)
{
	t_list *head;
	t_list *prev;
	int		tmp;

	head = root->prev;
	prev = head->prev;
	if (!head | !prev)
		return ; 
	tmp = head->nb;
	head->nb = prev->nb;
	prev->nb = tmp;
	prev->next = head;
	head->prev = prev;
	head->next = root;
	prev->prev = root->prev;
	root->prev = prev;
}

void	push(t_list *from, t_list *to)
{
	t_list	*top_from;
	int		content;
	
	if (!from | !to)
		return ;
	top_from = from->prev;
	content = top_from->nb;
	add_node(to, content);
	del_node(top_from);
}

void	rotate(t_list *root)
{
	t_list	*first;
	t_list	*last;

	if (!root)
		return ;
	first = root->next;
	last = root->prev;
	root->next = last;
	root->prev = last->prev;
	last->prev = root;
	root->prev->next = root;
	last->next = first;
	first->prev = last;
}