/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:06 by romlambe          #+#    #+#             */
/*   Updated: 2023/12/11 15:41:51 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 0;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i + 1] == '-')
			return (0);
		if (str[i] == '-')
			sign -= 1;
		i++;
	}
	while(str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}
t_list	*new_node(void *content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
t_list	*fill_list(t_list **lst, int ac, char **av)
{
	t_list	*temp;
	t_list	*new;
	int		i;

	if (!(*lst) || !lst)
		return ;
	i = 0;
	temp = *lst;
	while (ac - 1 > 0)
	{
		temp = new_node(ft_atoi(av[i]));
		lst_add_back(lst, new);
		temp = temp->next;
		ac--;
		i++;
	}
	return (*lst);
}

//algo simple

// while (!est_triee(pa) || pa != NULL)
// {
// 	int lpp = le_plus_petit(ra);
// 	int nb_ra = ft_nb_ra(pa);
// 	int nb_rra = ft_nb_rra(pa);
// 	if nb_ra > nb_rra
// 		while(nb_ra != 0)
// 			ra;
// 			nb_ra--;
// 	if nb_rra >= nb_ra
// 		while (nb_rra != 0)
// 			rra;
// 			nb_rra != 0;
// }
