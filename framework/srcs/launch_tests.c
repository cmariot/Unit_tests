/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 22:01:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 22:20:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	*execute(void *add)
{
	t_test	*test;

	test = (t_test *)add;
	test->status = (*test).test_add();
	return (test);
}

int	create_threads(t_test **test)
{
	int			status;
	pthread_t	thread_id;
	size_t		init_time;

	init_time = get_time();
	pthread_create(&thread_id, NULL, &execute, *test);
	while (1)
	{
		if (check_timeout(init_time))
		{
			pthread_cancel(thread_id);
			return (TIMEOUT);
		}
		else if ((*test)->status != -2)
			break ;
	}
	pthread_join(thread_id, NULL);
	status = (*test)->status;
	return (status);
}

void	execute_test(t_test **test)
{
	pid_t	pid;
	int		status;
	int		fd;
	int		stdout_backup;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("Error, fork failed.\n", 2);
		return ;
	}
	else if (pid == 0)
	{
		output_redirection(&fd, &stdout_backup, *test);
		status = create_threads(test);
		exit_child(test, &fd, &stdout_backup, status);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			(*test)->status = WEXITSTATUS(status);
		else if WIFSIGNALED(status)
			(*test)->status = WTERMSIG(status);
	}
}

int	launch_tests(t_test **test)
{
	int		total_number_of_tests;
	int		count_of_succeeded_tests;
	int		routine_exit;
	t_test	*first;

	first = (*test);
	total_number_of_tests = 0;
	count_of_succeeded_tests = 0;
	printf("%s TESTS:\n", (*test)->function);
	while (*test)
	{
		execute_test(test);
		print_test_output(*test, total_number_of_tests);
		if ((*test)->status == OK)
			count_of_succeeded_tests++;
		total_number_of_tests++;
		*test = (*test)->next;
	}
	routine_exit
		= display_results(count_of_succeeded_tests, total_number_of_tests);
	ft_cleartest_lst(&first, 1);
	return (routine_exit);
}
