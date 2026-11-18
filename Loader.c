#include <stdio.h>
#include "Loader.h"

//--------------------------->GLOBAL VARIABLES<---------------------------------

struct Book books[50];
int Book_id;
int bookcounter;
float totalSales;

//-------------------------------->INITIALIZE FILE<------------------------------------
void Initializefile(void){
    FILE *fp = fopen("books.dat","ab");//it creates the book.dat file if it doesnot exist 
    if(fp==NULL){
        printf("The file could not be created\n");
        return;
    }
    fclose(fp); //if books.dat already exists,it leaves the exisiting content still intact
}
//-------------------------------->LOAD FILE<------------------------------------
void Loadfile(void){
    FILE *fp=fopen("books.dat","rb");
    if(fp==NULL){
    printf("The file could not be opened");
    bookcounter=0;
    return;
    }
    else{
        bookcounter = fread(books,sizeof(struct Book),50,fp);
        fclose(fp);
    }                             
}
//-------------------------------->SAVE FILE<------------------------------------
void Savefile(void){
    FILE *fp = fopen("books.dat","wb");
    if(fp==NULL){
        printf("The file could not be opened\n");
        return;
    }
    fwrite(books,sizeof(struct Book),bookcounter,fp);
    fclose(fp); //wb writes the previous content of file with the new content 
}        
//--------------------------------->SAVE SALES<------------------------------------
void saveSales(void){
    FILE *fp = fopen("saves.dat","wb");
    if(fp==NULL){
        printf("Error saving total sales.\n");
        return;
    }
    fwrite(&totalSales,sizeof(float),1,fp);
    fclose(fp);
}
//--------------------------------->LOAD SALES<------------------------------------
void loadSales(void){
    FILE *fp = fopen("saves.dat","rb");
    if(fp==NULL){
        printf("No previous sales data found. starting with total sales as 0.\n");
        totalSales=0;
        return;
    }
    if(fread(&totalSales,sizeof(float),1,fp)!=1)
    {
        printf("Error loading total sales...\nTotal sales have been reset to zero!\n");
        totalSales=0;
    }
    fclose(fp);
}