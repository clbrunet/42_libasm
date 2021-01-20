/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:11:49 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/19 15:34:04 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TEST_H
# define LIBASM_TEST_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>

# ifndef BONUS_PRESENT
#  define BONUS_PRESENT 0
# endif

# if BONUS_PRESENT
#  include "libasm_bonus.h"
# else
#  include "libasm.h"
# endif

# define RESET		"\x1B[0m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGENTA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"
# define BOLD		"\x1B[1m"

# define TRUE		1
# define FALSE		0
# define ERROR		-1
# define SUCCESS	0
# define FAILURE	1

# ifndef FT_STRLEN
#  define FT_STRLEN 0
# endif
# ifndef FT_STRCPY 
#  define FT_STRCPY 0
# endif
# ifndef FT_STRCMP 
#  define FT_STRCMP 0
# endif
# ifndef FT_WRITE 
#  define FT_WRITE 0
# endif
# ifndef FT_READ 
#  define FT_READ 0
# endif
# ifndef FT_STRDUP 
#  define FT_STRDUP 0
# endif
# ifndef FT_ATOI_BASE 
#  define FT_ATOI_BASE 0
# endif
# ifndef FT_LIST_PUSH_FRONT 
#  define FT_LIST_PUSH_FRONT 0
# endif
# ifndef FT_LIST_SIZE 
#  define FT_LIST_SIZE 0
# endif
# ifndef FT_LIST_SORT 
#  define FT_LIST_SORT 0
# endif
# ifndef FT_LIST_REMOVE_IF
#  define FT_LIST_REMOVE_IF	0
# endif

typedef struct s_args
{
	char	all;
	char	bonus;
	char	verbose;
	char	help;
	char	strlen;
	char	strcpy;
	char	strcmp;
	char	write;
	char	read;
	char	strdup;
	char	atoi_base;
	char	list_push_front;
	char	list_size;
	char	list_sort;
	char	list_remove_if;
}			t_args;

# if BONUS_PRESENT
int		ft_atoi_base_c_piscine(char *str, char *base);
t_list	*ft_lstnew(void *data);
int		ft_list_size_libft(t_list *begin_list);
void	ft_list_push_front_libft(t_list **begin_list, void *data);
void	ft_lstclear(t_list **lst, void (*del)(void *));
# endif

void	print_result(char ko);

int		parse_av(int ac, char **av, t_args *args);

void	test_ft_strlen(t_args *args);
void	test_ft_strcpy(t_args *args);
void	test_ft_strcmp(t_args *args);
void	test_ft_strdup(t_args *args);
void	test_ft_write(t_args *args);
void	test_ft_read(t_args *args);

void	test_ft_atoi_base(t_args *args);
void	test_ft_list_size(t_args *args);
void	test_ft_list_push_front(t_args *args);
void	test_ft_list_sort(t_args *args);
void	test_ft_list_remove_if(t_args *args);

#endif
