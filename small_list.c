/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:14 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/20 18:11:30 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_elems(t_list *root)
{
	if (root->next->nb < root->next->next->nb && root->prev->nb
		< root->next->next->nb)
	{
		if (root->next->nb > root->prev->nb)
			ep_rra(root);
		else if (root->next->nb < root->prev->nb)
		{
			ep_sa(root);
			ep_ra(root);
		}
	}
	else if (root->next->nb > root->next->next->nb && root->prev->nb
		> root->next->next->nb)
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
	int		i;
	int		j;

	i = find_place_sa(sa, min(sa)) - 1;
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
