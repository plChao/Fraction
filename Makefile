CC = g++
tar = Fraction.out
LIB = std=c++11
CFLAG = g -Wall
all:$(tar)

$(tar):Fraction.h Fraction.cpp main.cpp
	$(CC) -$(LIB) -$(CFLAG) $^ -o $@
clean:
	rm $(tar)