/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:14 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/20 13:18:20 by ncharbog         ###   ########.fr       */
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
	t_list	*tmp;
	int		i;
	int		j;

	i = find_place_sa(sa, min(sa)) - 1;
	tmp = sa->next;
	j = i;
	if (i > 2)
		i = 4 - i;
	while (i > 0)
	{
		if (j > 2)
			ep_rra(sa);
		else
			ep_ra(sa);
		i--;
	}
	ep_pb(sa, sb);
	three_elems(sa);
	ep_pa(sa, sb);
}
