/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_basic_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:32:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 23:33:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	basic_test(void)
{
	if (ft_strlen("a") == 1
		&& ft_strlen("ab") == 2
		&& ft_strlen("abc") == 3
		&& ft_strlen("abcd") == 4
		&& ft_strlen("a b c") == 5
		&& ft_strlen("a B c") == 5)
	{
		return (0);
	}
	else
		return (-1);
}
