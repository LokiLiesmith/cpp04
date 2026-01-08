# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrazem <mrazem@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/07 01:47:24 by mrazem            #+#    #+#              #
#    Updated: 2026/01/08 17:04:03 by mrazem           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -g -std=c++98

SRC			:= main.cpp AMateria.cpp Cure.cpp Ice.cpp
NAME		:= interface
OBJDIR		:= obj
OBJ			:= $(SRC:%.c=$(OBJDIR)/%.o)


all: $(NAME)
$(NAME): $(OBJ)
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled. \nrun with: ./$(NAME)"

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CXX) $C(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Clean rules
clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all
.PHONY: all clean fclean re