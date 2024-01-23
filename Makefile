Name = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
RM = rm -f
INC = cub3d.h
SRC =  mandatory/main.c mandatory/parsing/check_syntax.c mandatory/utils/utils.c mandatory/utils/utils1.c mandatory/utils/utils2.c mandatory/parsing/read_map.c\
		mandatory/parsing/check_directions.c mandatory/parsing/parsing.c mandatory/parsing/map_handling.c mandatory/parsing/closed_map.c\
		mandatory/parsing/floor_cieling.c mandatory/parsing/new_full_map.c 

OBJ = $(SRC:.c=.o)

all: $(Name)

$(Name): $(OBJ)
	$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJ) -o $(Name)

%.o: %.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(Name)

re: fclean all

.PHONY: all clean fclean re
