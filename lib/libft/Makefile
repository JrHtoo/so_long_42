SRCS =	ft_bzero.c		\
		ft_strlen.c		\
		ft_strchr.c		\
		ft_calloc.c		\
		ft_strdup.c		\
		ft_substr.c		\
		ft_strjoin.c 	\
		get_next_line.c \
		ft_line_length.c \
		ft_count_line.c  \
		ft_count_char.c \
		ft_printmap.c \
		ft_itoa.c
		
OBJS_DIR = objs/
OBJS	 = $(SRCS:.c=.o)
SRCS_OBJS = $(addprefix $(OBJS_DIR), $(OBJS))

NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wextra -Wall
ARCHIVE = ar
ARFLAGS = -rcs

all: $(OBJS_DIR) $(NAME)

$(OBJS_DIR): $(INCLUDE) Makefile
	@printf "\033[0;32mMaking libft.....\n\e[0m"
	@$(CC) $(CFLAGS) -c $(SRCS)
	@mkdir -p $@
	@mv *.o $@

$(NAME): $(SRCS)
	@$(ARCHIVE) $(ARFLAGS) $(NAME) $(SRCS_OBJS)
	@printf "\033[0;32mLibft library complete!\n\e[0m"


clean:
	@rm -rf $(OBJS_DIR)
	@printf "\033[0;31mLIBFT : Cleaning process done!\n\e[0m"

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@printf "\033[0;31mLIBFT : File cleaning process done!\n\e[0m"

re: fclean all

.PHONY: clean fclean re all bonus
