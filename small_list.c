/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:14 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/19 16:06:30 by ncharbog         ###   ########.fr       */
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
			ep_rra(root);
		else if (root->next->nb < root->prev->nb)
		{
			ep_sa(root);
			ep_ra(root);
		}
	}
	else if (root->next->nb > elem2->nb && root->prev->nb > elem2->nb)
	{
		if (root->next->nb < root->prev->nb)
			ep_sa(root);
		else
			ep_ra(root);
	}
	else
	{
		ep_sa(root);
		ep_rra(root);
	}
}

void	four_elems(t_list *sa, t_list *sb)
{
	ep_pb(sa, sb);
	three_elems(sa);
	ep_pa(sa, sb);
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
