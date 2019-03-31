OBJS = push.o swap.o rotate.o load.o aux_funcs1.o aux_funcs2.o solve.o grow_small_b.o bubble_sort.o merge_sort.o rank_nodes.o

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