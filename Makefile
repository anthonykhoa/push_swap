OBJS = push.o swap.o rotate.o list_size.o sorted.o load.o solve.o grow_b.o sort.o


PS_OBJS = push_swap.o

CHECK_OBJS = checker.o

LIB = libft/libft.a

FLAGS = -Wall -Wextra -Werror

all: push_swap checker

push_swap: $(LIB) $(OBJS) $(PS_OBJS)
	@make -C libft
	@gcc -o push_swap $(FLAGS) $(LIB) $(OBJS) $(PS_OBJS)

checker: $(LIB) $(OBJS) $(CHECK_OBJS)
	@make -C libft
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