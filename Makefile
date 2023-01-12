NAME = link

CC = cc

CFLAGS = -Wall -Wextra -Werror

SSRC1 = server_bonus.c

SSRC2 = client_bonus.c

OOBJ1 = server_bonus

OOBJ2 = client_bonus

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

bonus : $(OOBJ1) $(OOBJ2) 

$(OOBJ1) : 
	$(CC) $(CFLAGS) libft.a binary.c $(SSRC1) -o $(OOBJ1)

$(OOBJ2) : 
	$(CC) $(CFLAGS) libft.a binary.c $(SSRC2) -o $(OOBJ2)



clean : 
	@$(RM) *.o
	@echo "cleaned"

fclean : clean
	@$(RM) $(NAME) $(OBJ1) $(OBJ2) $(OOBJ1) $(OOBJ2)
	@echo "perfectly"

re : fclean all

re_bonus : fclean bonus 
