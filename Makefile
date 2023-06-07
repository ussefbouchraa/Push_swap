NAME = push_swap
B_NAME = checker

CC = cc -Wall -Wextra -Werror
RM = rm -rf 

FILES =  utils/ft_isspace.c utils/ft_issorted.c utils/ft_max.c utils/ft_min.c utils/ft_clear.c \
		utils/ft_isdigit.c utils/ft_atoi.c utils/nbr_args.c utils/ft_strcmp.c utils/min_instructs.c \
		utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_substr.c utils/ft_strjoin.c utils/ft_strchr.c utils/get_next_line.c \
		utils/ft_lstadd_front.c utils/ft_lstnew.c utils/ft_lstsize.c utils/ft_lstadd_back.c \
		push_swap.c instructs.c sup_instructs.c sort.c sort_all.c utils/split_args.c utils/check_args.c \
		
B_FILES = checker.c utils/ft_isspace.c utils/ft_issorted.c utils/ft_max.c utils/ft_min.c utils/ft_clear.c \
		utils/ft_isdigit.c utils/ft_atoi.c utils/nbr_args.c utils/ft_strcmp.c \
		utils/ft_split.c utils/ft_strdup.c utils/ft_strlen.c utils/ft_substr.c utils/ft_strjoin.c utils/ft_strchr.c utils/get_next_line.c \
		utils/ft_lstadd_front.c utils/ft_lstnew.c utils/ft_lstsize.c utils/ft_lstadd_back.c \
		 instructs.c sup_instructs.c sort.c sort_all.c utils/split_args.c utils/check_args.c utils/min_instructs.c \

OBJS = $(FILES:.c=.o)
B_OBJS = $(B_FILES:.c=.o)

all : $(NAME)
bonus : $(B_NAME)

$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $@

%.o : %.c  push_swap.h
	$(CC) -c $< -o $@



$(B_NAME) : $(B_OBJS)
	$(CC) $(B_OBJS) -o $@

%.o : %.c 
	$(CC) -c $< -o $@

clean : 
	$(RM) $(OBJS) $(B_OBJS)

fclean : clean
	$(RM) $(NAME) $(B_NAME)

re : fclean all
