NAME = link

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC1 = server.c

SRC2 = client.c

OBJ1 = server

OBJ2 = client

AR = ar rcs

RM = rm -rf

all : $(OBJ1) $(OBJ2) 

$(NAME) : all

$(OBJ1) : 
	$(CC) $(CFLAGS) libft.a binary.c $(SRC1) -o $(OBJ1)

$(OBJ2) : 
	$(CC) $(CFLAGS) libft.a binary.c $(SRC2) -o $(OBJ2)


clean : 
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME) $(OBJ1) $(OBJ2)
	@echo "fully"

re : fclean all
