#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int search_symtab(FILE *fp1,char sym[20]){
  char lab[20];
  int val;
  while(fscanf(fp1,"%s %d",lab,&val)!=EOF){
    if(strcmp(sym, lab)==0){
      return val;
    }
  }
  return 0;
}

int len(char *val){
  int l = 0;
  while(*val){
    ++l;
    ++val;
  }
  return l;
}

int main()
{
  int length,address,start,first_executable;
  char found[20];
  int sym_found =0;
  FILE *obj_file, *symtab_file, *intr_file, *optab_file, *pass1_pass2_file;
  char label[20], opcode[20], operand[20];
  intr_file = fopen("../pass1/pass1_intermeditate", "r+");
  obj_file = fopen("pass2_obj_file","w+");
  optab_file = fopen("../optab", "r+");
  symtab_file = fopen("../pass1/pass1_symtab", "r+");
  pass1_pass2_file = fopen("../pass1/pass1_pass2", "r+");

  // read the length prev stored in pass1
  fscanf(pass1_pass2_file,"%d",&length);
  // read the initial value from intermediate file
  fscanf(intr_file, "%s %s %s\n", label, opcode, operand);

  if(strcmp(opcode, "start")==0)
  {
    start = atoi(operand);
    first_executable = start;
    fprintf(obj_file, "H^%s^00%d^00%d\n", label, start, length);
    fscanf(intr_file, "%d %s %s %s\n", &address, label, opcode, operand);
    fprintf(obj_file, "T^00%d^00%d^", start, length);
  }

  char lab[20],val[20];
  int flag = 0;
  while(strcmp(opcode, "end")!=0){
    flag = 0;
    while(fscanf(optab_file,"%s %s",lab,val)!=EOF){
      if(strcmp(opcode, lab)==0) {
        strcpy(found,val);
        flag = 1;
        break;
      }
    }
    if (flag != 1){
      strcpy(found,"0");
    }
    rewind(optab_file);
    if (strcmp(found,"0")!=0){
      fprintf(obj_file, "%s", found);
      sym_found = search_symtab(symtab_file,operand);
      rewind(symtab_file);
      printf("operand = %s \nval = %d\n",operand,sym_found);
      if (sym_found != -1){
        fprintf(obj_file, "%d^", sym_found);
        start = sym_found;
      }
      else{
        start = 0;
        printf("Set error flag..exiting since no symbol in symtab\n");
        exit(0);
      }// found symbol in symtab
    }// found opcode in optab
    else if(strcmp(opcode, "word")==0 || strcmp(opcode, "resw")==0){
      fprintf(obj_file, "00000%d^", atoi(operand));
    }// if opcode is a word or resw
    else if(strcmp(opcode,"byte") == 0){
      for (int i=2;i<len(operand)-1;++i){
        fprintf(obj_file, "%c", operand[i]);
      }
    }// if opcode is byte
    fscanf(intr_file, "%d %s %s %s\n", &address, label, opcode, operand);
  }
  fprintf(obj_file, "\n");
  fprintf(obj_file, "E^00%d", first_executable);
  return 0;
}
