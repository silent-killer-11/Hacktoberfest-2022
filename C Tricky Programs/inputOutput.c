#include <stdio.h>
int main(void){
   FILE *code;
   char ch;
   code= fopen(__FILE__, "r");
   do{
      ch=fgetc(code);
      printf("%c", ch);
   }
   while(ch!=EOF);
      fclose(code);
   return 0;
}
