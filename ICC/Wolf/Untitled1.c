#include <stdio.h>
#include <string.h>

#define MAXC 1000

int main (int argc, char **argv) {

    if (argc < 3) { /* validate 2 arguments given */
        fprintf (stderr, "error: insufficient input.\n"
                        "usage: %s file1 file2\n", argv[0]);
        return 1;
    }

    char buf1[MAXC] = "",               /* declare buf1 */
         buf2[MAXC] = "";               /* declare buf2 */
    FILE *f1 = fopen (argv[1], "r"),    /* open file 1 */
         *f2 = fopen (argv[2], "r");    /* open file 2 */

    if (!f1) {  /* validate file 1 open for reading */
        fprintf (stderr, "file open failed '%s'\n", argv[1]);
        return 1;
    }

    if (!f2) {  /* validate file 2 open for reading */
        fprintf (stderr, "file open failed '%s'\n", argv[2]);
        return 1;
    }

    while (fgets (buf1, MAXC, f1)) {    /* read each word in file 1 */
        size_t len1 = strlen (buf1);    /* get length */

        if (len1 && buf1[len1 - 1] == '\n')
            buf1[--len1] = 0;       /* overwrite '\n' with nul-byte */

        while (fgets (buf2, MAXC, f2)) {    /* read each in file 2 */
            size_t len2 = strlen (buf2);

            if (len2 && buf2[len2 - 1] == '\n')
                buf2[--len2] = 0;   /* overwrite '\n' with nul-byte */

            if (len1 != len2)       /* if lengths differ, not equal */
                continue;           /* get next word from file 2 */

            if (strcmp (buf1, buf2) == 0)   /* compare strings */
                printf ("%s\n", buf1);      /* print if equal */
        }
        rewind (f2);    /* rewind f2, clear EOF */
    }
    fclose (f1);    /* close f1 */
    fclose (f2);    /* close f2 */

    return 0;
}
