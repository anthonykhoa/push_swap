OBJS = push.o swap.o rotate.o list_size.o sorted.o load.o solve.o grow_b.o sort.o rem_int_arr_element.o

PS_OBJS = push_swap.o

CHECK_OBJS = checker.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g

all: libft_maker push_swap checker

libft_maker:
	@make -C libft

push_swap: $(LIB) $(OBJS) $(PS_OBJS)
	@gcc -o push_swap $(FLAGS) $(LIB) $(OBJS) $(PS_OBJS)

checker: $(LIB) $(OBJS) $(CHECK_OBJS)
	@gcc -o checker $(FLAGS) $(LIB) $(OBJS) $(CHECK_OBJS)

%.o: %.c
	@gcc $(FLAGS) -c -o $@ $<

clean:
	@rm -f $(OBJS) $(PS_OBJS) $(CHECK_OBJS)
	@make -C libft clean

fclean: clean
	@rm -f push_swap checker
	@make -C libft fclean

re: fclean all