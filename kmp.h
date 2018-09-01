#ifndef __KMP_H__
#define __KMP_H__

void get_prefix_tbl(char *pattern, unsigned int len, unsigned int *prefix_tbl);
int kmp_find(char *text, unsigned int textlen, char *pattern, unsigned int patternlen);
#endif // __KMP_H__
