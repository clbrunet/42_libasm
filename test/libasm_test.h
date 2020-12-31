/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm_test.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:11:49 by clbrunet          #+#    #+#             */
/*   Updated: 2020/12/26 15:28:28 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_TEST_H
# define LIBASM_TEST_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>

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
}			t_args;

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

void	print_result(char ko);

int		parse_av(int ac, char **av, t_args *args);

void	test_strlen(t_args *args);
void	test_strcpy(t_args *args);
void	test_strcmp(t_args *args);

#endif
