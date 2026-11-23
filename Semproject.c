#include<stdio.h>
#include<string.h>
#include "Loader.h"

//--------------------------->FUNCTION DECLARATION<-----------------------------
void Add_book(void);
void Delete_book(void);
void Catalog(void);
void Search(void);
void update(void);
void sell(void);
void cumulativeSales(void);
void resetSales(void);
void bestSell(void);
void LowStockReport(void);
void printHeader(void);
void printRow(int);
void showcatalog(void);

//----------------------------------xxxxx----------------------------------------
//Main function that controls the book shop mgmnt system
int main(){
    int option;
//------------------------>FOR LOADING FILES<------------------------------------
// Load the saved book records and sales data when the program starts.
Initializefile();  
Loadfile();
loadSales();
//------------------------------------>MENU<--------------------------------
   // Display the menu repeatedly until the user chooses to exit.
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
        printf("| 10.Low stock report                       |\n");
        printf("| 11.Exit                                   |\n");
        printf("+===========================================+\n");
        printf("Enter choice\n");
        // Check whether the user entered a valid numeric menu choice.
        if(scanf("%d",&option)!=1){
            printf("Invalid input! Please enter a number between 1 and 11.\n");
            while(getchar()!='\n'); //clear the input buffer 
    //if user enter AB and press enter toh getchar will absorb A B and the chracter \n and input buffer hence becomes empty
            option =0;
            continue;
        }

//--------------------------------->SWITCH<--------------------------------------
// Perform the operation selected by the user.
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
                printf("Low stock report selected.\n");
                LowStockReport();
                break;

            case 11:
                printf("Exiting.\n");
                break;
            
            default:
                printf("Invalid option! Choose between 1 and 11.\n");
        }
    }while(option!=11);

    return 0;
}

//------------------------------>FUNCTION DEFINATIONS<----------------------------

