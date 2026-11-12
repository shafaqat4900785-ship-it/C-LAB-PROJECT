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
int sale[50]={0};
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
void bestSell(void);
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
        printf("| 7.Best selling book                       |\n");
        printf("| 8.Cumulative Sales                        |\n");
        printf("| 9.Reset Sales                             |\n");
        printf("| 10.Exit                                   |\n");
        printf("+===========================================+\n");
        printf("Enter choice\n");
        if(scanf("%d",&option)!=1){
            printf("Invalid input! Please enter a number between 1 and 10.\n");
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
            printf("Best selling book selected\n");
                bestSell();
                break;

            case 8:
                printf("Cumulative Sales selected.\n");
                cumulativeSales();
                break;

            case 9:
                printf("Resetting sales.\n");
                resetSales();
                break;


            case 10:
                printf("Exiting.\n");
                break;
            
            default:
                printf("Invalid option! Choose between 1 and 10.\n");
        }
    }while(option!=10);

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
    fwrite(&sale,sizeof(int),50,fp);

    fclose(fp);
}
//--------------------------------->LOAD SALES<------------------------------------
void loadSales(void){
    FILE *fp = fopen("saves.dat","rb");
    if(fp==NULL){
        printf("No previous sales data found. starting with total sales as 0.\n");
        totalSales=0;
        for(int i=0;i<50;i++){
            sale[i]=0;
        }
        return;
    }
    if(fread(&totalSales,sizeof(float),1,fp)!=1)
    {
        printf("Error loading total sales...\nTotal sales have been reset to zero!\n");
        totalSales=0;
    }
    if(fread(sale,sizeof(int),50,fp)!=50){
        for(int i=0;i<50;i++){
            sale[i]=0;
        }
    }
    fclose(fp);
}

//--------------------------------->RESET SALES<------------------------------------
void resetSales(void){
    char choice;
    do{
        printf("Are you sure you want to reset the sales? This action cannot be undone.(y/n)\n");
        scanf(" %c",&choice);
        
    if(choice=='y'|| choice=='Y'){
totalSales=0;
saveSales();
printf("Total sales reset to 0.\n");}
else if(choice=='n' || choice=='N'){
    printf("Reset sales cancelled.\n");}
else{
    printf("Invalid input! Enter (y/n) only\n");
    while(getchar()!='\n');
}}
while(choice!='y'&& choice!='Y' && choice !='n' && choice !='N');
}
//--------------------------------->ADD BOOK<------------------------------------
void Add_book(void){
    char choice;
    do{
    if(bookcounter>=50){
        printf("The Inventory is full");
        return;
    }
    printf("Enter Book ID: \n");
    if(scanf(" %d", &books[bookcounter].Book_id)!=1)
    {
        printf("Invalid book ID entered.\nPlease refrain from entering non-numeric values next time.\nExiting from here...\n");
        while(getchar()!='\n');
        return;
    }
    int duplicate=0;
    for(int i=0;i<bookcounter;i++)
    {
        if(books[i].Book_id==books[bookcounter].Book_id)
        {
            duplicate=1;
            break;
        }
    }
        if(duplicate==1)
        {printf("Book with ID %d already exists.\nCan't proceed further.\nPlease enter a unique book ID next time.\n",books[bookcounter].Book_id);
        return;
        }
     printf("Enter Book Title: \n");
    scanf(" %99[^\n]", books[bookcounter].Title);
     printf("Enter Book Author: \n");
    scanf(" %99[^\n]", books[bookcounter].Author);
     printf("Enter Book genre : \n");
    scanf(" %99[^\n]", books[bookcounter].genre);
    do{
        while(1){
    printf("Enter Book Price: \n");
    if(scanf("%f", &books[bookcounter].Price)!=1)
    {
        printf("Invalid input.Enter a numeric value (positive and greater than 0 price.)\n");
        while(getchar()!='\n');// clearing input buffer
        continue;
    }
    break;
}
    if(books[bookcounter].Price<=0)
    printf("Invalid price entered. Enter a positive and greater than 0 price.\n");
    }while(books[bookcounter].Price<=0);

    do{
        while(1){
    printf("Enter Book Quantity: \n");
    if(scanf(" %d", &books[bookcounter].Quantity)!=1){
        printf("Invalid input.Enter a numeric value (positive and greater than 0 quantity.)\n");
        while(getchar()!='\n');
        continue;
    }
    break;
}
    if(books[bookcounter].Quantity<=0)
    printf("Invalid quantity entered. Enter a positive and greater than 0 quantity.\n");
    }while(books[bookcounter].Quantity<=0);
    sale[bookcounter]=0;
    bookcounter++;
    saveSales();
    Savefile();
    printf("New Entry made succesfully\n");
    printf("Do you want to add another book?(y/n):\n");
    scanf(" %c",&choice);
}while(choice=='Y'|| choice=='y');

}
//-------------------------------->DELETE BOOK<-----------------------------------
void Delete_book(void){
    char choice;
    printf("Enter the Book ID to be deleted:\n");
        if(scanf("%d",&Book_id)!=1){
            printf("Invalid book ID entered.\nPlease refrain from entering non-numeric values next time\n");
            while(getchar()!='\n');
        return;}
     int found=0;
    for(int i=0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id)
        { found=1;
          printf("Book with ID %d exist \n Deleting it...",Book_id);
           for(int j=i;j<bookcounter-1;j++){
            books[j]=books[j+1];
            sale[j]=sale[j+1];
           }
           bookcounter--;
           saveSales();
           Savefile();
           printf("Book with ID %d deleted successfully\n",Book_id);
        break;}
    }
    if(found==0){
        printf("Book with Id %d does not exist in the catalog\n",Book_id);
    }
    printf("Do you want to delete another book?(y/n):\n");
    scanf(" %c",&choice);}
