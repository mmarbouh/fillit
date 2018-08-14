OBJS = $(wildcard ./*.c)

fillit:
	 gcc $(OBJS) libft/libft.a -o fillit
clean: 
	rm -f fillit
