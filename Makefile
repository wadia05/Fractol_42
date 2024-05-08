NAME = fractol
NAME_BONUS = fractol_bonus
SRC = \
    mandatory/color.c \
    mandatory/draw.c \
    mandatory/extra_tools.c \
    mandatory/hooks.c \
    mandatory/int_win.c \
    mandatory/main.c \
    mandatory/mandl_jul_math.c \
	mandatory/help.c
SRCB = \
    bonus/color_bonus.c \
    bonus/draw_bonus.c \
    bonus/extra_tools_bonus.c \
    bonus/hooks_bonus.c \
    bonus/int_win_bonus.c \
    bonus/main_bonus.c \
    bonus/mandl_jul_math_bonus.c \
	bonus/help_bonus.c \
	bonus/zoom_bonus.c


CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)
MLX = "./MLX42/build/libmlx42.a"
LDFLAGS = -O3 -Iinclude -lglfw -L"/Users/wait-bab/.brew/Cellar/glfw/3.4/lib"
FRAMEWORKS = -framework Cocoa -framework OpenGL -framework IOKit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME) 

bonus: $(OBJB)
	$(CC) $(CFLAGS) $(OBJB) $(MLX) $(LDFLAGS) $(FRAMEWORKS) -o $(NAME_BONUS) 

%.o: %.c
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all