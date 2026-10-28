#include<stdio.h>
int main (void){
    struct Book {
        char Author[100];
        char Title[100];
        float Price;
        int Quantity;
    };
    struct Book books[50];
   FILE *fp= fopen("data.txt","r");
   if(fp==NULL)
   {printf("file not opened\n");
return 1;}
int i=0;
while(i<3 && 
fscanf(fp,"%99[^,],%99[^,],%f,%d",books[i].Author,books[i].Title,&books[i].Price,&books[i].Quantity)==4)
{
    printf("%s |%s |%.2f|%d\n",books[i].Author,books[i].Title,books[i].Price,books[i].Quantity);
    i++;
}
fclose(fp);
return 0;
}