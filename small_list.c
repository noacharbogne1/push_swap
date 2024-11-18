/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:14 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/18 17:20:59 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_list *root)
{
	t_list	*elem2;

	elem2 = root->next->next;
	if (check_order(root) == 1)
		return ;
	if (root->next->nb < elem2->nb && root->prev->nb < elem2->nb)
	{
		if (root->next->nb > root->prev->nb)
			ep_ra(root);
		else if (root->next->nb < root->prev->nb)
			ep_sa(root);
	}
	else if (root->next->nb > elem2->nb && root->prev->nb > elem2->nb)
	{
		ep_rra(root);
		if (root->next->nb < root->prev->nb)
			ep_sa(root);
	}
	else
	{
		ep_ra(root);
		ep_sa(root);
	}
}

void	four_elems(t_list *sa, t_list *sb)
{
	ep_pb(sa, sb);
	three_elems(sa);
	ep_pb(sa, sb);
	if (sa->prev->nb < sa->next->nb)
		ep_ra(sa);
	if (sa->prev->nb < sa->next->next->nb)
	{
		ep_rra(sa);
		ep_sa(sa);
		ep_ra(sa);
		ep_ra(sa);
	}
	if (sa->prev->nb < sa->prev->prev->nb)
		ep_sa(sa);
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
