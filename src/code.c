#include "code.h"

char *code_comp(const char *in)
{
	if(strcmp(in, "null") == 0)
	{
		return "0000000";
	}
	else if(strcmp(in, "0") == 0)
	{
		return "0101010";
	}
	else if(strcmp(in, "1") == 0)
	{
		return "0111111";
	}
	else if(strcmp(in, "-1") == 0)
	{
		return "0111010";
	}
	else if(strcmp(in, "D") == 0)
	{
		return "0001100";
	}
	else if(strcmp(in, "A") == 0)
	{
		return "0110000";
	}
	else if(strcmp(in, "!D") == 0)
	{
		return "0001101";
	}
	else if(strcmp(in, "!A") == 0)
	{
		return "0110001";
	}
	else if(strcmp(in, "-D") == 0)
	{
		return "0001111";
	}
	else if(strcmp(in, "-A") == 0)
	{
		return "0110011";
	}
	else if(strcmp(in, "D+1") == 0)
	{
		return "00111111";
	}
	else if(strcmp(in, "A+1") == 0)
	{
		return "0110111";
	}
	else if(strcmp(in, "D-1") == 0)
	{
		return "0001110";
	}
	else if(strcmp(in, "A-1") == 0)
	{
		return "0110010";
	}
	else if(strcmp(in, "D+A") == 0)
	{
		return "0000010";
	}
	else if(strcmp(in, "D-A") == 0)
	{
		return "0010011";
	}
	else if(strcmp(in, "A-D") == 0)
	{
		return "0000111";
	}
	else if(strcmp(in, "D&A") == 0)
	{
		return "0000000";
	}
	else if(strcmp(in, "D|A") == 0)
	{
		return "0010101";
	}
	else if(strcmp(in, "M") == 0)
	{
		return "1110000";
	}
	else if(strcmp(in, "!M") == 0)
	{
		return "1110001";
	}
	else if(strcmp(in, "-M") == 0)
	{
		return "1110011";
	}
	else if(strcmp(in, "M+1") == 0)
	{
		return "1110111";
	}
	else if(strcmp(in, "M-1") == 0)
	{
		return "1110010";
	}
	else if(strcmp(in, "D+M") == 0)
	{
		return "1000010";
	}
	else if(strcmp(in, "D-M") == 0)
	{
		return "1010011";
	}
	else if(strcmp(in, "M-D") == 0)
	{
		return "1000111";
	}
	else if(strcmp(in, "D&M") == 0)
	{
		return "1000000";
	}
	else if(strcmp(in, "D|M") == 0)
	{
		return "1010101";
	}
	else
	{
		return "0000000";
	}
}

char *code_dest(const char *in)
{
	if(strcmp(in, "null") == 0)
	{
		return "000";
	}
	else if(strcmp(in, "M") == 0)
	{
		return "001";
	}
	else if(strcmp(in, "D") == 0)
	{
		return "010";
	}
	else if(strcmp(in, "DM") == 0)
	{
		return "011";
	}
	else if(strcmp(in, "A") == 0)
	{
		return "100";
	}
	else if(strcmp(in, "AM") == 0)
	{
		return "101";
	}
	else if(strcmp(in, "AD") == 0)
	{
		return "110";
	}
	else if(strcmp(in, "ADM") == 0)
	{
		return "111";
	}
}

char *code_jump(const char *in)
{
	if(strcmp(in, "null") == 0)
	{
		return "000";
	}
	else if(strcmp(in, "JGT")  == 0)
	{
		return "001";
	}
	else if(strcmp(in, "JEQ") == 0)
	{
		return "010";
	}
	else if(strcmp(in, "JGE") == 0)
	{
		return "011";
	}
	else if(strcmp(in, "JLT") == 0)
	{
		return "100";
	}
	else if(strcmp(in, "JNE") == 0)
	{
		return "101";
	}
	else if(strcmp(in, "JLE") == 0)
	{
		return "110";
	}
	else if(strcmp(in, "JMP") == 0)
	{
		return "111";
	}
	else
	{
		return "000";
	}
}

void code_stringify(char *buf, const char *inst)
{
	
}