/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/19 08:48:03 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(t_list *sa, t_list *sb, long nb)
{
	int	i_sb;
	int	i_sa;
	int	same;

	same = 0;
	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i_sa = len_lst(sa) - find_place(sa, nb);
	if (i_sa < i_sb && i_sa > 0 && i_sb > 0)
		same = i_sa + (i_sb - i_sa);
	else if (i_sa > i_sb && i_sa > 0 && i_sb > 0)
		same = i_sb + (i_sa - i_sb);
	while (same > 0)
	{
		ep_rr(sa, sb);
		same--;
	}
	i_sb = i_sb - same;
	i_sa = i_sa - same;
	while (i_sb > 0)
	{
		ep_rb(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		ep_ra(sa);
		i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}

int	exec_rrarrb(t_list *sa, t_list *sb, long nb)
{
	int	i_sb;
	int	i_sa;
	int same;

	same = 0;
	i_sb = positioning_sb(nb, sb);
	i_sa = find_place(sa, nb);
	if (i_sa < i_sb && i_sa > 0 && i_sb > 0)
		same = i_sa + (i_sb - i_sa);
	else if (i_sa > i_sb && i_sa > 0 && i_sb > 0)
		same = i_sb + (i_sa - i_sb);
	while (same > 0)
	{
		ep_rrr(sa, sb);
		same--;
	}
	i_sb = i_sb - same;
	i_sa = i_sa - same;
	while (i_sb > 0)
	{
		ep_rrb(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		ep_rra(sa);
		i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}

int	exec_rrarb(t_list *sa, t_list *sb, long nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i_sa = find_place(sa, nb);
	while (i_sb > 0)
	{
		ep_rb(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		ep_rra(sa);
		i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}

int	exec_rarrb(t_list *sa, t_list *sb, long nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	i_sa = len_lst(sa) - find_place(sa, nb);
	while (i_sb > 0)
	{
		ep_rrb(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		ep_ra(sa);
		i_sa--;
	}
	ep_pb(sa, sb);
	return (-1);
}
