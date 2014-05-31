NAME	=	ft_select

CFLAGS	+=  -Wall -Wextra -Werror -I./includes -ggdb3


SRCS	=		srcs/ft_strlen.c\
				srcs/ft_strdup.c\
				srcs/main.c\
				srcs/ft_bzero.c\
				srcs/create_list.c\
				srcs/easy_print.c\
				srcs/end_key.c \
				srcs/init_core.c \
				srcs/init_term.c \
				srcs/keys.c\
				srcs/print_ac.c\
				srcs/print_list.c\
				srcs/read_entry.c

SRC	= $(addprefix $(SRCPATH), $(SRCS))

OBJ	= $(SRC:.c=.o)

all: $(NAME) 

$(NAME): $(OBJ) 
	gcc $(CFLAGS) $(SRCS) -o $(NAME) -lcurses

clean :
	rm -f $(OBJ)

fclean : clean 
	rm -f $(NAME)

re: fclean all 

.PHONY: all clean fclean re
