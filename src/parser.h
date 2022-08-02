#ifndef PARSER_H
#define PARSER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef enum instType
{
	NO_INSTRUCTION,
	A_INSTRUCTION,
	C_INSTRUCTION,
	L_INSTRUCTION
} TYPE;


typedef struct parser
{
	FILE *f;
	char currInst[128];
	TYPE currType;
	int pos;
} Parser;


bool parser_noMoreLines(Parser *p);
TYPE parser_instructionType(Parser *p);
char *parser_symbol(Parser *p);
char *parser_dest(Parser *p);
char *parser_comp(Parser *p);
char *parser_jump(Parser *p);
void parser_advance(Parser *p);
Parser *parser_init(const char *file);
void parser_destroy(Parser *p);

#endif