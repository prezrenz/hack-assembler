#ifndef CODE_H
#define CODE_H

#include <string.h>

char *code_comp(const char *in);
char *code_dest(const char *in);
char *code_jump(const char *in);
void code_stringify(char *buf, const char *inst);

#endif