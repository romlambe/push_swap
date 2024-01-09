/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:27:03 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/09 13:58:21 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_doubles(t_list *lst)
{
	t_list	*temp;
	t_list	*next_node;
	int		doubles;

	doubles = 0;
	temp = lst;
	while (temp)
	{
		next_node = temp->next;
		while (next_node)
		{
			if (next_node->content == temp->content)
				doubles = 1;
			next_node = next_node->next;
		}
		temp = temp->next;
	}
	if (doubles == 1)
	{
		del_nodes(&lst);
		write (1, "Error", 6);
		return (-1);
	}
	return (0);
}

char	*ft_strdup_ps(char *str)
{
	char	*dest;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen_ps(str);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

t_list	*new_node(int content)
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	if (!lst)
		return (NULL);
	lst->content = content;
	lst->index = -1;
	lst->next = NULL;
	return (lst);
}

char	**ft_convert_format(int ac, char **av)
{
	int		i;
	char	**res;

	i = 0;
	res = (char **)malloc(sizeof(char *) * (ac + 1));
	if (!res)
		return (NULL);
	res[ac - 1] = NULL;
	while (i < ac - 1)
	{
		res[i] = ft_strdup_ps(av[i + 1]);
		if (!res[i])
			return (free_array(res), NULL);
		i++;
	}
	return (res);
}

t_list	*fill_list(t_list **lst, int ac, char **av)
{
	int		i;
	int		num;
	t_list	*new;

	i = 0;
	while (ac > 1)
	{
		num = ft_atoi_ps(av[i]);
		if (num == -1)
			return (free_array(av), del_nodes(lst), NULL);
		new = new_node(num);
		lst_add_back(lst, new);
		ac--;
		i++;
	}
	if (check_doubles(*lst) == -1)
		return(free_array(av), NULL);
	i = 0;
	free_array(av);
	return (*lst);
}
