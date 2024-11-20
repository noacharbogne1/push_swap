/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:33:55 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/20 16:12:14 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	prepare_sorting(t_list *sa, t_list *sb)
{
	if (check_order(sa))
			return (0);
	if (len_lst(sa) == 2)
		ep_sa(sa);
	else if (len_lst(sa) == 3)
		three_elems(sa);
	else if (len_lst(sa) == 4)
		four_elems(sa, sb);
	else if (len_lst(sa) > 4)
	{
		sort_list(sa, sb);
		place_in_a(sa, sb);
	}
	return (1);
}

int	write_error(t_list *sa, t_list *sb)
{
	write(2, "Error\n", 6);
	ft_free(&sa);
	ft_free(&sb);
	return (0);
}