# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelharbi <oelharbi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 18:04:37 by oelharbi          #+#    #+#              #
#    Updated: 2024/03/25 22:10:17 by oelharbi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -O3

M_NAME = fractol

B_NAME = fractol_bonus

HEADER = mandatory/fractol.h

B_HEADER =bonus/fractol_bonus.h

OBJ = mandatory/draw.o mandatory/events.o mandatory/fractol.o mandatory/init_and_utils.o mandatory/parse.o

B_OBJ = bonus/draw_bonus.o bonus/draw2_bonus.o bonus/events_bonus.o bonus/fractol_bonus.o bonus/init_and_utils_bonus.o bonus/parse_bonus.o

all: $(M_NAME)
	@echo "\033[1;32mCompilation Completed Successfully! ✅\033[0;m"

bonus : $(B_NAME)
	@echo "\033[1;32mCompilation Completed Successfully! ✅\033[0;m"

$(M_NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(M_NAME)

$(B_NAME) : $(B_OBJ)
	@$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(B_OBJ) -o $(B_NAME) 

./mandatory/%.o : ./mandatory/%.c $(HEADER)
	@echo "\033[0;34mCompiling $< .\033[0;m"
	@sleep 0.2
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

./bonus/%.o : ./bonus/%.c $(B_HEADER)
	@echo "\033[0;34mCompiling $< .\033[0;m"
	@sleep 0.2
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean:
	@echo "\033[0;31mRemoving object files.\033[0;m"
	@sleep 0.2
	@echo "\033[0;31mRemoving object files.\033[0;m"
	@sleep 0.2
	@rm -f $(OBJ) $(B_OBJ)
	@echo "\033[1;32mCleaning DONE ✅\033[0;m"

fclean: clean
	@echo "\033[0;31mRemoving program.\033[0;m"
	@sleep 0.2
	@rm -f $(OBJ) $(B_OBJ)
	@echo "\033[1;32mDONE ✅\033[0;m"
	@rm -f $(M_NAME) $(B_NAME)

re: fclean all 

.PHONY: clean

#-I /usr/local/include -L /usr/local/lib  -lmlx -framework OpenGL -framework AppKit