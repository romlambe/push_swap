/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:59:17 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/09 13:50:21 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lsta;
	t_list	*lstb;
	t_data	data;
	char	**result;
	int		*tab;

	lsta = NULL;
	lstb = NULL;
	result = NULL;
	if (ac < 2 || !av[1][0])
		return (-1);
	if (ac == 2)
	{
		result = ft_split(av[1]);
		ac = size_array(result);
	}
	else
		result = ft_convert_format(ac, av);
	if (fill_list(&lsta, ac, result) ==  NULL)
		return(-1);
	tab = sort_array(lsta);
	sort_lst(&lsta, &lstb, tab, &data);
	del_nodes(&lsta);
	free(tab);
	return 0;
}
