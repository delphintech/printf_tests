CC = cc

CFLAGS += -Werror -Wall -Wextra -MMD

LIBFT = libft.a
LIBFT_DIR = ./libft

LIBS = -L. -lft -lftprintf

NAME = libftprintf.a

SRCS += ft_printf.c \
		print_alpha.c

OBJS += $(SRCS:.c=.o)
DEPS += $(SRCS:.c=.d)

all	:	$(NAME)

$(LIBFT) : 
		$(MAKE) -C $(LIBFT_DIR) bonus
		mv $(LIBFT_DIR)/$(LIBFT) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $(SRCS)

$(NAME)	:	$(LIBFT) $(OBJS) 
	ar crs $(NAME) $(OBJS)

clean	:                 
		rm -f $(OBJS) $(DEPS)
		$(MAKE) -C ./$(LIBFT_DIR) clean

fclean	:	clean
		rm -f $(NAME) $(LIBFT)
		$(MAKE) -C ./$(LIBFT_DIR) fclean
		
re	:	fclean all
		$(MAKE) -C ./$(LIBFT) re
	
.PHONY: all clean fclean re

-include DEPS

# ---------------------------------------------------

DBGFLAGS := -g3

tclean	:	clean
		rm -f $(NAME) *.d *.o test
		$(MAKE) -C ./$(LIBFT_DIR) fclean

test : $(NAME) test.c
	$(CC) $(CFLAGS) -c test.c
	$(CC) $(CFLAGS) -o test test.o $(OBJS) $(LIBS)

debug :  $(NAME)             ## Permet de debuger le code avec lldb
	$(CC) $(CFLAGS) -c test.c
	$(CC) $(DBGFLAGS) -o test test.o $(OBJS) $(LIBS)
	lldb ./$(NAME)
	
val :  $(NAME)             ## Permet de debuger le code avec lldb
	$(CC) $(CFLAGS) -c test.c
	$(CC) $(DBGFLAGS) -o test test.o $(OBJS) $(LIBS)
	valgrind --leak-check=full --track-origins=yes -s ./test