Run

    /quine.py < pre_quine.c  > quine.c

to get quine.c which will print it's own source code when compiled

    gcc -Wall -std=c99 -o quine quine.c

and run:

    /quine

Not convinced? Check with:

    ./quine | diff quine.c -