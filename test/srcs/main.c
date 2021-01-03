/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:06:59 by clbrunet          #+#    #+#             */
/*   Updated: 2021/01/03 15:20:49 by clbrunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libasm_test.h"

void	print_help(void)
{
	printf(BOLD GREEN "libasm_test\n" RESET);
	printf(BOLD RED "\nUSAGE:\n" RESET);
	printf(BOLD "\t<path>/libasm_test" RESET " [flags] [function]...\n");
	printf(BOLD RED "\nFLAGS:\n" RESET);
	printf(BOLD MAGENTA "\t-a," RESET BOLD " --all" RESET
			"\tTest mandatory and bonus functions.\n");
	printf(BOLD MAGENTA "\t-b," RESET BOLD " --bonus" RESET
			"\tTest bonus functions.\n");
	printf(BOLD MAGENTA "\t-v," RESET BOLD " --verbose" RESET
			"\tShow the result of each test. "
			"Repeating the option show the test.\n");
	printf(BOLD MAGENTA "\t-h," RESET BOLD " --help" RESET
			"\tPrint this help message.\n");
	printf(BOLD RED "\nFUNCTION:\n" RESET);
	printf("\t[ft_]" BOLD "function_name\n" RESET);
}

void	print_result(char ko)
{
	if (ko)
		printf(BOLD RED "\t[KO]\n" RESET);
	else
		printf(BOLD GREEN "\t[OK]\n" RESET);
}

void	print_args(t_args *args)
{
	printf("all: %i\n", args->all);
	printf("bonus: %i\n", args->bonus);
	printf("verbose: %i\n", args->verbose);
	printf("help: %i\n", args->help);
	printf("strlen: %i\n", args->strlen);
	printf("strcpy: %i\n", args->strcpy);
	printf("strcmp: %i\n", args->strcmp);
	printf("write: %i\n", args->write);
	printf("read: %i\n", args->read);
	printf("strdup: %i\n", args->strdup);
}

static int	mandatory_part_tests(t_args *args)
{
	test_ft_strlen(args);
	test_ft_strcpy(args);
	test_ft_strcmp(args);
	test_ft_write(args);
	test_ft_read(args);
	test_ft_strdup(args);
	return (SUCCESS);
}

static void	bonus_part_tests(t_args *args)
{
	(void)args;
}

static void	tests(t_args *args)
{
	if (args->strlen)
		test_ft_strlen(args);
	if (args->strcpy)
		test_ft_strcpy(args);
	if (args->strcmp)
		test_ft_strcmp(args);
	if (args->write)
		test_ft_write(args);
	if (args->read)
		test_ft_read(args);
	if (args->strdup)
		test_ft_strdup(args);
	if (args->bonus)
		bonus_part_tests(args);
	if (args->all)
	{
		mandatory_part_tests(args);
		bonus_part_tests(args);
	}
	if (!args->bonus && !args->strlen && !args->strcpy && !args->strcmp
			&& !args->write && !args->read && !args->strdup)
		mandatory_part_tests(args);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (parse_av(ac, av, &args))
	{
		print_help();
		return (FAILURE);
	}
	if (args.help)
		print_help();
	else
		tests(&args);
	return (SUCCESS);
}
