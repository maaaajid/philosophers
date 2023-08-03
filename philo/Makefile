NAME=philo

SRC= philo.c ft_atoi.c philo_utils.c

CFLAGS= -Wall -Wextra -Werror


all : $(NAME)

$(NAME) : $(SRC) $(LIBFT)
	@cc $(CFLAGS) $(SRC) -o $(NAME)


clean :
	rm -fr $(NAME)

fclean :
	rm -fr $(NAME) 

re : fclean all