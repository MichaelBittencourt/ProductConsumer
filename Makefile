######################## Used Files #####################

SRC_FOLDER=src
OBJ_FOLDER=obj
C_SRC=$(wildcard $(SRC_FOLDER)/*.c)
OBJ=$(subst .c,.o,$(subst $(SRC_FOLDER),$(OBJ_FOLDER),$(C_SRC)))
BIN=prog

########################### COMPILE SETTINGS ##########################

CC=gcc
FLAGS:=
CC_FLAGS=-std=c99 -lpthread $(FLAGS)

######################### TARGETS #################################

all: objFolder $(BIN)

objFolder:
	@ mkdir -p $(OBJ_FOLDER)

$(BIN): $(OBJ)
	$(CC) $^ -o $@ $(CC_FLAGS)

$(OBJ_FOLDER)/%.o: $(SRC_FOLDER)/%.c
	$(CC) -c $< -o $@ $(CC_FLAGS)

.PHONY: clean all

clean:
	rm -f *~ $(BIN)
	test -e $(OBJ_FOLDER) && rm -f $(OBJ_FOLDER)/*.o && rmdir $(OBJ_FOLDER) || true


