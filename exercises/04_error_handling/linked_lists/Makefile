EXE = exe.x
CXX = c++
CFLAGS = -I include -g -std=c++11 -Wall -Wextra 

SRC= main.cc src/linked_list.cc src/double_linked_list.cc
OBJ=$(SRC:.cc=.o)
INC = $(wildcard *.h)

all: $(EXE)

clean:
	$(info clean up)
	@rm -rf $(OBJ) $(EXE) src/*~ include/*~ *~ html latex

.PHONY: clean

%.o: %.cc
	$(CXX) -c $< -o $@ $(CFLAGS)

$(EXE): $(OBJ)
	$(CXX) $^ -o $(EXE)

documentation: Doxyfile
	doxygen $^


main.o: include/linked_list.h include/double_linked_list.h
src/linked_list.o: include/linked_list.h
src/double_linked_list.o: include/linked_list.h include/double_linked_list.h

#src/double_linked_list.o: include/linked_list.h  include/double_linked_list.h


format: $(SRC) $(INC)
	@clang-format -i $^ 2>/dev/null || echo "Please install clang-format to run this commands


