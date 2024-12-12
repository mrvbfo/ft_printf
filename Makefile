NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf
AR = ar rcs

SRC = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_str.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME):$(OBJ)
	@$(CC) $(CFLAGS) -c $(SRC)
	@$(AR) $(NAME) $?

clean: 
	@$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
