
TARGET = pwd-manager
SRC = src
INCLUDE = include

CC = gcc

CFLAGS = -I $(INCLUDE) -std=c99

.PHONY: all
all: info build run

.PHONY: info
info:
	@echo Compiling $(TARGET) ...

.PHONY: build
build:
	$(CC) $(SRC)/main.c $(SRC)/llib/*.c $(SRC)/manager/*.c -o $(TARGET) $(CFLAGS)

.PHONY: clean
clean:
	@rm -f $(TARGET)

.PHONY: run
run:
	@echo Running $(TARGET) ...
	@./$(TARGET)