//---------------------------------->CATALOG<-------------------------------------
void Catalog(void){
    if(bookcounter==0){
        printf("The catalog is empty.\n");
        return;
    }
     printf("%-6s | %-25s | %-20s | %-12s | %-10s | %-12s\n",
       "ID", "TITLE", "AUTHOR", "GENRE", "PRICE", "QUANTITY");
printf("--------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < bookcounter; i++){
        printf("%-6d | %-25.25s | %-20.20s | %-12.12s | %10.2f | %12d\n",
    books[i].Book_id,
    books[i].Title,
    books[i].Author,
    books[i].genre,
    books[i].Price,
    books[i].Quantity);
       
    }
 
}
//----------------------------------->SEARCH<--------------------------------------
void Search(void){
    printf("Enter the Book ID you want to search:\n");
    if(scanf("%d",&Book_id)!=1)
    {
        printf("Invalid book ID entered.Please refrain from entering non-numeric values next time.\nExiting from here...\n");
        while(getchar()!='\n');
        return;
    }
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
        printf("Book with ID %d doesnot exist in the catalog\n",Book_id);
    }
}
//----------------------------------->UPDATE<--------------------------------------
void update(void){
    printf("Enter the book ID you want to update:\n");
    if(scanf("%d",&Book_id)!=1){
        printf("Invalid book ID entered.\nPlease refrain from entering non-numeric values next time.\nExiting from here...\n");
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
                            printf("Invalid quantity entered. Enter a numeric value(positive and greater than 0)\n");
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
    }
        if(found==0)
        printf("Book with ID %d doesnot exist in the catalog.\n",Book_id);
     
}
//---------------------------------->SELL BOOK<------------------------------------
void sell(void){ 
    Catalog();
    printf("Enter the Book ID the customer wants to buy:\n");
    if(scanf("%d",&Book_id)!=1)
    {
        printf("Invalid input book ID entered.\nPlease refrain from entering non-numeric values next time.\nExiting from here...\n");
        while(getchar()!='\n');
        return;
    }
    int found=0;
    float total=0;
    for(int i =0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id){
            found=1;
            printf("Book with Id %d exist in the catalog\n",Book_id);
            printf("Enter the quantity the customer wants to buy:\n");
            int quantity;
            if(scanf("%d",&quantity)!=1)
            {
                printf("Invalid input.\nPlease refrain from entering non-numeric values next time.\nExiting from here...\n");
                while(getchar()!='\n');
                return;
            }
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
                sale[i]+=quantity;
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
//-------------------------------->BEST SELLING BOOK<-----------------------------------
void bestSell(void){
    int order[50];
    for(int i=0;i<bookcounter;i++){
        order[i]=i;}
    for(int i=0;i<bookcounter-1;i++){
        for(int j=0;j<bookcounter-1-i;j++){
            if(sale[order[j]]<sale[order[j+1]]){
                int temp=order[j];
                order[j]=order[j+1];
                order[j+1]=temp;
            }
        }
    }
    if(bookcounter==0){
        printf("No books\n");
    }
    else{
    printf("The best selling books are\n");
    printf("%-6s | %-25s | %-20s | %-12s | %-10s | %-12s\n",
       "ID", "TITLE", "AUTHOR", "GENRE", "PRICE", "QUANTITY SOLD");
printf("--------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<bookcounter;i++){
        int index=order[i];
   printf("%-6d | %-25.25s | %-20.20s | %-12.12s | %10.2f | %12d\n",
    books[index].Book_id,
    books[index].Title,
    books[index].Author,
    books[index].genre,
    books[index].Price,
    sale[index]);
    }}
}
//-----------------------------xxxxxxxxxxxxxx-------------------------------------