SRC = fft.h fft.c

default : $(SRC) Test_Case.c
	@gcc -o FFT32 $(SRC) Test_Case.c -lm
	@./Test_Case

debug : $(SRC) Test_Case.c
	@gcc -g -o Test_Case $(SRC) Test_Case.c -lm
	@gdb ./Test_Case

clean : 
	@rm Test_Case