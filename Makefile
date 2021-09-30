CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
AR = ar cr
NAME= libft.a
SOURCES = ./main.c ./operations/operations_1.c ./operations/operations_2.c ./operations/operations_3.c \
			./small_sorting/small_sorting.c ./small_sorting/input_of_2or3.c ./small_sorting/input_of_5.c \
			./input/get_input.c ./input/list_to_array.c ./input/check_doubles.c ./input/bubble_sort.c \
			./input/add_index.c \
			./small_sorting/input_of_4.c \
			./algorithm/algorithm.c ./algorithm/markup.c ./algorithm/set_true_false.c ./algorithm/brute_force.c \
			./algorithm/do_the_job.c
BONUS = ./bonus/checker.c ./bonus/get_next_line/get_next_line.c ./bonus/get_next_line/get_next_line_utils.c \
			./operations/operations_1.c ./operations/operations_2.c ./operations/operations_3.c \
			./bonus/modified_ops.c ./bonus/get_input_bonus.c ./input/check_doubles.c ./bonus/while_loop.c
OBJECTS = $(SOURCES:.c=.o)
BONUS_OBJ = $(BONUS:.c=.o)
#build everything
all: $(NAME)

bonus: LIB $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) libft.a -o CHECKER

#make libft
LIB:
	make -C ./libft
	cp ./libft/libft.a $(NAME)

#creates a static library
$(NAME): LIB $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) libft.a -o push_swap

#removes all *.o files
clean:
	$(RM) $(OBJECTS) $(BONUS_OBJ)
	make clean -C ./libft

#removes all *.o files + libft.a + libmlx.a
fclean: clean
	$(RM) $(NAME)
	$(RM) ./libft/libft.a
	$(RM) libft.a
	$(RM) push_swap
	$(RM) CHECKER

#removes all *.o files + libft.a + libmlx.a and rebuild everything
re: fclean all