/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_strtoll_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 14:19:38 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/10 12:19:48 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	strtoll_test(void)
{
	char			*test;
	char			*str1;
	char			*str2;
	long long		result;
	long long		expected;

	test = "0";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "0123456789";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "-1";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "+10";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "				          42";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "			-5325 868";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "	++54";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "	 -0000405";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = " 75+";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "9223372036854775807";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "-9223372036854775807";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected || ft_strcmp(str1, str2) != 0)
		return (-1);

	test = "922337203685477580799999999999999999";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (result != expected)
		return (-1);

	test = "-922337203685477580799999999999999999";
	str1 = test;
	result = ft_strtoll(str1, &str1);
	str2 = test;
	expected = strtoll(str2, &str2, 10);
	if (*str1 == '\0' || result == 0)
		return (-1);

	return (0);
}
