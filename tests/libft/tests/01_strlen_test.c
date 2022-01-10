/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:32:15 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/10 12:24:00 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	strlen_test(void)
{
	char	*str;

	if (ft_strlen("a") != 1
		|| ft_strlen("ab") != 2
		|| ft_strlen("abc") != 3
		|| ft_strlen("abcd") != 4
		|| ft_strlen("a b c") != 5
		|| ft_strlen("a B c") != 5)
		return (-1);

	str = NULL;
	if (ft_strlen(NULL) != 0
		|| ft_strlen(str) != 0)
		return (-1);
	
	if (ft_strlen("12345678901234567890123456789012345678901234567890123490693")
		!= 59)
		return (-1);
	
	return (0);
}
