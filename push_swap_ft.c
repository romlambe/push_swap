/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:58:06 by romlambe          #+#    #+#             */
/*   Updated: 2023/11/29 15:53:23 by romlambe         ###   ########.fr       */
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

t_list	remplir_list(int ac, char **av)
{
	int	i;
	t_list	*lst_a;
	t_list	*temp;

	i = 0;
	lst_a = (t_list *)malloc(sizeof(t_list));
	temp = *lst_a;
	while(ac - 1 >= 0)
	{
		(temp)->content = ft_atoi(av[i]);
		temp = (temp)->next;
		ac--;
		i++;
	}
	return (*lst_a);
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

void	ft_sa(t_list **lst_a, int print)
{
	t_list *temp;

	if (!*lst_a || !(*lst_a)->next)
		return ;
	temp = *lst_a;
	*lst_a = (*lst_a)->next;
	(*lst_a)->next = temp;
	if (print == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_list **lst_b, int print)
{
	t_list *temp;

	if (!*lst_b || !(*lst_b)->next)
		return ;
	temp = *lst_b;
	*lst_b = (*lst_b)->next;
	(*lst_b)->next = temp;
	if (print == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_list **lst_a, t_list **lst_b)
{
	t_list *temp_a;
	t_list *temp_b;

	if ((!lst_b || !(*lst_b)->next) || (!lst_a || !(*lst_a)->next))
		return ;
	write(1, "ss\n", 3);
	ft_sa(lst_a, 0);
	ft_sb(lst_b, 0);

}

void	ft_pa(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!lst_a || !lst_b)
		return ;
	write(1, "pa\n", 3);
	temp = *lst_b;
	*lst_b = temp->next;
	temp->next = *lst_a;
	*lst_a= temp;
}

void	ft_pb(t_list **lst_a, t_list **lst_b)
{
	t_list	*temp;

	if (!lst_a || !lst_b)
		return ;
	write(1, "pb\n", 3);
	temp = *lst_a;
	*lst_a = temp->next;
	temp->next = *lst_b;
	*lst_b = temp;
}

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

void	ft_rra(t_list **lst_a, int print)
{
	t_list	*new_last;
	t_list	*last_to_first;

	if (!lst_a || !(*lst_a)->next)
		return ;

	last_to_first = lst_last(lst_a);
	new_last= lst_second_to_last(lst_a);

	last_to_first->next = (*lst_a);
	(*lst_a) = last_to_first;
	new_last->next = NULL;

	if (print == 1)
		write(1,"rra\n", 4);
}

void	ft_rrb(t_list **lst_b, int print)
{
	t_list	*new_last;
	t_list	*last_to_first;

	if (!lst_b || !(*lst_b)->next)
		return ;

	last_to_first = lst_last(lst_b);
	new_last= lst_second_to_last(lst_b);

	last_to_first->next = (*lst_b);
	(*lst_b) = last_to_first;
	new_last->next = NULL;

	if (print == 1)
		write(1,"rrb\n", 4);
}

void	ft_rrr(t_list **lst_a, t_list **lst_b, int print)
{
	if ((!lst_a || !(*lst_a)->next) || (!lst_b) || (*lst_b)->next)
		return ;
	ft_rra(lst_a, 0);
	ft_rrb(lst_b, 0);
	write (1, "rrr\n", 4);
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
