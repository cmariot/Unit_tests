/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_ko_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 12:37:40 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 22:53:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"

int	ko_test(void)
{
	int	a;

	a = 1;
	if (a == 0)
		return (0);
	else
		return (-1);
}