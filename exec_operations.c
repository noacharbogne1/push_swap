/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/15 12:51:46 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(t_list *sa, t_list *sb, int nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i_sa = len_lst(sa) - find_place(sa, nb);
	while (i_sb > 0)
	{
		rotate(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		rotate(sa);
		i_sa--;
	}
	push(sa, sb);
	return (-1);
}

int	exec_rrarrb(t_list *sa, t_list *sb, int nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	i_sa = find_place(sa, nb);
	//if (i_sa > 1)
		//i_sa = i_sa - 1;
	while (i_sb > 0)
	{
		reverse_rotate(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		reverse_rotate(sa);
		i_sa--;
	}
	push(sa, sb);
	return (-1);
}

int	exec_rrarb(t_list *sa, t_list *sb, int nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	if (i_sb == len_lst(sb))
		i_sb = 0;
	if (i_sb != 0)
		i_sb = len_lst(sb) - i_sb;
	i_sa = find_place(sa, nb);
	//if (i_sa > 1)
		//i_sa = i_sa - 1;
	while (i_sb > 0)
	{
		rotate(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		reverse_rotate(sa);
		i_sa--;
	}
	push(sa, sb);
	return (-1);
}

int	exec_rarrb(t_list *sa, t_list *sb, int nb)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	i_sa = len_lst(sa) - find_place(sa, nb);
	//if (i_sa > 1)
	//	i_sa = i_sa - 1;
	while (i_sb > 0)
	{
		reverse_rotate(sb);
		i_sb--;
	}
	while (i_sa > 0)
	{
		rotate(sa);
		i_sa--;
	}
	push(sa, sb);
	return (-1);
}
