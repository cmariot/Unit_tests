/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_lst_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:35:51 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 20:59:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

t_test	*ft_newtest_lst(char *function, char *test_name,
			void *test_add, char *expected_output)
{
	t_test	*new;
	char	*tmp;

	new = malloc(sizeof(t_test));
	if (new)
	{
		new->function = function;
		new->test_name = test_name;
		new->test_add = test_add;
		new->expected_output = expected_output;
		new->filename = ft_strjoin(function, "_");
		tmp = ft_strjoin(new->filename, test_name);
		free(new->filename);
		new->filename = ft_strjoin(tmp, ".log");
		free(tmp);
		new->status = -2;
		new->next = NULL;
		return (new);
	}
	else
		return (NULL);
}

t_test	*ft_lasttest_lst(t_test *test)
{
	if (test)
	{
		while (test->next)
			test = test->next;
		return (test);
	}
	else
		return (NULL);
}

void	ft_addtest_lst(t_test **test_add, t_test *new)
{
	t_test	*tmp;

	if (test_add)
	{
		if (*test_add == NULL)
			*test_add = new;
		else
		{
			tmp = ft_lasttest_lst(*test_add);
			tmp->next = new;
		}
	}
}

void	ft_cleartest_lst(t_test **test, bool opt)
{
	t_test	*tmp;

	while (*test)
	{
		tmp = (*test)->next;
		if (opt == 1)
			unlink((*test)->filename);
		free((*test)->filename);
		free(*test);
		*test = tmp;
	}
}

void	load_test(t_test **test, char *function, char *test_name,
			void *function_add, char *expected_output)
{
	if (test == NULL)
		*test = ft_newtest_lst(function, test_name,
				function_add, expected_output);
	else
		ft_addtest_lst(test, ft_newtest_lst(function, test_name,
				function_add, expected_output));
}