//--------------------------------->RESET SALES<------------------------------------
// Resets the total sales after getting confirmation from the user.
void resetSales(void){
    char choice;
    do{
        printf("Are you sure you want to reset the sales? This action cannot be undone.(y/n)\n");
        scanf(" %c",&choice);
        // Reset sales only when the user confirms the action.
    if(choice=='y'|| choice=='Y'){
totalSales=0;
saveSales();
printf("Total sales reset to 0.\n");}
else if(choice=='n' || choice=='N'){
    printf("Reset sales cancelled.\n");}
else{
    printf("Invalid input! Enter (y/n) only.\n");
    while(getchar()!='\n');
}}
while(choice!='y'&& choice!='Y' && choice !='n' && choice !='N');
}
//--------------------------------->ADD BOOK<------------------------------------
// Adds a new book to the inventory after checking its details.
void Add_book(void){
    showcatalog();
    char choice;
    do{
 // Check whether there is space for another book in the inventory.
    if(bookcounter>=50){
        printf("The Inventory is full!\n");
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
    // Check if the entered book ID is already used.
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
 // Keep asking until a valid positive price is entered.
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
// Make sure the entered quantity is not negative.
    do{
        while(1){
    printf("Enter Book Quantity: \n");
    if(scanf(" %d", &books[bookcounter].Quantity)!=1){
        printf("Invalid input.Enter a numeric value (Zero or a positive quantity.)\n");
        while(getchar()!='\n');
        continue;
    }
    break;
    }
    if(books[bookcounter].Quantity<0)
    printf("Invalid quantity entered. Enter a zero or a positive quantity.\n");
    }while(books[bookcounter].Quantity<0);
 // Set the sold quantity to zero for the newly added book.
    sale[bookcounter]=0;
// Update the book count and save the changes to the files.
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
// Deletes a book from the inventory using its book ID.
    showcatalog();
    char choice;
    do{
    printf("Enter the Book ID to be deleted:\n");
        if(scanf("%d",&Book_id)!=1){
            printf("Invalid book ID entered.Please refrain from entering non-numeric values next time.\n");
            while(getchar()!='\n');
        return;}
     int found=0;
    for(int i=0;i<bookcounter;i++){
        if(books[i].Book_id==Book_id)
        { found=1;
          printf("Book with ID %d exist in the catalog\nDeleting it...",Book_id);
     // Shift the remaining records left to fill the deleted book's position.
          for(int j=i;j<bookcounter-1;j++){
            books[j]=books[j+1];
            sale[j]=sale[j+1];
           }
     // Decrease the number of books after removing the record.
           bookcounter--;
           saveSales();
           Savefile();
           printf("Book with name Id %d deleted successfully\n",Book_id);
        break;}
    }
    if(found==0){
        printf("Book with ID %d does not exist in the catalog\n",Book_id);
    }
    printf("Do you want to delete another book?(y/n):\n");
    scanf(" %c",&choice);}
    while(choice == 'y' || choice == 'Y');}
//----------------------------------->PRINTHEADER<--------------------------------------
// Displays the column headings used in the book catalog.
void printHeader(void){
    printf("%-6s | %-25s | %-20s | %-12s | %-10s | %-12s\n",
           "ID", "TITLE", "AUTHOR", "GENRE", "PRICE", "QUANTITY");
    printf("--------------------------------------------------------------------------------------------------\n");
}
//----------------------------------->PRINTROW<-----------------------------------------
// Displays the details of a book at the specified array index.
void printRow(int i){
    printf("%-6d | %-25.25s | %-20.20s | %-12.12s | %10.2f | %12d\n",
           books[i].Book_id,
           books[i].Title,
           books[i].Author,
           books[i].genre,
           books[i].Price,
           books[i].Quantity);
}
//----------------------------------->SEARCH<-----------------------------------------
// Searches for books using their ID, title, author or genre.
void Search(void){
    int choice;
    char title[100],genre[100],author[100];
    printf("How would you like to search?\n");
    printf("1.By ID\n2.By Title\n3.By Author\n4.By Genre\n");
    printf("Enter choice\n");
    if(scanf("%d",&choice)!=1){
        printf("Invalid input! Enter between 1-4 next time.\nExiting from here.\n");
        while(getchar()!='\n');
        return;
    }
    // Select the search method based on the user's choice.
    switch(choice){
        case 1:{
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
            found=1;
            printf("Book with ID %d exist in the catalog\n",Book_id);
            printHeader();
                    printRow(i);
         break;
        }
    }
    if(found==0){
        printf("Book with ID %d doesnot exist in the catalog\n",Book_id);
    }
    break;}
    case 2:{
    printf("Enter book title you want to search:\n");
    if(scanf(" %99[^\n]",title)!=1){
        printf("Invalid input!\n");
        while(getchar()!='\n');
        return;
    }
    int found=0;
    for(int i=0;i<bookcounter;i++){
    // Compare the strings without considering uppercase or lowercase letters.
    if(strcmpi(title,books[i].Title)==0){
        found=1;
        printf("Book with title %s exist in the catalog\n",title);
                    printHeader();
                    printRow(i);}
                }
    if(found==0){
printf("Book with title %s doesn't exist in the catalog\n",title);}
      break;}
case 3:{
        printf("Enter Author name\n");
        if(scanf(" %99[^\n]",author)!=1){
            printf("Invalid input!\n");
            while(getchar()!='\n');
            return;}
            int found=0;
        for(int i=0;i<bookcounter;i++){
// Compare the strings without considering uppercase or lowercase letters.
            if(strcmpi(author,books[i].Author)==0){
                if(found==0){
// Display the table header only when the first matching book is found.
                printf("Books written by %s are\n",author);
                printHeader();}
// Count each matching book found in the search.
                found++;
                printRow(i);}
            }
// Display a message if no books matched the search.
    if(found==0){
printf("Books written by %s doesn't exist in the catalog\n",author);}
break;}
     case 4:{
        printf("Enter book genre\n");
        if(scanf(" %99[^\n]",genre)!=1){
            printf("Invalid input!");
            while(getchar()!='\n');
            return;}
            int found=0;
    for(int i=0;i<bookcounter;i++){
 // Compare the strings without considering uppercase or lowercase letters.
        if(strcmpi(genre,books[i].genre)==0){
            if(found==0){
 // Display the table header only when the first matching book is found.
            printf("Books of %s genre are\n",genre);
            printHeader();}
// Count each matching book found in the search.
            found++;
            printRow(i);}
        }
 // Display a message if no books matched the search.
         if(found==0)
printf("Books of %s genre doesn't exist in catalog\n",genre);
break;}
 default:{
 printf("Invalid input! please only enter between 1-4 next time.\n");
break;}}
printf("\n");
}
//---------------------------------->CATALOG<-------------------------------------
// Displays all books currently stored in the inventory.
void Catalog(void){
    if(bookcounter==0){
        printf("The catalog is empty.\n");
        return;
    }
     printHeader();
// Go through all the books and display each book's details.
    for(int i = 0; i < bookcounter; i++){
        printRow(i);}}
//----------------------------------->UPDATE<--------------------------------------
// Allows the user to update the price or quantity of an existing book.
void update(void){
    showcatalog();
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
// Select whether to update the book's price or quantity.
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
            // Keep asking until a valid positive price is entered.
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
            // Keep asking until a valid non-negative quantity is entered.
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
                    if(books[i].Quantity<0)
                    printf("Invalid quantity entered. Enter a positive and greater than 0 quantity.\n");

                }while(books[i].Quantity<0);
                // Save the updated book details to the file.
                Savefile();
                printf("Quantity updated successfully!\n");
  
            }
            else
            {printf("Invalid choice.\n");}
            break;
        }
    }
        if(found==0)
        printf("Book with ID %d doesnot exist in the catalog.\n",Book_id);}
