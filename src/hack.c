#include "parser.h"
#include "code.h"

char *strip_ext(char *fname);
void remove_spaces(char* s);

int main(int argc, char *argv[])
{
	//Check if correct arguments
	if(argc < 2)
	{
		printf("Usage: HackAssembler <ASM File>\n");
		
		return 1;
	}
	
	//Declare and Initialize I/O files
	Parser *par;
	FILE *out;
	char binStr[20];
	const char tok[3] = ";=";
	char *instBuf; //For splitting the instruction
	
	par = parser_init(argv[1]);
	
	//Error check, else output
	if(par == NULL)
	{
		printf("FAILED TO OPEN FILE: %s\n", argv[1]);
		
		return 1;
	}
	else
	{
		//Open output file when no error
		out = fopen(strcat(strip_ext(argv[1]), ".hack"), "w");
		
		//Loop: while still has lines in file, advance then put out to file
		while(parser_noMoreLines(par) == 0)
		{
			printf("%d: \n", par->pos);
			
			parser_advance(par);
			remove_spaces(par->currInst);
			
			if((*par).currType == A_INSTRUCTION)
			{
				fputs((*par).currInst, out);
			}
			else if((*par).currType == L_INSTRUCTION)
			{
				fputs((*par).currInst, out);
			}
			else if((*par).currType == C_INSTRUCTION)
			{
				strcpy(binStr, "111");
				
				strcat(binStr, code_comp(parser_comp(par)));
				strcat(binStr, code_jump(parser_jump(par)));
				strcat(binStr, code_dest(parser_dest(par)));
				
				strcat(binStr, "\n");
				fputs(binStr, out);
			}
			
		}
	}
	
	//Close files
	parser_destroy(par);
	fclose(out);
	
	return 0;
}

//Helper function, strip file extension
char *strip_ext(char *fname)
{
	char *fn = fname;
    char *end = fn + strlen(fn);

    while (end > fn && *end != '.' && *end != '\\' && *end != '/') {
        --end;
    }
    if ((end > fn && *end == '.') &&
        (*(end - 1) != '\\' && *(end - 1) != '/')) {
        *end = '\0';
    }
	
	return fn;
}

void remove_spaces(char* s) {
    char* d = s;
    do {
        while (*d == ' ') {
            ++d;
        }
    } while (*s++ = *d++);
}