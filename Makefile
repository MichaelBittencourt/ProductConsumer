######################## Used Files #####################

SRC_FOLDER=src
OBJ_FOLDER=obj
C_SRC=$(wildcard $(SRC_FOLDER)/*.c)
OBJ=$(subst .c,.o,$(subst $(SRC_FOLDER),$(OBJ_FOLDER),$(C_SRC)))
BIN=prog

########################### COMPILE SETTINGS ##########################

CC=gcc
FLAGS=-std=c99 -lpthread

######################### TARGETS #################################

all: objFolder $(BIN)

objFolder:
	@ mkdir -p $(OBJ_FOLDER)

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(FLAGS)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	$(CC) -c $< -o $@ $(FLAGS)

.PHONY: clean all

clean:
	rm -f *~ $(BIN)
	test -e $(OBJ_FOLDER) && rm -f $(OBJ_FOLDER)/*.o && rmdir $(OBJ_FOLDER) || true


