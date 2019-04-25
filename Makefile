yj: yj.o lab2.o
	g++ -o lab2 lab2.o yj.o

yj.o: yj.cpp yj.h
	g++ -c yj.cpp

lab2.o: lab2.cpp yj.h
	g++ -c lab2.cpp

clean:
	rm yj *.o
