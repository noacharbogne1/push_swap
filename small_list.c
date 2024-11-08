/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:14 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/08 19:57:25 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_list *root)
{
	t_list	*elem1;
	t_list	*elem2;
	t_list	*elem3;

	elem1 = root->next;
	elem2 = elem1->next;
	elem3 = root->prev;
	if (check_order(root) == 1)
		return ;
	if (elem1->nb < elem2->nb && elem3->nb < elem2->nb)
	{
		if (elem1->nb > elem3->nb)
			rotate(root);
		if (elem1->nb < elem3->nb)
			swap(root);
	}
	else if (elem1->nb > elem2->nb && elem3->nb > elem2->nb)
	{
		reverse_rotate(root);
		if (elem1->nb < elem3->nb)
			swap(root);
	}
	else
	{
		rotate(root);
		swap(root);
	}
}

void	four_elems(t_list *sa, t_list *sb)
{
	push(sa, sb);
	three_elems(sa);
	push(sb, sa);
	if (sa->prev->nb < sa->next->nb)
		rotate(sa);
	if (sa->prev->nb < sa->next->next->nb)
	{
		reverse_rotate(sa);
		swap(sa);
		rotate(sa);
		rotate(sa);
	}
	if (sa->prev->nb < sa->prev->prev->nb)
		swap(sa);
}

void	five_elems(t_list *sa, t_list *sb)
{
	push(sa, sb);
	push(sa, sb);
	three_elems(sa);
	if (sb->next->nb < sa->prev->nb)
	{
		swap(sb);
		push(sb, sa);
	}
	else
		push(sb, sa);
	push(sb, sa);
	if (sa->prev->nb < sa->next->nb)
		rotate(sa);
	if (sa->prev->nb < sa->next->next->nb)
	{
		reverse_rotate(sa);
		swap(sa);
		rotate(sa);
		rotate(sa);
	}
	if (sa->prev->nb < sa->prev->prev->nb)
		swap(sa);
}
