#include "parser.h"

bool parser_noMoreLines(Parser *p)
{
	return feof((*p).f);
}


TYPE parser_instructionType(Parser *p)
{
	if(strchr((*p).currInst, '(') != NULL)
	{
		return L_INSTRUCTION;
	}
	else if(strchr((*p).currInst, '@') != NULL)
	{
		return A_INSTRUCTION;
	}
	else if(strchr((*p).currInst, '/') == NULL)
	{
		return C_INSTRUCTION;
	}
	else
	{
		return NO_INSTRUCTION;
	}
}

char *parser_symbol(Parser *p)
{
	return "test";
}

char *parser_dest(Parser *p)
{
	static char ret[6];
	
	if(strchr(p->currInst, '=') == NULL)
	{	
		printf("IS NULL\n");
		return "null";
	}
	else
	{
		char tok[2] = "=";
		char *buf;
		
		buf = strtok(p->currInst, tok);
		strcpy(ret, buf);
		
		buf = strtok(NULL, tok);
		
		return ret;
	}
}

char *parser_comp(Parser *p)
{
	puts("TESTING");
	return "null";
}

char *parser_jump(Parser *p)
{
	static char ret[6];
	
	if(strchr(p->currInst, ';') == NULL)
	{	
		printf("IS NULL JUMP\n");
		return "null";
	}
	else if(strchr(p->currInst, ';') != NULL)
	{
		char tok[3] = ";\n";
		char *buf;
		
		buf = strtok(p->currInst, tok);
		buf = strtok(NULL, tok);
		
		strcpy(ret, buf);
		
		buf = strtok(NULL, tok);
		
		return ret;
	}
}

void parser_advance(Parser *p)
{
	fgets((*p).currInst, 128, (*p).f);
	(*p).currType = parser_instructionType(p);
	
	//Skip Comments
	if(((*p).currInst[0] == '/' && (*p).currInst[1] == '/') || (*p).currInst[0] == '\n')
	{
		//Advance again
		parser_advance(p);
	}
	else
	{
		//If not comment, increment
		(*p).pos += 1;
	}
	
}

Parser *parser_init(const char *file)
{
	//Allocate Parser mem and open file
	Parser *p = (Parser *) malloc(sizeof(Parser));
	(*p).f = fopen(file, "r+");
	
	//Error on file opening
	if((*p).f == NULL)
	{
		return NULL;
	}
	
	(*p).currType = NO_INSTRUCTION;
	(*p).pos = 0;
	
	return p;
}

void parser_destroy(Parser *p)
{
	fclose((*p).f);
	free(p);
}