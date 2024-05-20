/* A small test for atoi. Assumes twos complement */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <errno.h>



#define outfile stderr



static unsigned int Failures = 0;



static void CheckAtoi (const char* Str, int Val)
{
    int Res = atoi (Str);
    if (Res != Val) {
        fprintf (outfile, "atoi error in \"%s\":\n"
                          "  result = %d, should be %d\n", Str, Res, Val);
        ++Failures;
    }
}



int main (void)
{
    CheckAtoi ("\t +0A", 0);
    CheckAtoi ("\t -0.123", 0);
    CheckAtoi ("  -32  ", -32);
    CheckAtoi (" +32  ", 32);
    CheckAtoi ("0377", 377);
    CheckAtoi (" 0377 ", 377);
    CheckAtoi (" +0377 ", 377);
    CheckAtoi (" -0377 ", -377);
    CheckAtoi ("0x7FFF", 0);
    CheckAtoi (" +0x7FFF", 0);
    CheckAtoi (" -0x7FFF", 0);
    fprintf (outfile, "Failures: %u\n", Failures);
    return (Failures != 0);
}
