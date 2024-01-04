/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:25:51 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/04 16:29:41 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_last(t_list **lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

t_list	*lst_second_to_last(t_list **lst)
{
	t_list	*temp;

	if (!lst || !(*lst)->next)
		return (NULL);
	temp = *lst;
	while ((temp)->next->next != NULL)
		temp = temp->next;
	return (temp);
}

int	lst_size(t_list **lst)
{
	int	i;
	t_list *temp;

	i = 0;
	temp = *lst;
	if (!temp)
		return (0);
	while (temp)
	{
		i++;
		temp = (temp)->next;
	}
	return (i);
}
