/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 00:37:08 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 22:42:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	strlen_launcher(void)
{
	t_test	*tests;
	char	*function_name;

	tests = NULL;
	function_name = "STRLEN";
	load_test(&tests, function_name, "basic_test", &basic_test, NULL);
	load_test(&tests, function_name, "null_test", &null_test, NULL);
	load_test(&tests, function_name, "bigger_test", &bigger_str_test, NULL);
	return (launch_tests(&tests));
}
