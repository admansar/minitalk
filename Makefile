NAME = link

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC1 = server.c

SRC2 = client.c

OBJ1 = server

OBJ2 = client

OBJ = binary.o

AR = ar rcs
RM = rm -rf

all : $(NAME) x

make_libft : 
	cd libft/ && make
	cd ..

$(NAME) : $(OBJ) 
	$(RM) libft/libft.a
	$(AR) $(NAME) $(OBJ) libft/*.o

x : 
	$(CC) $(CFLAGS) $(NAME) $(SRC1) -o $(OBJ1)
	$(CC) $(CFLAGS) $(NAME) $(SRC2) -o $(OBJ2)

clean : 
	$(RM) *.o
	cd libft/
	$(RM) *.o $(OBJ1) $(OBJ2)
	cd ..
fclean : clean
	cd libft && make fclean
	$(RM) $(NAME) $(OBJ1) $(OBJ2)

re_libft :
	cd libft/ && make re
	cd ..

re : re_libft all
