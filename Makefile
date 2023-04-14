# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fclaus-g <fclaus-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 11:06:55 by fclaus-g          #+#    #+#              #
#    Updated: 2023/04/14 11:12:26 by fclaus-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CCDEBUG = gcc -g -Wall -Werror -Wextra

CLIENTSRC = client.c
SERVERSRC = server.c

CLIENTOBJ = $(CLIENTSRC:.c=.o)
SERVEROBJ = $(SERVERSRC:.c=.o)

RM = rm -f

all: $(CLIENT) $(SERVER)

$(CLIENT): $(CLIENTOBJ)
	$(CC) $(CFLAGS) $(CLIENTOBJ) -o $(CLIENT)

$(SERVER): $(SERVEROBJ)
	$(CC) $(CFLAGS) $(SERVEROBJ) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(CLIENTOBJ) $(SERVEROBJ)
fclean: clean
	$(RM) $(CLIENT) $(SERVER)
re: fclean all
.PHONY: all clean fclean re
