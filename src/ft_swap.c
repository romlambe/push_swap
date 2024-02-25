/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:06:44 by romlambe          #+#    #+#             */
/*   Updated: 2024/02/21 17:02:24 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_list **lst_a, int print)
{
	t_list	*temp;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	temp = *lst_a;
	*lst_a = temp->next;
	temp->next = (*lst_a)->next;
	(*lst_a)->next = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **lst_b, int print)
{
	t_list	*temp;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	temp = *lst_b;
	*lst_b = temp->next;
	temp->next = (*lst_b)->next;
	(*lst_b)->next = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	if (!(*lst_a) || !(*lst_b))
		return ;
	write(1, "ss\n", 3);
	ft_sa(lst_a, 0);
	ft_sb(lst_b, 0);
}

void	ft_pa(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!(*lstb))
		return ;
	write(1, "pa\n", 3);
	temp = (*lstb);
	(*lstb) = (*lstb)->next;
	temp->next = (*lsta);
	(*lsta) = temp;
}

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!*lst_a)
		return ;
	write(1, "pb\n", 3);
	temp = (*lst_a);
	(*lst_a) = (*lst_a)->next;
	temp->next = (*lst_b);
	(*lst_b) = temp;
}
