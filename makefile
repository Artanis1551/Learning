all: encryptTest.exe

encryptTest.exe: encrypt.o
	gcc -Wall encryptTest.exe encrypt.o encryptTest.c

encrypt.o:
	gcc -Wall mStdLibs/mMath.o encrypt.c

clean: 
	rm encrypt.o encryptTest.exe
