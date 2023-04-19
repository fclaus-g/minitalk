# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:06:55 by fclaus-g          #+#    #+#              #
#    Updated: 2023/04/19 13:43:46 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SOURCES = client.c server.c client_bonus.c server_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_PRINTF = ft_printf
OBJ_PRINTF = ft_printf/*.o
LIBFTPRINTF = ft_printf/libftprintf.a

SRC_LIBFT = libft
OBJ_LIBFT = libft/*.o
LIBFT = libft/libft.a

all: $(LIBFT) $(LIBFTPRINTF) client server

server: server.o
	$(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ server.o

client: client.o
	$(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ client.o

server_bonus: server_bonus.o
	$(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ server_bonus.o

client_bonus: client_bonus.o
	$(CC) $(CFLAGS) $(LIBFT) $(LIBFTPRINTF) -o $@ client_bonus.o
	
${LIBFTPRINTF}: 
	$(MAKE) -C $(SRC_PRINTF)
	
${LIBFT}: 
	$(MAKE) -C $(SRC_LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: server_bonus client_bonus ${LIBFT} ${LIBFTPRINTF}

clean:
	$(RM) $(OBJECTS) $(OBJ_PRINTF) $(OBJ_LIBFT)

fclean: clean
	$(RM) -f server client server_bonus client_bonus

re: fclean all

.PHONY: all clean fclean re
