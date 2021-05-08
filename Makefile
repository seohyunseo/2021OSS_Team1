CC = gcc
CFLAGS = -W -Wall
TARGET = study
OBJECTS = main.c study.o manager.o
all : $(TARGET)
$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^
clean :
	rm *.o study