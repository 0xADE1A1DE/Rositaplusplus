all: test-2share test-3share test-3share_e
	
test-2share: ../Xoodoo-masked-optimized.c test.c fakeelmo.c
		gcc -g ../Xoodoo-masked-optimized.c test.c fakeelmo.c  -o test-2share

test-3share: ../Xoodoo-masked-3share.c test.c fakeelmo.c
		gcc -g ../Xoodoo-masked-3share.c test.c fakeelmo.c  -o test-3share

test-3share_e: ../Xoodoo-masked-3share_e.c test.c fakeelmo.c
		gcc -c ../Xoodoo-masked-3share_e.c -o Xoodoo-masked-3share_e.o
		gcc -c test.c -o test.o
		gcc -c fakeelmo.c -o fakeelmo.o
		gcc Xoodoo-masked-3share_e.o test.o fakeelmo.o -o test-3share_e
clean:
	rm -f *.o
	rm -f test-*share
