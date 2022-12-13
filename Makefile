
# make -C <directorio donde hacer make"

NAME = push_swap


SRC = main.c

SRC_TEST = maintester.c

OBJ = main.o

LIB = ./lib/libftprintf.a

FLAGS = -Wall -Wextra -Werror


all: $(NAME)

$(NAME):$(OBJ) $(LIB)
	@echo llamada a NAME:
	gcc $(OBJ) $(LIB) -o $(NAME)

$(OBJ):
	@echo llamada a OBJ:
	gcc $(FLAGS) -c $(SRC)

$(LIB):
	
ARG = 2 3 4 1 5

FIGTH_TEST = 11 111 1 1111 111111 1111111 11111 11111111 \
				2 22222222 2222 222 2222222 222222 22222 \
			3333 333 3 33333 333333 12 3333333 33 \
			4 44 444 4444 44444 444444 4444444 

tmake testest0: fclean
	gcc $(FLAGS) $(SRC_TEST) -o $(NAME)
	./push_swap $(ARG) |./checker_Mac $(ARG)
	./push_swap $(ARG)


test: fclean $(NAME)
	./$(NAME) $(FIGTH_TEST) 

test10: fclean $(NAME)
	./$(NAME) 1 111111111 2 22222222 222222 33 1111 555555 555 5555555 

test3: fclean $(NAME)
	./$(NAME) 2 22 222 
test31: fclean $(NAME)
	./$(NAME) 2 222 22 
test32: fclean $(NAME)
	./$(NAME) 22 2 222 
test33: fclean $(NAME)
	./$(NAME) 22 222 2 
test34: fclean $(NAME)
	./$(NAME) 222 2 22
test35: fclean $(NAME)
	./$(NAME) 222 22 2


test5: fclean $(NAME)
	./$(NAME) 22 2222 2 22222 222  


clean:
	rm -f $(OBJ)
	rm -f ./lib/*.o

fclean:clean
	rm -f $(NAME)

push:
	git add .
	git status
	git commit -m "Last Commit"
	git push


pr:
	./push_swap $(FIGTH_TEST)

pelea:
	./push_swap $(FIGTH_TEST) |./checker_Mac $(FIGTH_TEST)