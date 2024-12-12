# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddo-carm <ddo-carm@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 22:42:52 by ddo-carm          #+#    #+#              #
#    Updated: 2024/12/12 22:42:52 by ddo-carm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
TEST_NAME = printf_test.a
CFLAGS = -Wall -Wextra -Werror
SRCS_D = .
HEADERS = .

#source files
SRC = 

MAIN = $(SRCS_D)/main.c

#object files
OBJ = $(SRC:.c=.o)
OBJ_MAIN = $(MAIN:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@clear
	@echo "$(BGRN)✨compilation completed✨"

%.o: %.c
	@cc $(CFLAGS) -I $(HEADERS) -c $< -o $@
	@echo "$(BMAG)Compiling..."
	@sleep 0.4
	@clear

#remove .o
clean:
	@rm -f $(OBJ)
	@echo "$(BMAG@ar rcs)✨objects removed $(BGRN)successfully✨"

#clean and remove
fclean: clean
	@rm -f $(NAME)
	@echo "$(BMAG)✨program removed $(BGRN)successfully✨"

#remake
re: fclean all
	@echo "$(BMAG)✨clean and re-compile was $(BGRN)successfull✨"

#TESTING
test: all
	@cc $(CFLAGS) $(MAIN) $(SRC) -o $(TEST_NAME)
	@clear
	@echo "$(BGRN)✨test completed✨"
	@./$(TEST_NAME)

cleantest:
	@rm -f $(OBJ_MAIN) $(TEST_NAME)
	@echo "$(BMAG)✨test removed $(BGRN)successfully✨"

retest: cleantest test
	@echo "$(BMAG)✨clean test and retest was $(BGRN)successfull✨"

#help
help:
	@echo "✳$(BMAG) make  $(BWHI)    -> $(BMAG)compiles the lib"
	@echo "$(BWHI)✳$(BMAG) test      $(BWHI)-> $(BMAG)compiles the lib with the main"
	@echo "$(BWHI)✳$(BMAG) clean    $(BWHI) -> $(BMAG)removes all objects"
	@echo "$(BWHI)✳$(BMAG) fclean    $(BWHI)-> $(BMAG)removes all objects plus the program"
	@echo "$(BWHI)✳$(BMAG) re        $(BWHI)-> $(BMAG)removes all objects plus the program and recompiles the lib"
	@echo "$(BWHI)✳$(BMAG) cleantest $(BWHI)-> $(BMAG)removes all test files"
	@echo "$(BWHI)✳$(BMAG) retest    $(BWHI)-> $(BMAG)removes test files and recompiles"

#Phony targets to avoid clashes
.PHONY: all clean fclean re cleantest retest help

#color list for foreground
#bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'

BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
YEL		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
MAG		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 7)
GRE		= $(shell tput setaf 8)
BRED 	= $(shell tput setaf 9)
BGRN	= $(shell tput setaf 10)
BYEL	= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
BWHI	= $(shell tput setaf 15)