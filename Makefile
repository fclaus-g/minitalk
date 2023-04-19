# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fernandoclaus <fernandoclaus@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:06:55 by fclaus-g          #+#    #+#              #
#    Updated: 2023/04/19 09:20:43 by fernandocla      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SOURCES = client.c server.c client_bonus.c server_bonus.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRC_PRINTF = ft_printf
LIBFTPRINTF = ft_printf/libftprintf.a

all: $(LIBFTPRINTF) client server

server: server.o
	$(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ server.o

client: client.o
	$(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ client.o

server_bonus: server_bonus.o
	$(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ server_bonus.o

client_bonus: client_bonus.o
	$(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ client_bonus.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

${LIBFTPRINTF}:
	@$(MAKE) -sC $(SRC_PRINTF)
	@echo "Printf compilado"

bonus: server_bonus client_bonus ${LIBFTPRINTF}
	$(CC) $(CFLAGS) $(LIBFTPRINTF) - o server_bonus.c server_bonus
	$(CC) $(CFLAGS) $(LIBFTPRINTF) - o client_bonus.c client_bonus
clean:
	$(RM) $(OBJECTS)
fclean: clean
	$(RM) -f server client server_bonus client_bonus
re: fclean all
.PHONY: all clean fclean re
