NAME = fillit
LIB = libft.a

FILENAMES = ft_get_id.c \
			ft_readfile.c \
			ft_tetradd.c \
			ft_tetrdel.c \
			ft_tetrnew.c \
			main.c \
			\
			ft_bigmatrix_size.c \
			ft_clear_rows.c \
			ft_copy_matrix.c \
			ft_del_matrix.c \
			ft_fillit.c \
			ft_lines_counter.c \
			ft_make_all_matrix.c \
			ft_make_bigmatrix.c \
			ft_matrix_one.c \
			ft_matrix_two.c \
			ft_matrix_three.c \
			ft_matrix_four.c \
			ft_matrix_five.c \
			ft_min_square_size.c \
			ft_print_result.c


SOURCES = $(addprefix ./, $(FILENAMES))
OBJECTS = $(addprefix obj/, $(FILENAMES:.c=.o))

CC = gcc
FLAGS ?= -Wall -Wextra -Werror
FLAGS += -I./ -I./libft/

all: $(NAME)

$(NAME): $(OBJECTS) $(LIB)
	$(CC) -o $@ $(FLAGS) $(OBJECTS) $(LIB)

$(LIB):
	make -C ./libft/

obj:
	mkdir obj/

obj/%.o: ./%.c | obj
	$(CC) -c $(FLAGS) $< -o $@

clean:
	make -C ./libft/ fclean
	rm -rf obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.NOTPARALLEL:
.PHONY: all clean fclean re
