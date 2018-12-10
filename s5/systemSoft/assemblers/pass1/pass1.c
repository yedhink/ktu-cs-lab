#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	int i, j=0, symtab_flag, optab_flag, error_flag,  locctr, starting_addr, symtab_locctr, length, program_length;
	char label[20], opcode[20], operand[20], symtab_label[20], optab_opcode[20], optab_operand[20];
	FILE *input_file, *symtab_file, *intr_file, *optab_file, *pass1_pass2_file;
	input_file = fopen("input_text", "r+");
	intr_file = fopen("pass1_intermeditate", "w+");
	optab_file = fopen("../optab", "r+");
	symtab_file = fopen("pass1_symtab", "w+");
	pass1_pass2_file = fopen("pass1_pass2", "w+");
	fscanf(input_file, "%s %s %s", label, opcode, operand);
	if(strcmp(opcode, "start")==0)
	{
		starting_addr = atoi(operand);
		locctr = starting_addr;
		fprintf(intr_file, "%s %s %s\n", label, opcode, operand);
		fscanf(input_file, "%s %s %s", label, opcode, operand);
	}
	else
	{
		starting_addr = 0;
		locctr = starting_addr;
	}
	while(strcmp(opcode, "end")!=0)
	{
		symtab_flag = 0;
		error_flag = 0;
                optab_flag = 0;
		fprintf(intr_file, "%d ", locctr);
		if(strcmp(label, ".")!=0)
		{
			if(strcmp(label, "**")!=0)
			{
				while(fscanf(symtab_file, "%s %d", symtab_label, symtab_locctr)!=EOF)
				{
					if(strcmp(label, symtab_label)==0)
					{
						symtab_flag = 1;
						break;
					}
				}
				if(symtab_flag==0)
				{
					fprintf(symtab_file, "%s %d\n", label, locctr);
				}
			}
			while(fscanf(optab_file, "%s %s", optab_opcode, optab_operand)!=EOF)
			{
				if(strcmp(opcode, optab_opcode)==0)
				{
					optab_flag=1;
					break;
				}
			}
			if(optab_flag==1)
			{
				locctr += 3;
			}
			else if(strcmp(opcode, "word")==0)
			{
				locctr += 3;
			}
			else if(strcmp(opcode, "resw")==0)
			{
				locctr += (3*(atoi(operand)));
			}
			else if(strcmp(opcode, "resb")==0)
			{
				locctr += (atoi(operand));
			}
			else if(strcmp(opcode, "byte")==0)
			{
				if(operand[0]=='x')
				{
					locctr += 1;
				}
				else if(operand[0]=='c')
				{
					length = strlen(operand-3);
					locctr += length;
				}
			}
			else
			{
				error_flag = 1;
			}
		}
		fprintf(intr_file, "%s %s %s\n", label, opcode, operand);
		fscanf(input_file, "%s %s %s", label, opcode, operand);
		rewind(optab_file);
	}
	fprintf(intr_file, "%d %s %s\n", locctr, label, opcode);
	program_length = locctr - starting_addr;
	printf("The program length is %d.\n", program_length);
	fprintf(pass1_pass2_file, "%d", program_length);
	fcloseall();
}
