
PGM = ft_display_file

SRCS = srcs/check.c srcs/display.c srcs/main.c
OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror -I includes

all: $(PGM)

$(PGM): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(PGM)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(PGM)

re: fclean all

.PHONY: all clean fclean re