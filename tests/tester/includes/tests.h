/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 01:39:14 by cmariot           #+#    #+#             */
/*   Updated: 2022/01/08 22:58:11 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include "libunit.h"
# include <signal.h>

//STRLEN

int		tester_launcher(void);

int		ok_test(void);
int		ko_test(void);
int		sigsegv(void);
int		sigbus(void);
int		putstr(void);
int		timeout(void);
int		sigabrt(void);
int		sigfpe(void);
int		sigpipe(void);
int		sigill(void);

#endif
