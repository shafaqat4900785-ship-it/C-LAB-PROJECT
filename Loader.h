#ifndef LOADER_H
#define LOADER_H
//------------------------------>BOOK STRUCTURE<--------------------------------

struct Book{
    int Book_id;
    char Title[100];
    char Author[100];
    char genre[100];
    float Price;
    int Quantity;
};

//--------------------------->GLOBAL VARIABLES<---------------------------------

extern struct Book books[50];
extern int Book_id;
extern int bookcounter;
extern float totalSales;

//--------------------------->FUNCTION DECLARATIONS<----------------------------

void saveSales(void);
void loadSales(void);
void Loadfile(void);
void Initializefile(void);
void Savefile(void);

#endif