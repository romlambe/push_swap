/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:13:31 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/06 18:17:22 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	lst_add_back(t_list **lst, t_list *new)
{
	t_list	*last;
	if (!lst)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		last = lst_last(*lst);
		last->next = new;
	}
}

int	ft_strlen_ps(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
