CXX 	 = clang++
CPPFLAGS = -std=gnu++11 -ggdb -Wall -Werror
SLIBS 	 = -lSDL2 -lSDL2_image

DBG		 = gdb
VAL 	 = valgrind
RMV 	 = rm

compile:
	$(CXX) $(CPPFLAGS) *.cpp $(SLIBS) -o Test

test:
	./Test

gdb:
	$(DBG) ./Test

valgrind:
	$(VAL) ./Test

clean:
	$(RMV) ./Test
