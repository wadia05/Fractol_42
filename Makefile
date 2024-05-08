NAME = frac

SRC = $(wildcard src/*.c)

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:.c=.o)
MLX = "./MLX42/build/libmlx42.a"
LDFLAGS = -O3 -Iinclude -lglfw -L"/Users/wait-bab/.brew/Cellar/glfw/3.4/lib"
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
