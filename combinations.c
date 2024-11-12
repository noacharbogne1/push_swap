/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combinations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 11:25:47 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/12 15:29:21 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_combination(t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;

	tmp = sa->prev;
	i = combination_rarb(tmp->nb, sa, sb);
	while (tmp != sa)
	{
		if (i > combination_rarb(tmp->nb, sa, sb))
			i = combination_rarb(tmp->nb, sa, sb);
		if (i > combination_rrarrb(tmp->nb, sa, sb))
			i = combination_rrarrb(tmp->nb, sa, sb);
		if (i > combination_rrarb(tmp->nb, sa, sb))
			i = combination_rrarb(tmp->nb, sa, sb);
		if (i > combination_rarrb(tmp->nb, sa, sb))
			i = combination_rarrb(tmp->nb, sa, sb);
		tmp = tmp->prev;
	}
	return (i);
}

int	combination_rarb(int nb, t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb, 1);
	i = 0;
	tmp = sa->prev;
	while (tmp->nb != nb)
	{
		i++;
		tmp = tmp->prev;
	}
	if (i < i_sb)
		i = i + (i_sb - i);
	else if (i > i_sb)
		i = i_sb + (i - i_sb);
	return (i);
}
int	combination_rrarrb(int nb, t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb, 2);
	i = 0;
	tmp = sa;
	while (tmp->nb != nb)
	{
		i++;
		tmp = tmp->next;
	}
	if (i < i_sb)
		i = i + (i_sb - i);
	if (i > i_sb)
		i = i_sb + (i - i_sb);
	return (i);
}
int	combination_rrarb(int nb, t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb, 1);
	i = 0;
	tmp = sa;
	while (tmp->nb != nb)
	{
		i++;
		tmp = tmp->next;
	}
	i = i + i_sb;
	return (i);
}
int	combination_rarrb(int nb, t_list *sa, t_list *sb)
{
	t_list	*tmp;
	int		i;
	int		i_sb;

	i_sb = positioning_sb(nb, sb, 2);
	i = 0;
	tmp = sa->prev;
	while (tmp->nb != nb)
	{
		i++;
		tmp = tmp->prev;
	}
	i = i + i_sb;
	return (i);
}
