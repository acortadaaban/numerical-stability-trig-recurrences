CC = gcc
CFLAGS = -O2 -Wall

all: trigrec_escr trigrec_temps_err

trigrec_escr: trigrec_escr.c trigrec.c trigrec.h
	$(CC) $(CFLAGS) -o $@ trigrec_escr.c trigrec.c -lm

trigrec_temps_err: trigrec_temps_err.c trigrec.c trigrec.h
	$(CC) $(CFLAGS) -o $@ trigrec_temps_err.c trigrec.c -lm

clean:
	rm -f trigrec_escr trigrec_temps_err

.PHONY: all clean
