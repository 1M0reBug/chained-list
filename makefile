EXEC = chained-lists # [NOM DE L'EXE]
CXX = gcc
OPTION = -Wall -Wextra

#Path
PATH_INC = includes
PATH_SRC = src
PATH_OBJ = obj

#Directories
OBJ_DIR = obj


#Liste fichiers .cpp et .O
SRC = $(wildcard $(PATH_SRC)/*.c)
OBJ = $(SRC:$(PATH_SRC)/%.c=$(PATH_OBJ)/%.o)

#Actions
all : $(EXEC)
	./$(EXEC)

debug : $(EXEC)
	gdb ./$(EXEC)

valgrind: $(EXEC)
	valgrind ./$(EXEC)

$(PATH_OBJ)/%.o : $(PATH_SRC)/%.c
	$(CXX) $(OPTION) -o $@ -c $< -I$(PATH_INC)

$(EXEC) : $(OBJ)
	@echo "\033[32m[Link] $(EXEC)\033[00m"
	$(CXX) $(OPTION) -o $@ $^

clean :
	@echo "Suppression des .o et fichiers temporaires"
	@find . -name '*.o' -exec rm  {} \;
	@find . -name '*~' -exec rm  {} \;

init :
	mkdir -p obj

.PHONY: clean init debug valgrind all
