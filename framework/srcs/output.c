/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 22:38:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}

int	display_results(int count_of_succeeded_tests, int total_number_of_tests)
{
	if (count_of_succeeded_tests == total_number_of_tests)
	{
		printf("%d / %d = ",
			count_of_succeeded_tests, total_number_of_tests);
		printf(GREEN"[OK]\n"RESET);
		return (0);
	}
	else
	{
		printf("%d / %d = ",
			count_of_succeeded_tests, total_number_of_tests);
		printf(RED"[KO]\n"RESET);
		return (-1);
	}
}

void	check_output(t_test *test)
{
	char	*output;

	output = filename_to_str(test->filename);
	if (ft_strcmp(output, test->expected_output) == 0)
	{
		printf(GREEN"[OUTPUT : OK]"RESET);
	}
	else
	{
		printf(RED"[OUTPUT : KO]"RESET);
		test->status = KO;
	}
	if (output)
		free(output);
}

void	print_test_output(t_test *test, int test_number)
{
	printf("%s_%02d", test->function, test_number);
	printf(": %s:\t", test->test_name);
	if (test->status == OK)
		printf(GREEN"[OK]"RESET);
	else if (test->status == 255)
		printf(RED"[KO]"RESET);
	else if (test->status == TIMEOUT)
		printf(RED"[TIMEOUT]"RESET);
	else if (test->status == SIGSEGV)
		printf(RED"[SIGSEGV]"RESET);
	else if (test->status == SIGBUS)
		printf(RED"[SIGBUS]"RESET);
	else if (test->status == SIGABRT)
		printf(RED"[SIGABRT]"RESET);
	else if (test->status == SIGFPE)
		printf(RED"[SIGFPE]"RESET);
	else if (test->status == SIGPIPE)
		printf(RED"[SIGPIPE]"RESET);
	else if (test->status == SIGILL)
		printf(RED"[SIGILL]"RESET);
	else
		printf(RED"[%d]"RESET, test->status);
	if (test->expected_output != NULL)
		check_output(test);
	printf("\n");
}
