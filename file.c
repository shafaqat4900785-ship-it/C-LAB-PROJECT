#include<stdio.h>
int main (void){
   FILE *fp= fopen("data.txt","w");
   if(fp==NULL)
   {
    printf("the file didnot open \n");
    return 1;}
    fprintf(fp,"rich dad poor dad,trump,20,4\n c programing,hunain,20,5\n,rock n royals, barbie,45,5\n");
    fclose(fp);
   }
