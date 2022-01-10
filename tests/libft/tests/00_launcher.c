/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:37:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/10 12:08:06 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	libft_launcher(void)
{
	t_test	*tests;
	char	*function_name;

	tests = NULL;
	function_name = "LIBFT";
	load_test(&tests, function_name, "strlen", &strlen_test, NULL);
	load_test(&tests, function_name, "strtoll", &strtoll_test, NULL);
	return (launch_tests(&tests));
}
