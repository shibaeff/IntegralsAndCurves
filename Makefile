CC=gcc
CFLAGS=-c -m32 -DNEWTON
LDFLAGS=
SOURCES=test_equation_solver.c  settings.h equation_solver.c test_integration.c test_integration.h common_interface.c\
 common_interface.h integration.c integration.h colors.h asm_functions.h functions.c main.c asm_functions.o
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=curves

all: asm_functions.o $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -m32 $(LDFLAGS) $(OBJECTS) -o $@ -lm

.c.o:
	$(CC) -m32 $(CFLAGS) $< -o $@


asm_functions.o:
	echo "Building nasm" && nasm -f elf32 -o asm_functions.o asm_functions.asm

clean:
	rm -rf *.o curves