//---------------------------------->SELL BOOK<------------------------------------
// Handles book sales and updates the stock and sales records.
void sell(void){ 
    showcatalog();
    printf("Enter the Book ID the customer wants to buy:\n");
    if(scanf(" %d",&Book_id)!=1)
    {
        printf("Invalid book ID entered.Please refrain from entering non-numeric values next time.\n");
        while(getchar()!='\n');
        return;
    }
    int found=0;
    float total=0;
    for(int i =0;i<bookcounter;i++){
        if(books[i].Book_id == Book_id){
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
                // Reduce the available stock by the number of books sold.
                books[i].Quantity-=quantity;
                Savefile();
                // Calculate the total cost based on the book price and quantity sold.
                total=books[i].Price*quantity;
                printf("Total price of this purchase order: Rs.%.2f\nAdded to the total annually sales\n",total);
                // Update the total revenue and copies sold for this book.
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
//---------------------------------->CUMULATIVE SALES<------------------------------------
// Displays the total sales recorded by the system.
void cumulativeSales(void){
    printf("Cumulative sales as of now: Rs.%.2f\n",totalSales);
}
//-------------------------------->BEST SELLING BOOK<-----------------------------------
// Displays the top five books based on the number of copies sold.
void bestSell(void){
    if(bookcounter==0){
        printf("No books available in the inventory.\n");
        return;
    }
    // Store the original array positions so the book records remain unchanged.
    int order[50];
    // Initially arrange the indices in the same order as the books array.
    for(int i=0;i<bookcounter;i++){
        order[i]=i;}
    // Sort the indices in descending order according to the number of books sold.
    for(int i=0;i<bookcounter-1;i++){
        for(int j=0;j<bookcounter-1-i;j++){
    // Swap the indices when the next book has sold more copies.
            if(sale[order[j]]<sale[order[j+1]]){
                int temp=order[j];
                order[j]=order[j+1];
                order[j+1]=temp;
            }
        }
    }
    if(sale[order[0]]==0){
        printf("No books sold yet!\n");
        return;
    }
// Display up to five books, starting with the highest-selling one.
    printf("The best selling books are\n");
    printf("%-6s | %-25s | %-20s | %-12s | %-10s | %-12s\n",
       "ID", "TITLE", "AUTHOR", "GENRE", "PRICE", "SOLD");
printf("--------------------------------------------------------------------------------------------------\n");
    for(int i=0;i<bookcounter && i<5;i++){
        int index=order[i];
        if(sale[index]==0){
        continue;}
   printf("%-6d | %-25.25s | %-20.20s | %-12.12s | %10.2f | %12d\n",
    books[index].Book_id,
    books[index].Title,
    books[index].Author,
    books[index].genre,
    books[index].Price,
    sale[index]);
    }}
//-------------------------------LowStockReport-------------------------------------
void LowStockReport(void)
{
    int limit;       
    int found = 0;   

    printf("Enter stock limit: "); // Ask the user for the stock limit

    if (scanf("%d", &limit) != 1) { // Read one integer
        printf("Invalid input.\n"); // If input is not a number, show an error
        while (getchar() != '\n');  // Remove the invalid characters
        return;                    
    }

    if (limit < 0) { // A negative stock limit is not valid
        printf("Stock limit cannot be negative.\n"); 
        return;                                      
    }

    else{
    printf("Books with low stock are:\n");
    printHeader();
    for (int i = 0; i < bookcounter; i++) { 
        if (books[i].Quantity <= limit) {   // If its quantity is at or below the limit
            printRow(i);
            found++; // Count this low-stock book
        }
    }}

    if (found == 0) // If no book was at or below the limit
        printf("No books at or below that stock level.\n"); 
}
//-------------------------------Showcatalog-------------------------------------
// Asks the user whether to view the catalog before continuing an operation.
void showcatalog(void)
{
    int choice;
    // Keep asking until the user enters a valid option.
    while(1)
    {
    printf("\nWould you like to view the book catalog before proceeding?\n");
    printf("1. Yes, view catalog\n");
    printf("2. No, continue with the operation\n");  
        printf("Enter your choice: ");
        if(scanf("%d", &choice) != 1)
        {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n');
            continue;
        }
        if(choice == 1)
        {
            Catalog();
            printf("\n\n");
            return;
        }
        else if(choice == 2)
        {
            return;
        }
        else
        {
            printf("Invalid choice! Please select 1 or 2.\n");
        }
    }
}