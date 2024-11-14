/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:52:05 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/14 16:10:49 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	exec_rarb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;
	int	i_sa;

	i_sb = len_lst(sb) - positioning_sb(nb, sb) - 1;
	i_sa = count - i_sb;
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
int	exec_rrarrb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	i_sa = count - i_sb;
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
int	exec_rrarb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;
	int	i_sa;

	i_sb = len_lst(sb) - positioning_sb(nb, sb) - 1;
	i_sa = count - i_sb;
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
int	exec_rarrb(t_list *sa, t_list *sb, int nb, int count)
{
	int	i_sb;
	int	i_sa;

	i_sb = positioning_sb(nb, sb);
	i_sa = count - i_sb;
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
