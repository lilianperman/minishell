/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_template2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-silv <bda-silv@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:52:28 by bda-silv          #+#    #+#             */
/*   Updated: 2023/05/19 09:52:36 by bda-silv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unit_test.h"

/*
**		GUIDELINE TO UNIT TESTING
**
** 1.	Test file shall be named like test_branch.c i.e. test_parsing.c;
**
** 2.	All coding for tests should run in this test_file.c only;
**
** 3.	It has a specific Header file: #include "unit_test.h";
**
** 4.	Main()  will return (0) for success or any positive int for failure;
**
** 5.	Everything printed out will be collected in a logfile (FD 1 or FD 2);
**
** 6.	Infinite loops requiring user intervention to quit must be avoided, as
**		it will halt the Makefile and breaches the automated testing  purpose.
**
** 7.	Tests should print EXPECTED output vs ACTUAL output and, in case of
**		mismatch, an error should be returned to terminal.
**
*/

int	test1(void)
{
	prt(2, "Test 1: OK");
	return (0);
}

int	test2(void)
{
	prt(2, "Test 2: KO");
	return (1);
}

int	main(void)
{
	int	error;

	error = 0;
	error += test1();
	error += test2();
	return (error);
}
