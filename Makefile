
# make -C <directorio donde hacer make"

NAME = push_swap

SRC = main.c tools.c

SRC_TEST = maintester.c

OBJ = main.o tools.o

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
	
TEST_5 = 1 5 2 4 3

FIGTH_TEST = 11 111 1 1111 111111 1111111 11111 11111111 \
				2 22222222 2222 222 2222222 222222 22222 \
				3333 333 3 33333 333333 12 3333333 33 \
				4 44 444 4444 44444 444444 4444444 

TEST_100 = 	19 45 21 72 53 76 78 7 84 40 \
			65 44 18 9 37 90 62 63 6 41 \
			60 22 85 38 89 36 17 64 1 93 \
			99 16 23 70 92 25 98 97 4 71 \
			48 49 46 73 82 15 80 77 81 94 \
			52 13 86 35 14 68 91 67 79 0 \
			75 88 56 39 61 0 42 43 24 87 \
			30 31 32 3 26 69 8 95 74 57 \
			29 28 27 34 5 96 83 50 2 11 \
			66 33 58 51 59 12 55 54 47 10 


FT = 11 111 1 1111 111111 1111111 11111 11111111 \
				2 22222222 2222 222 2222222 222222 22222 \

FT2 = 0 9 8 1 2 7 3 4 6 5


test0: fclean
	gcc $(FLAGS) $(SRC_TEST) -o $(NAME)
	./push_swap $(TEST) |./checker_Mac $(TEST)
	./push_swap $(TEST)

test: fclean $(NAME)
	./$(NAME) $(FT) 

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

py10: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (1..10).to_a.shuffle.join(' ')"`

py20: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (-9..10).to_a.shuffle.join(' ')"`

py100: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (-49..50).to_a.shuffle.join(' ')"`

py100+: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (0..100).to_a.shuffle.join(' ')"`

py500: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (-249..250).to_a.shuffle.join(' ')"`

py50: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (1..50).to_a.shuffle.join(' ')"`

py1000: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (-499..500).to_a.shuffle.join(' ')"`

py10000: fclean $(NAME)
	python3 python_visualizer.py `ruby -e "puts (-4999..5000).to_a.shuffle.join(' ')"`