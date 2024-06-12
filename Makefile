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
		utils4.c\
		sorting_under_5.c\
		sort_any.c\
		indexing.c\

CH_SOURCES = checker_bonus.c\
			utils_bonus.c\
			utils1_bonus.c\
			utils2_bonus.c\
			utils4_bonus.c\
			parcing_bonus.c\
			ch_mov_bonus.c\
			ch_mov1_bonus.c\
			ch_mov2_bonus.c\
			utils3_bonus.c\
			get_next_line_bonus.c\

OBJECTS = $(SOURCES:.c=.o)
CH_OBJECTS = $(CH_SOURCES:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)

$(CHECKER): $(CH_OBJECTS) 
	$(CC) $(CFLAGS) $(CH_OBJECTS) -o $(CHECKER)
%.o: %.c push_swap.h checker_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c 
	$(CC) $(CFLAGS) -c $< -o $@
bonus: $(CHECKER) 


clean:
	$(RM) $(OBJECTS) $(CH_OBJECTS)

fclean: clean
	$(RM) $(NAME) $(CHECKER)

re: fclean all
