# Reflections on trusting trust (Ken Thompson) - code

## Origin of the example code

Ken Thompson's "cc hack" - Presented in the journal, Communication of the ACM,
Vol. 27, No. 8, August 1984, in a paper entitled ["Reflections on Trusting Trust"](https://www.ece.cmu.edu/~ganger/712.fall02/papers/p761-thompson.pdf),
Ken Thompson, co-author of UNIX, recounted a story of how he created a version
of the C compiler that, when presented with the source code for the "login" program,
would automatically compile in a backdoor to allow him entry to the system.

This is only half the story, though. In order to hide this trojan horse, Ken also
added to this version of "cc" the ability to recognize if it was recompiling itself
to make sure that the newly compiled C compiler contained both the "login" backdoor,
and the code to insert both trojans into a newly compiled C compiler.

In this way, the source code for the C compiler would never show that these trojans existed. 

## Self replicating code

I took the code from Ken Thompson's *Figure 1* and modified it to emit
the program keeping the quoted character style in the string `s`.

The source is in `trusttrust.c`.

Another small piece of code in `trust.c` is used generate the array of characters
after you modified the body of `trusttrust.c`.

```
$ make trust
$ ./trust >s.txt
```
After that edit `trusttrust.c` and paste the contents of the file `s.txt` to
replace the previous code. Finally

```
$ make
$ ./trusttrust
```

should then reproduce itself - or does it?

```
$ ./trusttrust | cc -o tt2 -x c -
$ ./tt2
```
