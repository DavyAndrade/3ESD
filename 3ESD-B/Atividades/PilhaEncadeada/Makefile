CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c11
TARGET = pilha_encadeada

SRC = main.c pilha_encadeada.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

.PHONY: all run clean
