NAME = repetitive_work
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = \
	main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

INCLUDES = -Iincludes/

OBJ_DIR = obj/

all: $(NAME) $(OBJ_DIR)

#Création des fichiers .o
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

#Création du dossier OBJ_DIR
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#Compilation des fichiers .cpp en .o
$(OBJ_DIR)%.o: %.cpp
	$(CC) $(INCLUDES) $(CFLAGS) -c $< -o $@

#Création du programme
$(NAME): $(OBJ_DIR) $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY = all clean fclean re
