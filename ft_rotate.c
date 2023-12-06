/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:08:05 by romlambe          #+#    #+#             */
/*   Updated: 2023/12/04 16:52:01 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_list **lst_a, int print)
{
	t_list	*first_to_last;
	t_list	*second_to_last;

	if (!lst_a || !(*lst_a)->next)
		return ;
	first_to_last = (*lst_a);
	second_to_last = lst_last(lst_a);
	(*lst_a) = first_to_last->next;
	second_to_last->next = first_to_last;
	first_to_last->next = NULL;
	if (print == 1)
		write(1, "ra\n", 3);
}

void	ft_rb(t_list **lst_b, int print)
{
	t_list	*first_to_last;
	t_list	*second_to_last;

	if (!lst_b || !(*lst_b)->next)
		return ;
	first_to_last = (*lst_b);
	second_to_last = lst_last(lst_b);
	(*lst_b) = first_to_last;
	second_to_last->next = first_to_last;
	first_to_last->next = NULL;
	if (print == 1)
		write(1, "rb\n", 3);
}

void	ft_rr(t_list **lst_a, t_list **lst_b, int print)
{
	if ((!lst_a || !(*lst_a)->next) || (!lst_b || !(*lst_b)->next))
		return ;
	ft_ra(lst_a, 0);
	ft_rb(lst_b, 0);
	write(1, "rr\n", 3);
}