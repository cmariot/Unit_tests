/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_tester_launcher.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:14:46 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 23:22:15 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	tester_launcher(void)
{
	t_test	*tests;
	char	*function_name;

	tests = NULL;
	function_name = "TESTER";
	load_test(&tests, function_name, "ok_test", &ok_test, NULL);
	load_test(&tests, function_name, "ko_test", &ko_test, NULL);
	load_test(&tests, function_name, "sigsegv", &sigsegv, NULL);
	load_test(&tests, function_name, "sigbus", &sigbus, NULL);
	load_test(&tests, function_name, "timeout", &timeout, NULL);
	load_test(&tests, function_name, "sigabrt", &sigabrt, NULL);
	load_test(&tests, function_name, "sigfpe", &sigfpe, NULL);
	load_test(&tests, function_name, "sigpipe", &sigpipe, NULL);
	load_test(&tests, function_name, "sigill", &sigill, NULL);
	load_test(&tests, function_name, "putstr_ok", &putstr, "Test\n");
	load_test(&tests, function_name, "putstr_ko", &putstr, "lol\n");
	return (launch_tests(&tests));
}
