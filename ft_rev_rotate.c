/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:08:43 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/09 13:47:20 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_list **lst_a, int print)
{
	t_list	*new_last;
	t_list	*last_to_first;
	t_list	*temp;

	if (!lst_a || !(*lst_a)->next)
		return ;
	temp = *lst_a;
	last_to_first = lst_last(temp);
	new_last = lst_second_to_last(lst_a);
	last_to_first->next = (*lst_a);
	(*lst_a) = last_to_first;
	new_last->next = NULL;
	if (print == 1)
		write(1, "rra\n", 4);
}

void	ft_rrb(t_list **lst_b, int print)
{
	t_list	*new_last;
	t_list	*last_to_first;
	t_list	*temp;

	if (!lst_b || !(*lst_b)->next)
		return ;
	temp = *lst_b;
	last_to_first = lst_last(temp);
	new_last = lst_second_to_last(lst_b);
	last_to_first->next = (*lst_b);
	(*lst_b) = last_to_first;
	new_last->next = NULL;
	if (print == 1)
		write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **lst_a, t_list **lst_b)
{
	if ((!lst_a || !(*lst_a)->next) || (!lst_b) || (*lst_b)->next)
		return ;
	ft_rra(lst_a, 0);
	ft_rrb(lst_b, 0);
	write (1, "rrr\n", 4);
}
