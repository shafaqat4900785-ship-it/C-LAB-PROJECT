#include<stdio.h>
//------------------------------>BOOK STRUCTURE<--------------------------------

struct Book{
    char Title[100];
    char Author[100];
    char genre[100];
    int Book_id;
    int Shelf_no;
};

//--------------------------->GLOBAL VARIABLES<---------------------------------

struct Book books[50];



//--------------------------->FUNCTION DECLARATION<-----------------------------
void Add_book(void);
void Delete_book(void);
void Catalog(void);
void Search(void);
void update(void);
void sell(void);
//----------------------------------xxxxx----------------------------------------

int main(){
    int option;

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
                Add_book();
                break;

            case 2:
                printf("Remove book selected. \n");
                Delete_book();
                break;

            case 3:
                printf("Catalog selected.\n");
                Catalog();
                break;

            case 4:
                printf("Search book selected.\n");
                Search();
                break;

            case 5:
                printf("Update record selected.\n");
                Update();
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

//---------------------------------->ADD BOOK<------------------------------------
void Add_book(void){

}
//-------------------------------->DELETE BOOK<-----------------------------------
void Delete_book(void){

}
//--------------------------------->CATALOG<--------------------------------------
void Catalog(void){

}
//-------------------------------->SEARCH<----------------------------------------
void Search(void){

}
//-------------------------------->UPDATE<----------------------------------------
void Update(void){

}
//------------------------------>SELL BOOK<---------------------------------------
void Sell(void){

}
//-----------------------------xxxxxxxxxxxxxx-------------------------------------