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
float totalSales=0;



//--------------------------->FUNCTION DECLARATION<-----------------------------
void Add_book(void);
void Delete_book(void);
void Catalog(void);
void Search(void);
void update(void);
void sell(void);
void Loadfile(void);
void Initializefile(void);
void Savefile(void);
void cumulativeSales(void);
void saveSales(void);
void loadSales(void);
void resetSales(void);
//----------------------------------xxxxx----------------------------------------

int main(){
    int option;
//------------------------>FOR LOADING FILES<------------------------------------
Initializefile();  
Loadfile();
loadSales();
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
        printf("| 7.Cumulative Sales                        |\n");
        printf("| 8.Reset Sales                             |\n");
        printf("| 9.Exit                                    |\n");
        if(scanf("%d",&option)!=1){
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            while(getchar()!='\n'); //clear the input buffer //if user enter AB and press enter toh getchar will abosrb A B and the chracter \n and input buffer hence becoemes empty
            option =0;
            continue;
        }

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
                update();
                break;

            case 6:
                printf("Sell book selected.\n");
                sell();
                break;

            case 7:
                printf("Cumulative Sales selected.\n");
                cumulativeSales();
                break;

            case 8:
                printf("Resetting sales.\n");
                resetSales();
                break;

            case 9:
                printf("Exiting.\n");
                break;
            
            default:
                printf("Invalid option! Choose between 1 and 9.\n");
        }
    }while(option!=9);

    return 0;
}

//------------------------------>FUNCTION DEFINATIONS<----------------------------


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
    fread(&totalSales,sizeof(float),1,fp);
    fclose(fp);
}

