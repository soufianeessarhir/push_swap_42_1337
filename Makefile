NAME = push_swap
CHECKER = checker
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
		indexing.c\

CH_SOURCES = checker.c\
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
			indexing.c\

OBJECTS = $(SOURCES:.c=.o)
CH_OBJECTS = $(CH_SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

bonus:$(CHECKER)

$(CHECKER): $(CH_OBJECTS)
	$(CC) $(CFLAGS) $(CH_OBJECTS) -o $(CHECKER)

%.o: %.c push_swap.h checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
