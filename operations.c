/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:05 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/07 14:09:56 by ncharbog         ###   ########.fr       */
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

void	reverse_rotate(t_list *root)
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
