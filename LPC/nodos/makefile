# Makefile para compilar archivos en el directorio actual
# nombre del ejecutable deseable en mayusculas

TARGET = RUN
# Bibliotecas incluidas, la biblioteca math.h es una muy común
LIBS = -lm

CC = g++

CFLAGS = -g -Wall

.PHONY: default all clean
default: $(TARGET)
all: default

OBJECTS = $(patsubst %.cpp, %.o, $(wildcard *.cpp))

HEADERS = $(wildcard *.h)

%.o: %.cpp $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) $(LIBS) -o $@

clean:
	-rm -f *.o core
cleanall: clean
	-rm -f $(TARGET)
