OBJS = push.o swap.o rotate.o load.o aux_funcs.o node_funcs.o solve.o merge_sort.o rank_nodes.o cut_down.o pre_msort.o print_stacks.o

PS_OBJS = push_swap.o

CHECK_OBJS = checker.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror -g 

all: libft_maker push_swap checker

rn:
	rm nums
	touch nums
	gcc -o rn random_number_generator.c $(LIB)

500:
	rm nums
	touch nums
	gcc -o rn random_number_generator.c $(LIB)
	./rn o 500
	open nums
	rm rn

100:
	rm nums
	touch nums
	gcc -o rn random_number_generator.c $(LIB)
	./rn o 100
	open nums
	rm rn

5:
	rm nums
	touch nums
	gcc -o rn random_number_generator.c $(LIB)
	./rn o 5
	open nums
	rm rn

3:
	rm nums
	touch nums
	gcc -o rn random_number_generator.c $(LIB)
	./rn o 3
	open nums
	rm rn


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
