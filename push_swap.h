/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:03:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/05 16:14:34 by ncharbog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int	nb;
	struct	s_list	*prev;
	struct	s_list	*next;
}					stack_a;

int		ft_across(char *str, stack_a *root);
int		ft_atoi(char *nptr);
int		ft_count(int n);
void	*add_node(stack_a *root, int value);
stack_a	*create_stack_a(void);

#endif