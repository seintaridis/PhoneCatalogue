#
# In order to execute this "Makefile" just type "make"
#	A. Delis (ad@di.uoa.gr)
#

OBJS 	= main.o list.o hashtable.o invert.o max_min.o 
SOURCE	= main.c list.c hashtable.c invert.c max_min.c
HEADER  = list.h hashtable.h filerecord.h invert.h max_min.h
OUT  	= myphones
CC	= gcc
FLAGS   = -g -c 
# -g option enables debugging mode 
# -c flag generates object code for separate files

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT)

# create/compile the individual files >>separately<< 
main.o: main.c
	$(CC) $(FLAGS) main.c

list.o: list.c
	$(CC) $(FLAGS) list.c

hashtable.o: hashtable.c
	$(CC) $(FLAGS) hashtable.c
invert.o: invert.c
	$(CC) $(FLAGS) invert.c
max_min.o: max_min.c
	$(CC) $(FLAGS) max_min.c

# clean house
clean:
	rm -f $(OBJS) $(OUT)

# do a bit of accounting
count:
	wc $(SOURCE) $(HEADER)
