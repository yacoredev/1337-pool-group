# Tool kayautomatisi compilation.
# Bla ma nktb cc/ar/rm kol mra b yeddi.

# A target is simply a name that make knows how to build or execute
# momkin ykon:
# file:		path/file:		executable:		phony command (clean, re..):

# target: dependencies		example: libft.a: ft_putchar.o ft_strlen.o
#		command							ar rcs libft.a ft_putchar.o ft_strlen.o
#										(libft.a ma ttsawbch 7ta ykono .o wajdin)

# compile: .c -> .o
# link: .o -> executable	or .o -> library
# static Library -> libft.a Archive of object files.

# -I includes	-> kay9ol lcompiler qleb 3la headers hna

# Dependency Management: gher lfiles li tbdlat hya li tcompila bo7dha
# timestamp: hya bach kay3rf make wach y3awd ycompile
#			 if .c newer than .o dyalo 3awd compile (rebuild)
#			 if .o newer than .c dyalo maydir walo
#
# should not compile any file for nothing: y3ni dependency system khaso ykhdem

# variables:
# CC = cc						use it	-->		$(CC)
# CFLAGS = -Wall -Wextra -Werror
# SRCS = srcs/ft_putchar.c srcs/ft_swap.c

# Pattern Rule:
# Any .o file can be built from it's .c file
# with the same path and name.
# '%' is replaced by the common part.
#
# %.o: %.c
#		cc -Wall -Wextra -Werror -c $< -o $@
#
# $<   (first dependency) (%.c)
# $@   (target)	(%.o)

# clean  -> remove intermediate files (.o)
# fclean -> clean + remove final product (.a / executable)
# re	 -> build everything from scratch (rebuild)
# example:		re:
#					make fclean
#					make all
# make re
# 1. delete .o and libft.a
# 2. compile all .c
# 3. recreate all .o
# 4. recreate libft.a

# Substitution Reference: replace .c extension with .o for every word in SRCS.
# Example: SRCS = main.c  utils.c
# OBJS = $(SRC:%.c=%.o)		==>		OBJS = main.o utils.o
# mn ba3d hna kyt3tabro dependencies
# libft.a: $(OBJS)				==>		libft.a: main.o utils.o

# kansta3ml variables bach yb9a Makefile sahl flmaintenance
NAME = libft.a
HDR = includes

# '\' Line Continuation
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c \
	srcs/ft_strcmp.c
OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

# dima rule lwla hya default rule li katexecute fach kadir make bo7dha
all: $(NAME)

# ila tremplasaw .o files ghayhbat make y9lab kifach ysawbhom 3ad yrja3 ykml
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

# Pattern Rule:
# Compile .c files
# katchanga:
# %.o  => srcs/ft_putchar.o : %.c  => srcs/ft_putchar.c ...
# $<	srcs/ft_putchar.c
# $@	srcs/ft_putchar.o
# -I	khsha path machi file direct
%.o: %.c
	$(CC) $(FLAGS) -I $(HDR) -c $< -o $@

clean:
	rm -f $(OBJS)
# -f remove without asking

fclean: clean
	rm -f $(NAME)

re: fclean all

# Set files bhad names: all, clean, ... as fake targets
# Always run these rules, wakha kan chi file fdir bnafs smya dyal 're' matalan
# Prevent conflicts with files of the same name
.PHONY: all clean fclean re