/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noacharbogne <noacharbogne@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:20:05 by noacharbogn       #+#    #+#             */
/*   Updated: 2024/11/06 11:59:53 by noacharbogn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_swap_a(stack_a *root)
{
    stack_a *head;
    stack_a *prev;
    int tmp;

    head = root->prev;
    prev = head->prev;
    tmp = head->nb;
    head->nb = prev->nb;
    prev->nb = tmp;
    prev->next = head;
    head->prev = prev;
    head->next = root;
    prev->prev = root->prev;
    root->prev = prev;
}
