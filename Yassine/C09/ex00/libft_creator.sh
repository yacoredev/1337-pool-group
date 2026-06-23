# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    libft_creator.sh                                   :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybaadi <ybaadi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/19 17:19:51 by ybaadi            #+#    #+#              #
#    Updated: 2026/06/23 18:57:36 by ybaadi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# tells system to execute script using bash
#!/bin/bash

# shell script:
# File fih terminal commands executed automatically line by line.
# Shell: Program that executes terminal commands.

# sh libft_creator.sh: run this script using shell.
# sh: Shell interpreter used to execute shell scripts.

# static library:
# File .a kayjma3 multiple .o object files
# copied into executable at compile time.
# lcode kaytcopa dakhl executable (.out) waqt linking, w maghayb9ach m7taj library

# dynamic library:
# Shared library (.so)
# loaded into memory at runtime.
# lcode kaytloada mn library lmemory waqt execution (runtime), kayb9a m7taj library

# Compilation:
# gcc -c: .c (source code) -> .o (object file)

# Linking:
# combine .o files into executable

# linker:
# Program kay7al function references w yjma3 object files.

# why we use libraries:
# - reuse code
# - avoid recompiling everything
# - organize project better

# command to take all object files and pack them to static library:
# ar rc libft.a *.o
# ar: archive tool
# r, c: replace existing files, create library if not exists

# Important:
# give execution permission to the script before running it with ./
# chmod +x libft_creator.sh

gcc -Wall -Wextra -Werror -c ft_putchar.c  ft_putstr.c  ft_strcmp.c  ft_strlen.c  ft_swap.c
ar rc libft.a ft_putchar.o  ft_putstr.o  ft_strcmp.o  ft_strlen.o  ft_swap.o
rm -f ft_putchar.o  ft_putstr.o  ft_strcmp.o  ft_strlen.o  ft_swap.o