all: trusttrust

trusttrust:	trusttrust.c
	$(CC) -o $@ $<

trust:	trust.c
	$(CC) -o $@ $<

clean:
	rm -f trust trusttrust
