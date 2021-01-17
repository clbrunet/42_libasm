/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_read.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/26 11:30:37 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/17 17:47:52 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

#if FT_READ

static char	check_returns_and_read_texts_diffs(int fd, size_t count, char *ft_buf, char *buf)
{
	char	ko;
	ssize_t	ret;
	int		ft_errno;

	lseek(fd, 0, SEEK_SET);
	ret = ft_read(fd, ft_buf, count);
	if (ret == ERROR)
		ft_errno = errno;
	lseek(fd, 0, SEEK_SET);
	ko = SUCCESS;
	if (ret != read(fd, buf, count))
		ko = TRUE;
	else if (ret == ERROR && ft_errno != errno)
		ko = TRUE;
	ft_buf[count] = '\0';
	buf[count] = '\0';
	if (strcmp(ft_buf, buf) != 0)
		ko = TRUE;
	return (ko);
}

static char	test_ft_read_case(char const *test_name, int fd, size_t count, t_args *args)
{
	char	ko;
	char	*ft_buf;
	char	*buf;

	if (args->verbose > 1)
		printf("\tft_read(%i, buf, %zu):", fd, count);
	else if (args->verbose)
		printf("\t%s", test_name);
	ft_buf = malloc((count + 1) * sizeof(char));
	buf = malloc(count + 1 * sizeof(char));
	if (!ft_buf || !buf)
	{
		free(ft_buf);
		free(buf);
		fflush(stdout);
		dprintf(2, RED "\tmalloc() failed\n" RESET);
		return (ERROR);
	}
	ko = check_returns_and_read_texts_diffs(fd, count, ft_buf, buf);
	free(ft_buf);
	free(buf);
	if (args->verbose)
		print_result(ko);
	return (ko);
}

static void	test_ft_read3(char ko, t_args *args)
{
	char	ret;

	open("./wrong_file", O_RDWR);
	ret = test_ft_read_case("wrong_fd:\t", 666, 10, args);
	if (ko != ERROR && ret)
		ko = ret;
	if (system("rm -f ./test_ft_read") == ERROR)
	{
		dprintf(2, RED "\tsystem() failed\n" RESET);
		return ;
	}
	if (!args->verbose && ko == ERROR)
		dprintf(2, RED "\tInsufficient memory.\n" RESET);
	else if (!args->verbose)
		print_result(ko);
}

static void	test_ft_read2(int fd, t_args *args)
{
	char	ko;
	char	ret;
	char	*long_str;

	long_str = "0123456789abcdqepfnio429780-[ewdofvnlb:fwejfsbfk"
		"[][;{}{kfi()*&*^%*(!)i2ifuheosfUI*^@&%0976@&%^TGH+";
	if (write(fd, long_str, strlen(long_str)) == ERROR
			|| write(fd, long_str, strlen(long_str)) == ERROR)
	{
		dprintf(2, RED "\twrite() failed\n" RESET);
		return ;
	}
	ko = test_ft_read_case("zero_count:\t", fd, 0, args);
	ret = test_ft_read_case("one_char_string:", fd, 1, args);
	if (ko != ERROR && ret)
		ko = ret;
	ret = test_ft_read_case("small_string:\t", fd, 10, args);
	if (ko != ERROR && ret)
		ko = ret;
	ret = test_ft_read_case("long_string:\t", fd, 100, args);
	if (ko != ERROR && ret)
		ko = ret;
	close(fd);
	test_ft_read3(ko, args);
}

void	test_ft_read(t_args *args)
{
	static char	done = FALSE;
	int			fd;

	if (done)
		return ;
	if (args->verbose)
		printf(BOLD "ft_read:\n" RESET);
	else
		printf(BOLD "ft_read:" RESET);
	fflush(stdout);
	fd = open("./test_ft_read", O_RDWR | O_CREAT, S_IWUSR | S_IRUSR);
	if (system(NULL) == FALSE || fd == ERROR)
	{
		if (fd == ERROR)
			dprintf(2, RED "\topen() failed\n" RESET);
		else
			dprintf(2, RED "\tNo shell is available\n" RESET);
		return ;
	}
	test_ft_read2(fd, args);
	done = TRUE;
}

#else

void	test_ft_read(t_args *args)
{
	static char done = FALSE;

	if (done)
		return ;
	if (!args->verbose)
		printf(BOLD "ft_read:" RESET YELLOW "\tInactive\n" RESET);
	else
		printf(BOLD "ft_read:\n" RESET YELLOW "\tInactive\n" RESET);
	done = TRUE;
}

#endif
