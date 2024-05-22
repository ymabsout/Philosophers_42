CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread 
NAME = philo_bonus
SRCS = main_bonus.c error_bonus.c sim_bonus.c ft_atoi_bonus.c parsing_bonus.c set_free_bonus.c\
	time_print_bonus.c
OBJS = $(SRCS:.c=.o)
HEADER = philo_bonus.h

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean 
	rm -rf $(NAME)

re : fclean all

.PHONY : clean
