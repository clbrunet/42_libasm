/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbrunet <clbrunet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 19:06:59 by clbrunet          #+#    #+#             */
/*   Updated: 2020/12/26 15:29:10 by clbrunet         ###   ########.fr       */
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
			"\tTest mandatory and bonus functions\n");
	printf(BOLD MAGENTA "\t-b," RESET BOLD " --bonus" RESET
			"\tTest bonus functions\n");
	printf(BOLD MAGENTA "\t-v," RESET BOLD " --verbose" RESET
			"\tShow the result of each test\n");
	printf(BOLD MAGENTA "\t-h," RESET BOLD " --help" RESET
			"\tPrints help information\n");
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

int	tests(t_args *args)
{
	if (args->strlen)
		test_strlen(args);
	if (args->strcpy)
		test_strcpy(args);
	if (args->strcmp)
		test_strcmp(args);
	/* if (args->write) */
	/* 	test_write(args); */
	/* if (args->read) */
	/* 	test_read(args); */
	/* if (args->strdup) */
	/* 	test_strdup(args); */
	if (!args->bonus || args->all)
	{
		test_strlen(args);
		test_strcpy(args);
		test_strcmp(args);
		/* test_write(args); */
		/* test_read(args); */
		/* test_strdup(args); */
	}
	if (args->bonus || args->all)
	{
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_args	args;

	if (parse_av(ac, av, &args))
	{
		print_help();
		/* print_args(&args); */
		return (1);
	}
	if (args.help)
		print_help();
	else
		tests(&args);
	return (0);
}
