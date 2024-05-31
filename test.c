/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:15:49 by dabouab           #+#    #+#             */
/*   Updated: 2024/05/31 16:55:47 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

# define START(name) printf("\033[0;35m----- %s -----\033[0m\n", name)
# define STRTEST printf("Test: ")
# define LINE printf("\n");
# define OK printf("\033[0;32m//  OK  //\033[0m\n")
# define KO printf("\033[0;31m//  KO  //\033[0m\n")


int	main(void)
{
	int	reel;
	int	result;
	char	c = 'z';
	char	*p;

	p = &c;
	
	// Char %p
	START("Char \%c");
	STRTEST;
	reel = printf("\033[0;34m%c | %c | %c\n\033[0m", 'a', '8', '~') - 11;
	result = ft_printf("%c | %c | %c\n", 'a', '8', '~');
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// String %s
	START("String \%s");
	STRTEST;
	reel = printf("\033[0;34m%s | %s | %s\n\033[0m", "s", "Ceci est un test !", "") - 11;
	result = ft_printf("%s | %s | %s\n", "s", "Ceci est un test !", "");
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// Pointer %p
	START("Pointer \%p");
	STRTEST;
	reel = printf("\033[0;34m%p | %p\n\033[0m", p, NULL) - 11;
	result = ft_printf("%p | %p\n", p, NULL);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// Decimal %d 
	START("Decimal \%d");
	STRTEST;
	reel = printf("\033[0;34m%d | %d | %d\n\033[0m", 0, INT_MIN, 102030) - 11;
	result = ft_printf("%d | %d | %d\n", 0, INT_MIN, 102030);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// Integer %i
	START("Integer \%i");
	STRTEST;
	reel = printf("\033[0;34m%i | %i | %i\n\033[0m", 0, INT_MIN, 102030) - 11;
	result = ft_printf("%i | %i | %i\n", 0, INT_MIN, 102030);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// Unsigned decimal %u
	START("Unsigned decimal \%u");
	STRTEST;
	reel = printf("\033[0;34m%u | %u | %u\n\033[0m", 0, INT_MIN, 102030) - 11;
	result = ft_printf("%u | %u | %u\n", 0, INT_MIN, 102030);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;
	
	// Hexadecimal lowercase %x
	START("Hexadecimal lowercase \%x");
	STRTEST;
	reel = printf("\033[0;34m%x | %x | %x\n\033[0m", 0, INT_MIN, 102030) - 11;
	result = ft_printf("%x | %x | %x\n", 0, INT_MIN, 102030);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;
	
	// Hexadecimal uppercase %X
	START("Hexadecimal uppercase \%X");
	STRTEST;
	reel = printf("\033[0;34m%X | %X | %X\n\033[0m", 0, INT_MIN, 102030) - 11;
	result = ft_printf("%X | %X | %X\n", 0, INT_MIN, 102030);
	if (result == reel)
		OK;
	else 
		
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// Percent sign %%
	START("Percent sign \%");
	STRTEST;
	reel = printf("\033[0;34m%%\n\033[0m") - 11;
	result = ft_printf("%%\n");
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;
	

	// MIX
	START("Everything");
	STRTEST;
	LINE;
	reel = printf("\033[0;34mChar: %c\nString: %s\nPointer: %p\nDecimal: %d\nInterger: %i\n\
Unsigned Decimal: %u\nHexa lower: %x\nHexa upper: %X\nPercent sign : %%\n\033[0m", \
		'c', "This is a test!", p, INT_MIN, INT_MAX, 12345, 1024, 987654) - 11;
	LINE;
	result = ft_printf("\033[0;34mChar: %c\nString: %s\nPointer: %p\nDecimal: %d\nInterger: %i\n\
Unsigned Decimal: %u\nHexa lower: %x\nHexa upper: %X\nPercent sign : %%\n\033[0m", \
		'c', "This is a test!", p, INT_MIN, INT_MAX, 12345, 1024, 987654);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;

	// NULL POINTER
	p = NULL;
	START("NULL POINTER");
	STRTEST;
	reel = printf("\033[0;34m%s\n\033", p) - 11;
	result = ft_printf("%s\n", p);
	if (result == reel)
		OK;
	else 
	{
		printf("Expected: %d | Got: %d\n", reel, result);
		KO;
	}
	LINE;
}