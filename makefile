CC = gcc
CFLAGS = -Wall -Wextra -std=c11
TARGET = explode
SRC = lab1.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

clean:
	rm -f $(TARGET)

