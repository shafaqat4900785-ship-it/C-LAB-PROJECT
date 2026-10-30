#include<stdio.h>
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

struct Book books[50];
int Book_id;
int bookcounter;



//--------------------------->FUNCTION DECLARATION<-----------------------------
void Add_book(int a);
void Delete_book(void);
void Catalog(int a);
void Search(void);
void update(void);
void sell(void);
void Loadfile(void);
//----------------------------------xxxxx----------------------------------------

int main(){
    int option;
//------------------------>FOR LOADING FILES<------------------------------------
    Loadfile();

//----------->MENU(add kar lena more options,this is all i could think of)<------
    do{
        printf("+===========================================+\n");
        printf("|        BOOK SHOP MANAGEMENT SYSTEM        |\n");
        printf("+===========================================+\n");
        printf("| 1.Add new book                            |\n");
        printf("| 2.Remove book                             |\n");
        printf("| 3.Catalog                                 |\n");
        printf("| 4.Search book                             |\n");
        printf("| 5.update record                           |\n");
        printf("| 6.Sell book                               |\n");
        printf("| 7.Exit                                    |\n");
        scanf("%d",&option);

//--------------------------------->SWITCH<--------------------------------------

        switch(option){
            case 1:
                printf("Add a Book selected.\n");
                Add_book(bookcounter);
                break;

            case 2:
                printf("Remove book selected. \n");
                Delete_book();
                break;

            case 3:
                printf("Catalog selected.\n");
                Catalog(bookcounter);
                break;

            case 4:
                printf("Search book selected.\n");
                Search();
                break;

            case 5:
                printf("Update record selected.\n");
                update();
                break;

            case 6:
                printf("Sell book slected.\n");
                sell();
                break;

            case 7:
                printf("Exiting.\n");
                break;


            default:
                printf("Invalid choice. Try again.\n");
        }
    }while(option!=7);

    return 0;
}

//------------------------------>FUNCTION DEFINATIONS<----------------------------


//-------------------------------->LOAD FILE<------------------------------------
void Loadfile(void){
    FILE *fp=fopen("books.dat","rb");
    if(fp==NULL){
    printf("The file could not be opened");
    return ;
    }
    else{
        bookcounter = fread(books,sizeof(struct Book),1,fp);
        fclose(fp);
    }

}


//--------------------------------->ADD BOOK<------------------------------------
void Add_book(int a){
    if(bookcounter==50){
        printf("The Inventory is full");
        return;
    }
    printf("Enter Book ID: \n");
    scanf(" %d", &books[bookcounter].Book_id);
     printf("Enter Book Title: \n");
    scanf(" %[^\n]", books[bookcounter].Title);
     printf("Enter Book Author: \n");
    scanf(" %[^\n]", books[bookcounter].Author);
     printf("Enter Book genre : \n");
    scanf(" %[^\n]", books[bookcounter].genre);
    printf("Enter Book Price: \n");
    scanf(" %f", &books[bookcounter].Price);
    printf("Enter Book Quantity: \n");
    scanf(" %d", &books[bookcounter].Quantity);
    FILE *fp= fopen("books.dat","ab");
    fwrite(&books[bookcounter], sizeof(struct Book), 1,fp);
    fclose(fp);
    bookcounter++;
    printf("New Entry made\n");

}
//-------------------------------->DELETE BOOK<-----------------------------------
void Delete_book(void){

}
//---------------------------------->CATALOG<-------------------------------------
void Catalog(int a){
    if(bookcounter==0){
        printf("The catalog is empty.\n");
        return;
    }
    for(int i = 0; i < bookcounter; i++){
        printf("%d | %s | %s | %s | %.2f | %d\n",books[i].Book_id,books[i].Title,books[i].Author,books[i].genre,books[i].Price, books[i].Quantity);
    }
 
}
//----------------------------------->SEARCH<--------------------------------------
void Search(void){

}
//----------------------------------->UPDATE<--------------------------------------
void update(){

}
//---------------------------------->SELL BOOK<------------------------------------
void sell(void){

}
//-----------------------------xxxxxxxxxxxxxx-------------------------------------