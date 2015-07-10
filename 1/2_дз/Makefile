NAME = 2

all: $(NAME)
$(NAME): $(NAME).o
	g++ $(NAME).o -o run.a
$(NAME).o: $(NAME).cpp
	g++ $(NAME).cpp -c -o $(NAME).o