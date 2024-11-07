/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncharbog <ncharbog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:03:39 by ncharbog          #+#    #+#             */
/*   Updated: 2024/11/07 13:56:22 by ncharbog         ###   ########.fr       */
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
}					t_list;

int		ft_across(char *str, t_list *root);
int		ft_atoi(char *nptr);
int		ft_count(int n);
int		len_lst(t_list *root);
int		check_order(t_list *root);
void	ft_free(t_list **root);
void	*add_node(t_list *root, int value);
t_list	*create_list(void);
void	push(t_list *from, t_list *to);
void    swap(t_list *root);
void	rotate(t_list *root);
void	reverse_rotate(t_list *root);
void	del_node(t_list *element);

#endif