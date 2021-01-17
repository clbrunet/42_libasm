/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:30:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/17 16:49:34 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_WRITE

static char	check_written_texts_diffs_error(void *ft_buf, char *buf)
{
	free(ft_buf);
	free(buf);
	fflush(stdout);
	if (!buf || !ft_buf)
		dprintf(2, RED "\tmalloc() failed\n" RESET);
	else
		dprintf(2, RED "\tread() failed\n" RESET);
	return (ERROR);
}

static char	check_returns_diffs(int fd, void const *buf, size_t len, ssize_t *ret)
{
	char	ko;
	int		ft_errno;

	lseek(fd, 0, SEEK_SET);
	*ret = ft_write(fd, buf, len);
	ft_errno = 0;
	if (*ret == ERROR)
		ft_errno = errno;
	ko = FALSE;
	if (write(fd, buf, len) != *ret)
		ko = TRUE;
	else if (ft_errno && ft_errno != errno)
		ko = TRUE;
	return (ko);
}

static char	check_written_texts_diffs(int fd, size_t len)
{
	char	*ft_buf;
	char	*buf;
	char	ko;

	lseek(fd, 0, SEEK_SET);
	ft_buf = malloc((len + 1) * sizeof(char));
	buf = malloc((len + 1) * sizeof(char));
	if (!buf || !ft_buf
		|| read(fd, ft_buf, len) == ERROR || read(fd, buf, len) == ERROR)
		return (check_written_texts_diffs_error(ft_buf, buf));
	ft_buf[len] = '\0';
	buf[len] = '\0';
	ko = FALSE;
	if (strcmp(ft_buf, buf) != 0)
		ko = TRUE;
	else if (read(fd, buf, len) > 0)
		ko = TRUE;
	free(ft_buf);
	free(buf);
	return (ko);
}

static char	test_ft_write_case(char const *test_name, int fd, void const *buf, t_args *args)
{
	size_t	len;
	char	ko;
	ssize_t	ret;

	len = strlen(buf);
	if (args->verbose > 1)
		printf("\tft_write(%i, \"%s\", %zu):", fd, (char *)buf, len);
	else if (args->verbose)
		printf("\t%s", test_name);
	ko = check_returns_diffs(fd, buf, len, &ret);
	if (ret != ERROR && !ko)
	{
		ret = check_written_texts_diffs(fd, len);
		if (ret)
			ko = ret;
	}
	if (args->verbose && ko != ERROR)
		print_result(ko);
	return (ko);
}

static void	test_ft_write3(int ko, t_args *args)
{
	if (system("rm -f ./test_ft_write") == ERROR)
	{
		dprintf(2, RED "\tsystem() failed\n" RESET);
		return ;
	}
	if (!args->verbose && ko == ERROR)
		dprintf(2, RED "\tInsufficient memory.\n" RESET);
	else if (!args->verbose)
		print_result(ko);
}

static void	test_ft_write2(int fd, t_args *args)
{
	char	ko;
	char	ret;
	char	*long_str;

	ko = test_ft_write_case("zero_count:\t", fd, "", args);
	ret = test_ft_write_case("one_char_string:", fd, "0", args);
	if (ko != ERROR && ret)
		ko = ret;
	ret = test_ft_write_case("small_string:\t", fd, "0123456789", args);
	if (ko != ERROR && ret)
		ko = ret;
	long_str = "01234567890123456789012345678901234567890123456789"
		"01234567890123456789012345678901234567890123456789";
	ret = test_ft_write_case("long_string:\t", fd, long_str, args);
	if (ko != ERROR && ret)
		ko = ret;
	close(fd);
	fd = open("./wrong_file", O_RDWR);
	ret = test_ft_write_case("wrong_fd:\t", 666, "0123456789", args);
	if (ko != ERROR && ret)
		ko = ret;
	test_ft_write3(ko, args);
}

void	test_ft_write(t_args *args)
{
	static char	done = FALSE;
	int			fd;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_write:\n" RESET);
	else
		printf(BOLD "ft_write:" RESET);
	fflush(stdout);
	if (system(NULL) == FALSE)
	{
		dprintf(2, RED "\tNo shell is available\n" RESET);
		return ;
	}
	fd = open("./test_ft_write", O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);
	if (fd == ERROR)
	{
		dprintf(2, RED "\topen() failed\n" RESET);
		return ;
	}
	test_ft_write2(fd, args);
	done = TRUE;
}

#else

void	test_ft_write(t_args *args)
{
	static char	done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_write:" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_write:\n" RESET YELLOW "\tInactive\n" RESET);
	done = TRUE;
}

#endif
