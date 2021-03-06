/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:42:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/09 13:57:53 by cmariot          ###   ########.fr       */
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

void	check_stdout_output(t_test *test, int fd)
{
	char	*output;

	if (test->expected_output != NULL)
	{
		output = filename_to_str(test->filename);
		if (ft_strcmp(output, test->expected_output) == 0)
		{
			dprintf(fd, GREEN"[OUTPUT : OK]\n"RESET);
		}
		else
		{
			dprintf(fd, RED"[OUTPUT : KO]\n");
			dprintf(fd, "\t\t\t[OUTPUT]:\t[%s]\n", output);
			dprintf(fd, "\t\t\t[EXPECTED]:\t[%s]\n"RESET, test->expected_output);
			if (fd != 1)
				test->status = KO;
		}
		if (output)
			free(output);
	}
	else
		dprintf(fd, "\n");
}

void	print_test_output(t_test *test, int test_number, int fd)
{
	if (fd != 1)
		print_test_output(test, test_number, 1);
	dprintf(fd, "%s_%02d", test->function, test_number);
	dprintf(fd, ": %s:\t", test->test_name);
	if (test->status == OK)
		dprintf(fd, GREEN"[OK]"RESET);
	else if (test->status == KO)
		dprintf(fd, RED"[KO]"RESET);
	else if (test->status == TIMEOUT)
		dprintf(fd, RED"[TIMEOUT]"RESET);
	else if (test->status == SIGSEGV)
		dprintf(fd, RED"[SIGSEGV]"RESET);
	else if (test->status == SIGBUS)
		dprintf(fd, RED"[SIGBUS]"RESET);
	else if (test->status == SIGABRT)
		dprintf(fd, RED"[SIGABRT]"RESET);
	else if (test->status == SIGFPE)
		dprintf(fd, RED"[SIGFPE]"RESET);
	else if (test->status == SIGPIPE)
		dprintf(fd, RED"[SIGPIPE]"RESET);
	else if (test->status == SIGILL)
		dprintf(fd, RED"[SIGILL]"RESET);
	else
		dprintf(fd, RED"[EXIT : %d]"RESET, test->status);
	check_stdout_output(test, fd);
}
