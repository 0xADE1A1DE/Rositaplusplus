CC=gcc
CFLAGS=
DEPS = present.h share.h present_share.h present_table.h
OBJ = present.o share.o

all: present_table

present_table: $(OBJ) present_table.o
	$(CC) -o $@ $^ $(CFLAGS)

#present: $(OBJ) present_share.o
#	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm present.o
	rm share.o
	rm present_table.o
	rm present_table
