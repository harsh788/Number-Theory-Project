CC = g++
TARGET = assignment1
$(TARGET): main.cpp addition.cpp subtraction.cpp multiplication.cpp division.cpp pi.cpp real.cpp squareroot.cpp
	$(CC) main.cpp addition.cpp subtraction.cpp multiplication.cpp division.cpp pi.cpp real.cpp squareroot.cpp -o ./$(TARGET)

