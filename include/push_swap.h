/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romlambe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 13:48:34 by romlambe          #+#    #+#             */
/*   Updated: 2024/01/09 13:58:25 by romlambe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "unistd.h"
# include "stdlib.h"
# include <stdio.h>
# include <limits.h>

typedef	struct	s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}				t_list;

typedef	struct	s_data
{
	int	median;
	int	size;
	int	start;
	int	end;
	int	n;
	int	t_num;
	int	unorder_num;
	int	max;
}				t_data;

// Instructions
void	ft_sa(t_list **lst_a, int print);
void	ft_sb(t_list **lst_b, int print);
void	ft_ss(t_list **lst_a, t_list **lst_b);
void	ft_pa(t_list **lst_a, t_list **lst_b);
void	ft_pb(t_list **lst_a, t_list **lst_b);
void	ft_ra(t_list **lst_a, int print);
void	ft_rb(t_list **lst_b, int print);
void	ft_rr(t_list **lst_a, t_list **lst_b);
void	ft_rra(t_list **lst_a, int print);
void	ft_rrb(t_list **lst_b, int print);
void	ft_rrr(t_list **lst_a, t_list **lst_b);

// Utils

void	sort_stack_a_to_b(t_list **lsta, t_list **lstb, int *array, t_data *data);
void	sort_stack_b_to_a(t_list **lsta, t_list **lstb, int *array, t_data *data);
void	check_highest_nb(t_list **lsta, t_list **lstb, int *array, t_data *data);
void	check_unsorted_nb(t_list **lsta, t_data *data);
void	check_not_max_num(t_list **lsta, t_list **lstb, t_data *data);
int	is_digit(const char *str);
int	available_size(long long digit);
long long	atoi_conversion(char *str);
int	ft_atoi_ps(char *str);
void    add_node(t_list **lst, int content);
void	sort_lst(t_list **lsta, t_list **lstb, int *array, t_data *data);
int	is_sorted(t_list **lst);
void	bubble_sort(int *array, int size);
int	*sort_array(t_list *lst);
int	check_doubles(t_list *lst);
char	*ft_strdup_ps(char *str);
t_list	*new_node(int content);
char	**ft_convert_format(int ac, char **av);
t_list	*fill_list(t_list **lst, int ac, char **av);
t_list *find_highest_node(t_list *lst);
void	both_lowest_at_bottom(t_list **lst);
char	*ft_strncpy(char *dest, const char *src, int size);
int	count_words(char *str);
void	check_string(char **new, char *str);
char	**ft_split(char *str);
int	size_array(char **array);
t_list *find_smallest_index(t_list **lsta);
t_list	*find_second_smallest_index(t_list **lst);
int	find_highest_nb(t_list *lst);
int	find_highest_index(t_list *lst, int max);
int	lst_size(t_list **lst);
t_list	*lst_last(t_list *lst);
t_list	*lst_second_to_last(t_list **lst);
void	lst_add_back(t_list **lst, t_list *new);
int	ft_strlen_ps(char *str);

// Free

void	del_nodes(t_list **lst);
void	free_array(char **array);

// Sorting

void	swap_2_numbers(t_list **lst);
void	sort_3_numbers(t_list **lst);
void	swap_5_numbers(t_list **lsta, t_list **lstb);




#endif
