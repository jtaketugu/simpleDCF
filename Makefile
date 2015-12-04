CC = gcc
CFLAGS = -Wall

#prog = prog_mix15s1n1.out
prog = a.out

objs = main.o\
       node.o\
       result.o\
       csma.o\
       util.o\
       ran2.o

$(prog): $(objs)
	$(CC) -o $(prog) $(objs)


#dependency other than .c
main.o: define.h node.h util.h
node.o: define.h node.h
result.o: result.h node.h
csma.o: node.h result.h define.h csma.h
util.o: util.h

clean:
	rm -f $(prog) $(objs)
