# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 10:58:45 by fclaus-g          #+#    #+#              #
#    Updated: 2022/11/04 17:58:36 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC =  \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_tolower.c \
	ft_toupper.c ft_strlen.c ft_isalnum.c ft_strlcpy.c \
	ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strnstr.c \
	ft_bzero.c ft_memset.c ft_memcpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_striteri.c ft_strmapi.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

CC = gcc
LIB = ar -crs
CFLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
RM = rm -f
OPTION = -c 
BONUSSRC = \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
	ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
	

BONUSOBJ = $(BONUSSRC:.c=.o)
INCLUDE = libft.h

all : $(NAME)

$(NAME) : $(OBJ) $(INCLUDE)
	$(LIB) $(NAME) $(OBJ)

bonus : $(OBJ) $(BONUSOBJ) $(INCLUDE)
	$(LIB) $(NAME) $(BONUSOBJ) $(OBJ)

$(OBJ) : $(SRC)
	$(CC) $(CFLAGS) $(OPTION) $(SRC)
	
%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@


clean : 
	$(RM) $(OBJ) $(BONUSOBJ)

fclean: clean 
	$(RM) $(NAME) 

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus rebonus
