CC = cc
SRCS = main.c error.c ft_atoi.c parsing.c philof.c routine.c
HEADER = philo.h
CFLAGS =  -Wall -Wextra -Werror -g 
NAME = philo
OBJS = $(SRCS:.c=.o)

all  : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -pthread $(OBJS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all