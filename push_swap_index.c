/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:51:43 by romlambe          #+#    #+#             */
/*   Updated: 2023/12/11 16:39:24 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_list	*find_smallest_node(t_list **lst)
{
	t_list *min;
	t_list *temp;

	min = NULL;
	temp = *lst;
	while (temp)
	{
		if(temp->index == -1 && (min == NULL || temp->content < min->content))
			min = temp;
		temp = temp->next;
	}
	return (min);
}

t_list	*define_index(t_list **lst)
{
	t_list	*min;
	int		index;

	index = 1;
	while(1)
	{
		min = find_smallest_node(lst);
		if (min == NULL)
			return (NULL);
		min->index = index;
		index++;
	}
	return (min);
}
t_list	*swap_2_numbers(t_list **lst, int index)
{
	define_index(lst);
	if ((*lst)->index > index)
		ft_sa(lst, 1);
	return (*lst);
}

t_list *swap_3_numbers(t_list **lst)
{
	int	first_index;
	int	second_index;
	int	third_index;

	define_index(lst);
	first_index = (*lst)->index;
	second_index = (*lst)->next->index;
	third_index = (*lst)->next->next->index;
	if (first_index == 1 && second_index == 3 && third_index == 2)
	{
		ft_ra(lst, 1);
		ft_sa(lst, 1);
		ft_rra(lst, 1);
	}
	if (first_index == 2 && second_index == 1 && third_index == 3)
		ft_sa(lst, 1);
	if (first_index == 2 && second_index == 3 && third_index == 1)
		ft_rra(lst, 1);
	if (first_index == 3 && second_index == 1 && third_index == 2)
		ft_ra(lst, 1);
	if (first_index == 1 && second_index == 3 && third_index == 2)
	{
		ft_sa(lst, 1);
		ft_rra(lst, 1);
	}
	if (first_index == 3 && second_index == 2 && third_index == 1)
	{
		ft_sa(lst, 1);
		ft_rra(lst, 1);
	}
	return (*lst);
}

t_list	*swap_5_numbers(t_list **lsta, t_list **lstb)
{
	t_list	*temp;

	if (!lsta || !(*lsta))
		return (NULL);
	temp = *lsta;
	define_index(&temp);
	while(temp)
	{
		if (temp->index == 1)
			ft_pb(lsta, lstb);
		if (temp->index == 2)
			ft_pb(lsta, lstb);
		temp = temp->next;
	}
	swap_3_numbers(lsta);
	ft_pa(lsta, lstb);
	ft_pa(lsta, lstb);
	return (*lsta);
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
    if (*lst == NULL)
        *lst = new_node;
    else
    {
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
int    main(void)
{
    t_list    *lsta = NULL;
    t_list    *lstb = NULL;

	add_node(&lsta, 5);
	add_node(&lsta, 3);
	add_node(&lsta, 2);
    add_node(&lsta, 4);
    add_node(&lsta, 7);
    // add_node(&lsta, 9);

    printf("Voici la liste : \n");
    print_lst(lsta);
    printf("\n");
	//swap_2_numbers(&lsta,lsta->next->index);
	swap_5_numbers(&lsta, &lstb);
    printf("\nVoici la liste apres les modifications : \n");
    print_lst(lsta);
    write(1, "\n", 1);
    return (0);
}
