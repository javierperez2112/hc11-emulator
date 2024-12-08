CFLAGS = -Wall -Wpedantic -Werror
HEADERS = hc11.h hc11_inst.h hc11_search.h

main: main.o hc11_mem.o hc11_inst.o hc11_search.o
	gcc main.o hc11_mem.o hc11_search.o hc11_inst.o -o main $(CFLAGS)
	rm -rf *.o

main.o: main.c $(HEADERS)
	gcc main.c -c $(CFLAGS)

hc11_mem.o: hc11_mem.c $(HEADERS)
	gcc hc11_mem.c -c $(CFLAGS)

hc11_inst.o: hc11_inst.c $(HEADERS)
	gcc hc11_inst.c -c $(FLAGS)

hc11_search.o: hc11_search.c $(HEADERS)
	gcc hc11_search.c -c $(FLAGS)