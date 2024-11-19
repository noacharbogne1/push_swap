/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:05 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/19 15:48:58 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *root)
{
	t_list	*head;
	t_list	*next;
	long	tmp;

	head = root->next;
	next = head->next;
	if (!head || !next)
		return ;
	tmp = head->nb;
	head->nb = next->nb;
	next->nb = tmp;
	head->next = next;
	head->prev = root;
	next->prev = head;
	if (root)
		root->next = head;
}

void	push(t_list *from, t_list *to)
{
	t_list	*top_from;
	long	content;

	if (!from || !to)
		return ;
	top_from = from->next;
	content = top_from->nb;
	add_front(to, content);
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
	root->prev = first;
	root->next = first->next;
	first->next = root;
	root->next->prev = root;
	last->next = first;
	first->prev = last;
}

void	reverse_rotate(t_list *root)
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
