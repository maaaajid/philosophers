NAME=philo

SRC= philo.c ft_atoi.c 

CFLAGS= -Wall -Wextra -Werror -fsanitize=thread -g3


all : $(NAME)

$(NAME) : $(SRC) $(LIBFT)
	@cc $(CFLAGS) $(SRC) -o $(NAME)


clean :
	rm -fr $(NAME)

fclean :
	rm -fr $(NAME) 

re : fclean all