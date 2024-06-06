/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabouab <dabouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:15:49 by dabouab           #+#    #+#             */
/*   Updated: 2024/06/05 17:29:12 by dabouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

# define BLUE "\x1b[34m"
# define RED "\x1b[31m"
# define PURPLE "\x1b[35m"
# define GREEN "\x1b[32m"
# define RESET "\x1b[0m"
# define START(name) printf(PURPLE "----- %s -----" RESET "\n", name)
# define STRTEST printf("Test: ")
# define LINE printf("\n");
# define OK printf(GREEN "//  OK  //" RESET "\n")
# define KO printf(RED "//  KO  //" RESET "\n")


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
	reel = printf(BLUE "%c | %c | %c" RESET "\n", 'a', '8', '~') - 9;
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
	reel = printf(BLUE "%s | %s | %s" RESET "\n", "s", "Ceci est un test !", "") - 9;
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
	reel = printf(BLUE "%p | %p" RESET "\n", p, NULL) - 9;
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
	reel = printf(BLUE "%d | %d | %d" RESET "\n", 0, INT_MIN, 102030) - 9;
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
	reel = printf(BLUE "%i | %i | %i" RESET "\n", 0, INT_MIN, 102030) - 9;
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
	reel = printf(BLUE "%u | %u | %u" RESET "\n", 0, INT_MIN, 102030) - 9;
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
	reel = printf(BLUE "%x | %x | %x" RESET "\n", 0, INT_MIN, 102030) - 9;
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
	reel = printf(BLUE "%X | %X | %X" RESET "\n", 0, INT_MIN, 102030) - 9;
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
	reel = printf(BLUE " %%   %%   %% " RESET "\n") - 9;
	result = ft_printf(" %%   %%   %% " "\n");
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
	reel = printf(BLUE "Char: %c\nString: %s\nPointer: %p\nDecimal: %d\nInterger: %i\n\
Unsigned Decimal: %u\nHexa lower: %x\nHexa upper: %X\nPercent sign : %%" RESET "\n", \
		'c', "This is a test!", p, INT_MIN, INT_MAX, 12345, 1024, 987654) - 9;
	LINE;
	result = ft_printf("Char: %c\nString: %s\nPointer: %p\nDecimal: %d\nInterger: %i\n\
Unsigned Decimal: %u\nHexa lower: %x\nHexa upper: %X\nPercent sign : %%\n", \
		'c', "This is a test!", p, (long)INT_MIN, (long)INT_MAX, 12345, 1024, 987654);
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
	reel = printf(BLUE "%s" RESET "\n", p) - 9;
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

// Add in Makefile
/*
# ---------------------------------------------------

DBGFLAGS := -g3

tclean	:	clean
		rm -f $(NAME) *.d *.o test

test : 	$(NAME) test.c
	$(CC) $(CFLAGS) -c test.c 
	$(CC) $(CFLAGS) -o test test.o $(OBJS) 

debug :	test.c   			## Permet de debuger le code avec lldb
	$(CC) $(DBGFLAGS) -c test.c $(SRCS)
	$(CC) $(DBGFLAGS) -o test test.o $(OBJS)
	lldb ./test
	
val : test.c           	## Permet de trouver les leak avec valgrind
	$(CC) $(CFLAGS) -c test.c $(SRCS)
	$(CC) $(DBGFLAGS) -o test test.o $(OBJS)
	valgrind --leak-check=full --track-origins=yes -s ./test
*/