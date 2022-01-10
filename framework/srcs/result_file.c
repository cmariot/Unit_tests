/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 00:54:56 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/10 12:36:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

int	create_log_file(t_test *test)
{
	char	*filename;
	int		log_file;

	filename = ft_strjoin(test->function, ".log");
	log_file = open(filename, O_RDWR | O_CREAT | O_TRUNC, 0640);
	if (log_file == -1)
	{
		ft_putstr_fd("Error, open failed.\n", 2);
		return (-1);
	}
	ft_putstr_fd(test->function, log_file);
	ft_putstr_fd(" TESTS:\n\n", log_file);
	return (log_file);
}
