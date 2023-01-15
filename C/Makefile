SRC = fft.h fft.c

default : $(SRC) FFT32.c
	@gcc -o FFT32 $(SRC) FFT32.c -lm
	@./FFT32

debug : $(SRC) FFT32.c
	@gcc -g -o FFT32 $(SRC) FFT32.c -lm
	@gdb ./FFT32

clean : 
	@rm FFT32