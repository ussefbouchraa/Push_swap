# Name = push_swap

# CC = cc -Wall -Wextra -Werror
# RM = rm -rf 

# Files =  utils/ft_atoi.c utils/ft_clear.c  utils/ft_isdigit.c utils/ft_split.c \
# 		utils/ft_strdup.c  utils/ft_strlen.c utils/ft_substr.c utils/nbr_args.c

# OBJS = (Files:.c=.o)

# all : $(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) push_swap.c -o $@

# %.o : %.c  push_swap.h
# 	$(cc) -c $< -o $@

# clean : 
# 	$(RM) $(OBJS)

# fclean : clean
# 	$(RM) $(NAME)

# re : fclean all
