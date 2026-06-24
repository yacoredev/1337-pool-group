# Tool kayautomatisi compilation.
# Bla ma nktb cc/ar/rm kol mra b yeddi.

# target: dependencies		example: libft.a: ft_putchar.o ft_strlen.o
#		command							ar rcs libft.a ft_putchar.o ft_strlen.o
#										(libft.a ma ttsawbch 7ta ykono .o wajdin)

# compile: .c -> .o
# link: .o -> executable	or .o -> library
# static Library -> libft.a Archive of object files.

# -I includes	-> kay9ol lcompiler qleb 3la headers hna

# Dependency Management: gher lfiles li tbdlat hya li tcompila bo7dha
# timestamp: hya bach kay3rf make wach y3awd ycompile
#			 if .c newer than .o 3awd compile (rebuild)
#			 if .c newer than .o maydir walo
#
# should not compile any file for nothing: y3ni dependency system khaso ykhdem

# variables:
# CC = cc						use it	-->		$(CC)
# CFLAGS = -Wall -Wextra -Werror
# SRCS = srcs/ft_putchar.c srcs/ft_swap.c

# Pattern Rule:
# Any .o file can be built from a .c file
# with the same path and name.
# '%' is replaced by the common part.
#
# %.o: %.c
#		cc -Wall -Wextra -Werror -c $< -o $@
#
# $<   (first dependency)
# $@   (target)

# clean  -> remove intermediate files (.o)
# fclean -> clean + remove final product (.a / executable)
# re	 -> build everything from scratch (rebuild)
# example:		re:
#					make fclean
#					make all
# make re
# 1. delete .o
# 2. delete libft.a
# 3. compile all .c
# 4. recreate all .o
# 5. recreate libft.a

SRC = main.c  utils.c
OBJ = $(SRC:%.c=%.j)


build:
	echo $(OBJ)