//--------------------------------->RESET SALES<------------------------------------
void resetSales(void){
    printf("Are you sure you want to reset the sales? This action cannot be undone.(y/n)\n");
char choice;
scanf(" %c",&choice);
if(choice=='y'|| choice=='Y')
{
totalSales=0;
saveSales();
printf("Total sales reset to 0.\n");
}
else
{
    printf("Reset sales cancelled.\n");
}
}
//--------------------------------->ADD BOOK<------------------------------------
void Add_book(void){
    char choice;
    do{
    if(bookcounter==50){
        printf("The Inventory is full");
        return;
    }
    printf("Enter Book ID: \n");
    scanf(" %d", &books[bookcounter].Book_id);
     printf("Enter Book Title: \n");
    scanf(" %99[^\n]", books[bookcounter].Title);
     printf("Enter Book Author: \n");
    scanf(" %99[^\n]", books[bookcounter].Author);
     printf("Enter Book genre : \n");
    scanf(" %99[^\n]", books[bookcounter].genre);
    do{
    printf("Enter Book Price: \n");
    scanf(" %f", &books[bookcounter].Price);
    if(books[bookcounter].Price<=0)
    printf("Invalid price entered. Enter a positive and greater than 0 price.\n");
    }while(books[bookcounter].Price<=0);
    do{
    printf("Enter Book Quantity: \n");
    scanf(" %d", &books[bookcounter].Quantity);
    if(books[bookcounter].Quantity<=0)
    printf("Invalid quantity entered. Enter a positive and greater than 0 quantity.\n");
    }while(books[bookcounter].Quantity<=0);
    bookcounter++;
    Savefile();
    printf("New Entry made succesfully\n");
    printf("Do you want to add another book?(y/n):\n");
    scanf(" %c",&choice);
}while(choice=='Y'|| choice=='y');

}
//-------------------------------->DELETE BOOK<-----------------------------------
void Delete_book(void){
    char choice;
    do{
    printf("Enter the Book ID to be deleted:\n");
    scanf("%d",&Book_id);
     int found=0;
    for(int i=0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id)
        { found=1;
          printf("Book with ID %d exist \n Deleting it...",Book_id);
           for(int j=i;j<bookcounter-1;j++){
            books[j]=books[j+1];
           }
           bookcounter--;
           Savefile();
           printf("Book with ID %d deleted successfully\n",Book_id);
        break;}
    }
    if(found==0){
        printf("Book with Id %d does not exist in the catalog\n",Book_id);
    }
    printf("Do you want to delete another book?(y/n):\n");
    scanf(" %c",&choice);
}while(choice=='y'|| choice=='Y');
}
//---------------------------------->CATALOG<-------------------------------------
void Catalog(void){
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
    printf("Enter the Book ID you want to search:\n");
    scanf("%d",&Book_id);
    int found=0;
    for(int i=0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id){
            found++;
            printf("Book with ID %d exist in the catalog\n",Book_id);
            printf("%d | %s | %s | %s | %.2f | %d\n",books[i].Book_id,books[i].Title,books[i].Author,books[i].genre,books[i].Price, books[i].Quantity);
          break;
        }
    }
    if(found==0){
        printf("Book with Id %d doesnot exist in the catalog\n",Book_id);
    }
}
//----------------------------------->UPDATE<--------------------------------------
void update(void){
    printf("Enter the book ID you want to update:\n");
    if(scanf("%d",&Book_id)!=1){
        printf("Invalid book ID entered.Exiting update record.\n");
        while(getchar()!='\n'); //clears the input buffer
        return;
    }
    int found=0;
    for(int i=0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id){
            found=1;
            printf("Book with ID %d exist in the catalog.\n",Book_id);
            printf("What do you want to update?\n");
            printf("*****UPDATE MENU*****\n");
            printf("     1.Price\n");
            printf("     2.Quantity\n");
            int choice;
            printf("Enter your choice:\n");
            if(scanf("%d",&choice)!=1){
                printf("Invalid choice entered.Exiting update record.\n");
                while(getchar()!='\n'); //clears the input buffer
                return;
            }
            if(choice==1){
                do{ 
                while(1){
                    printf("Enter the new price:\n");
                    if(scanf("%f",&books[i].Price)!=1){
                        printf("Invalid price entered . Enter a numeric value(positive and greater than 0).\n");
                        while(getchar()!='\n'); //clears the input buffer
                        continue;
                    }
                    break;
                }
                if(books[i].Price<=0)
                printf("Invalid price entered.Enter a positive and greater than 0 price.\n");
            }while(books[i].Price<=0);
               Savefile();
               printf("Price updated successfully!\n");
            }
            else if(choice==2){
                do{
                    while(1){
                        printf("Enter the new quantity:\n");
                        if(scanf("%d",&books[i].Quantity)!=1){
                            printf("Invalid quantity entered. Enter a numeric value(positive and greater than 0\n");
                            while(getchar()!='\n'); //clears the input buffer
                            continue;
                        }
                        break;
                    }
                    if(books[i].Quantity<=0)
                    printf("Invalid quantity entered. Enter a positive and greater than 0 quantity.\n");

                }while(books[i].Quantity<=0);
                Savefile();
                printf("Quantity updated successfully!\n");
  
            }
            else
            {printf("Invalid choice.\n");}
            break;
        }
        if(found==0)
        printf("Book with ID %d doesnot exist in the catalog.\n",Book_id);
    } 
}
//---------------------------------->SELL BOOK<------------------------------------
void sell(void){ 
    printf("Enter the Book ID the customer wants to buy:\n");
    scanf("%d",&Book_id);
    int found=0;
    float total=0;
    for(int i =0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id){
            found=1;
            printf("Book with Id %d exist in the catalog\n",Book_id);
            printf("Enter the quantity the customer wants to buy:\n");
            int quantity;
            scanf("%d",&quantity);
            if(quantity<=0){
                printf("Invalid quantity entered. Enter a positive and greater than 0 quantity.\n");
            }
            else if(quantity>books[i].Quantity)
            {
                printf("Not enough quantity in stock. Available quantity : %d\n",books[i].Quantity);
            }
            else
            {
                printf("%d books bought successfully.\n",quantity);
                books[i].Quantity-=quantity;
                Savefile();
                total=books[i].Price*quantity;
                printf("Total price of this purchase order: Rs.%.2f\nAdded to the total annually sales\n",total);
                totalSales+=total;
                saveSales();
            }
            break;
        }
    }
    if(found==0){
            printf("Book with ID %d does not exist in the catalog\n",Book_id);
        }
}
void cumulativeSales(void){
    printf("Cumulative sales as of now: Rs.%.2f\n",totalSales);
}
//-----------------------------xxxxxxxxxxxxxx-------------------------------------