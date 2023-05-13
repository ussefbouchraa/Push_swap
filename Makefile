NAME = push_swap

CC = cc -Wall -Wextra -Werror
RM = rm -rf 

FILES = utils/ft_atoi.c \
		utils/ft_clear.c \
		utils/ft_isdigit.c \
		utils/ft_split.c \
		utils/ft_strdup.c \
		utils/ft_strlen.c \
		utils/ft_substr.c \
		utils/nbr_args.c \

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) push_swap.c $(OBJS) -o $@

%.o : %.c  push_swap.h
	$(CC) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
