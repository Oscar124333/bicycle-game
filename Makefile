# === Makefile ===
CC = gcc
CFLAGS = -Wall -Wextra -MMD -MP

SRC = main.c
OBJ = $(SRC:.c=.o)
DEP = $(OBJ:.o=.d)

main: $(OBJ)
	$(CC) $(OBJ) -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

-include $(DEP)

clean:
	rm -f $(OBJ) $(DEP) main