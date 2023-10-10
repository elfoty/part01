exec = hello.out
sources = $(wildcard src/*.c)
objects = $(sources:.c=.o)
flags = -g

$(exec): $(objects)
	gcc $(objects) $(flags ) -o $(exec)

%.o: %.c include/%.h
	gcc -c $(flags) $< -o $@

install:
	make
	copy hello.out "/Program Files (x86)/hello"

clean:
	for %i in (*.out) do del %i
	for %i in (*.o) do del %i
	for %i in (src\*.o) do del %i
