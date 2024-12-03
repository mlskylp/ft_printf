NAME = libftprintf.a
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c ft_convert_hex.c ft_convert_nbr.c ft_transformation.c

OBJ = $(FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(OBJ) : $(FILES)
		cc $(CFLAGS) -c $(FILES)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re