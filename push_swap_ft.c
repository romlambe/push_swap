/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:06 by romlambe          #+#    #+#             */
/*   Updated: 2023/12/06 12:16:11 by romlambe         ###   ########.fr       */
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
int	lst_size(t_list *lst)
{
	int i;

	i = 0;
	if (!lst)
		return 0;
	while(lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_list	*lst_last(t_list **lst)
{
	t_list	*temp;

	temp = *lst;
	if (!lst)
		return (NULL);
	while (temp->next)
		temp = temp->next;
	return (temp);
}
t_list	*lst_second_to_last(t_list **lst)
{
	t_list	*temp;

	temp = (*lst);
	if (!lst || !(*lst)->next)
		return (NULL);
	while ((temp)->next->next != NULL)
		temp = temp->next;
	return (temp);
}

void    add_node(t_list **lst, int content)
{
    t_list    *new_node;
    t_list    *temp;

    new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node)
        return ;
    new_node->content = content;
    new_node->index = -1;
    new_node->next = NULL;
    if (*lst == NULL) // Si rien dans la liste
        *lst = new_node;
    else // S'il y a deja des noeuds dans la liste.
    { // On parcourt la liste et on ajoute le new node a la fin.
        temp = *lst;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new_node;
    }
}

void    print_lst(const t_list *lst)
{
    const t_list    *current;

    current = lst;
    if (!lst)
        return ;
    while (current != NULL)
    {
        printf("%d (%d)\n", current->content, current->index);
        current = current->next;
    }
}

#include <stdlib.h>

int    main(void)
{
    t_list    *lst = NULL;

    add_node(&lst, -5);
    add_node(&lst, 3);
    add_node(&lst, 13);
    add_node(&lst, 10);
    add_node(&lst, 24);
    add_node(&lst, 16);
    add_node(&lst, 18);
    add_node(&lst, 9);


	printf("\nVoici la liste avant les modifications : \n");
    print_lst(lst);

    ft_ra(&lst, 1);


    printf("\nVoici la liste apres les modifications : \n");
    print_lst(lst);
    return (0);
}


// Pour compter ra

int	count_ra(t_list **lst, int content)
{
	int		count;
	t_list	*temp;
	if(!(*lst) || !lst )
		return (0);
	count = -1;
	temp = *lst;
	while(temp->content != content)
	{
		count++;
		temp = temp->next;
	}
	return(count);
}

int	count_rra(t_list **lst, int content)
{
	int		count;
	int		size;
	int		res;
	t_list	*temp;

	if (!(*lst) || !lst)
		return(0);
	count = 0;
	size = lst_size(lst);
	temp = *lst;
	while(temp->next != content)
	{
		count++;
		temp = temp->next;
	}
	return(res = (size - count) + 1);
}
t_list	*swap_2_numbers(t_list **lst, t_list *index)
{
	ft_index(lst);
	if ((*lst)->index > (*lst)->next->index) //lst->next->index
		sa(lst);
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
