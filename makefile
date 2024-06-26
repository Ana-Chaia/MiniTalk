# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anacaro5 <anacaro5@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/04 10:20:00 by anacaro5          #+#    #+#              #
#    Updated: 2024/04/22 09:42:37 by anacaro5         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_MC 	= client
NAME_MS 	= server
NAME_BC 	= client_bonus
NAME_BS		= server_bonus

CC			= cc
CFLAGS		= -Werror -Wall -Wextra -g3
LIBFT		= ./libplus/libft.a

M_INC		= -I mandatory/minitalk.h
B_INC		= -I bonus/minitalk_bonus.h

PATH_M		=	mandatory/
CLIENT_M	=	$(addprefix $(PATH_M), client.c)
SERVER_M	=	$(addprefix $(PATH_M), server.c)

PATH_B		=	bonus/
CLIENT_B	=	$(addprefix $(PATH_B), client_bonus.c)
SERVER_B	=	$(addprefix $(PATH_B), server_bonus.c)

CLIENT_M_O	=	$(CLIENT_M:%.c=%.o)
SERVER_M_O	=	$(SERVER_M:%.c=%.o)

CLIENT_B_O	=	$(CLIENT_B:%.c=%.o)
SERVER_B_O	= 	$(SERVER_B:%.c=%.o)

BLUE 		= \033[1;36m
WHITE 		= \033[0;39m
T_LIB		= $(shell test -f ./libplus/get_next_line_utils.o && echo "yes" 2>&1)

all: libft $(NAME_MC) $(NAME_MS)

libft:
	@if ! [ $(T_LIB) ]; then echo "$(BLUE)-*- Creating libplus library. -*-$(WHITE)";fi
	@make -C libplus/ --no-print-directory

$(NAME_MC): $(CLIENT_M_O)
	$(CC) $(CFLAGS) $< -I $(PATH_M) $(LIBFT) -o $@

$(NAME_MS): $(SERVER_M_O)
	$(CC) $(CFLAGS) $< -I $(PATH_M) $(LIBFT) -o $@

bonus: libft $(NAME_BC) $(NAME_BS)

$(NAME_BC): $(CLIENT_B_O)
	$(CC) $(CFLAGS) $< -I $(PATH_B) $(LIBFT) -o $@

$(NAME_BS): $(SERVER_B_O)
	$(CC) $(CFLAGS) $< -I $(PATH_B) $(LIBFT) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C ./libplus --no-print-directory
	rm -f $(CLIENT_M_O) $(SERVER_M_O) $(CLIENT_B_O) $(SERVER_B_O)

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME_MC) $(NAME_MS) $(NAME_BC) $(NAME_BS)

re: fclean all

.PHONY: all clean fclean re libft