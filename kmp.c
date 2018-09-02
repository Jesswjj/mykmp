#include <stdio.h>
#include <string.h>
#include <stdlib.h>

static unsigned long int kmpcnt = 0;

/* get prefix str*/
void get_prefix_tbl(char *pattern, unsigned int len, unsigned int *prefix_tbl)
{
    unsigned int k, q;
    for(k = 0, q = 1; q < len; q++)
    {
        kmpcnt++;
		while (k > 0 && pattern[k] != pattern[q])
        {
            k = prefix_tbl[k-1];
        }
        if(pattern[k] == pattern[q])
        {
            k++;
        }
        prefix_tbl[q] = k;
        //printf("prefix_tbl[%d]=%d\n", q, prefix_tbl[q]);
    }
}

/* 	use kmp to find str
	text: The Source string to be searched
	pattern: Target string
	return val: error is -1, success is num of place
*/
unsigned long int kmp_find(char *text, unsigned int textlen, char *pattern, unsigned int patternlen)
{
    unsigned int i, q = 0;
    unsigned int *prefix_tbl = (unsigned int*)calloc(sizeof(int), patternlen);

    get_prefix_tbl(pattern, patternlen, prefix_tbl);

    for (i = 0; i < textlen; i++)
    {
        kmpcnt++;

        while (q > 0 && pattern[q] != text[i])
        {
            kmpcnt++;
            q = prefix_tbl[q - 1];
        }

        if (pattern[q] == (text[i]))
            q++;

        if (q == patternlen)
        {
            printf("kmp_find cnt:%ld\n", kmpcnt);
            return i+1-patternlen;
        }
	}

	free(prefix_tbl);

	return -1;
}
