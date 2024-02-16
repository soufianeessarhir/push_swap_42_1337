NAME = push_swap
SOURCES = main.c\
		utils.c\
		utils1.c\
		utils2.c\
		parcing.c\
		swaps.c\
		rotates.c\
		rev_rotates.c\
		pushs.c\
		utils3.c\
		sorting_under_5.c\
		sort_any.c\
		
OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
