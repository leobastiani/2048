CC=gcc
FLAGS=
CFLAGS=-c $(FLAGS)
LDFLAGS=$(FLAGS)
SOURCES=$(wildcard *.c)
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=2048

all: $(SOURCES) $(EXECUTABLE)
	
run: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

debug: $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS) -DDEBUG
	./$(EXECUTABLE)

test:  $(SOURCES)
	$(CC) $(SOURCES) -o $(EXECUTABLE) $(LDFLAGS) -DDEBUG -DTEST
	./$(EXECUTABLE)

.c.o:
	$(CC) $< -o $@ $(CFLAGS)

clear:
	rm *.o & rm $(EXECUTABLE)