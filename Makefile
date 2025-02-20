# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juhtoo-h <juhtoo-h@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 15:28:49 by juhtoo-h          #+#    #+#              #
#    Updated: 2025/02/20 13:04:02 by juhtoo-h         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src/
		
SRCS = check_map.c so_long.c error_utils.c file_to_img.c so_long_utils.c put_pic.c \
 		events.c animation.c animation_walking.c animation_utils.c collection.c \
		exit.c display.c monster.c death.c

SRCS_PREFIXED = $(addprefix $(SRC_PATH), $(SRCS))

INCLUDE = include/so_long.h

NAME = so_long

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

MLX42_PATH = lib/MLX42/

MLX42_LIB = $(MLX42_PATH)build/libmlx42.a -ldl -lglfw -pthread -lm

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit

LIBFT_PATH = lib/libft/

LIBFT_LIB = $(LIBFT_PATH)libft.a

PRINTF_PATH = lib/ft_printf/

PRINTF_LIB = $(PRINTF_PATH)libftprintf.a

OBJECTS = $(SRCS_PREFIXED:.c=.o)

all: SUBSYSTEMS $(NAME)

SUBSYSTEMS:
		@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build && make -C $(MLX42_PATH)/build -j4
		@make -C $(LIBFT_PATH) all -s
		@make -C $(PRINTF_PATH) all -s
		@echo

%.o : %.c Makefile $(INCLUDE)
	@printf "\033[0;32mCompling: $<\n\e[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS) Makefile $(INCLUDE)
	@echo
	@printf "\033[0;32mCompling $(NAME)...\n\e[0m"
	@echo
	@$(CC) $(CFLAGS) $(OBJECTS) $(MLX42_LIB) $(LIBFT_LIB) $(PRINTF_LIB) -o $(NAME)
	@printf "\033[0;32mFinished $(NAME)\n\e[0m"

norm:
	norminette lib/libft lib/ft_printf src include

clean:
	@make -C $(LIBFT_PATH) clean -s
	@make -C $(PRINTF_PATH) clean -s
	@rm -rf $(MLX42_PATH)build
	@printf "\033[0;31mMLX Cleaning process done!\n\e[0m"
	@rm -f $(OBJECTS)
	@printf "\033[0;31mCleaning process done!\n\e[0m"

fclean:
	@make -C $(LIBFT_PATH) fclean -s
	@make -C $(PRINTF_PATH) fclean -s
	@rm -rf $(MLX42_PATH)build
	@rm -f $(OBJECTS)
	@printf "\033[0;31mMLX Cleaning process done!\n\e[0m"
	@rm -f $(NAME)
	@printf "\033[0;31mFile cleaning process done!\n\e[0m"

re: fclean all

.PHONY: all clean fclean re norm