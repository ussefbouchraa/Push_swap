NAME = push_swap

CC = cc -Wall -Wextra -Werror
RM = rm -rf 

FILES =  utils/ft_isspace.c utils/ft_issorted.c utils/ft_max.c utils/ft_min.c utils/ft_clear.c utils/ft_isdigit.c \
		utils/ft_atoi.c  utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_substr.c  \
		utils/nbr_args.c utils/ft_lstadd_front.c utils/ft_lstnew.c utils/ft_lstsize.c utils/ft_lstadd_back.c 

OBJS = $(FILES:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) push_swap.c instructs.c sup_instructs.c sort.c $(OBJS) -o $@

%.o : %.c  push_swap.h
	$(CC) -c $< -o $@

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all
