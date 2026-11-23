void update(void){
    printf("Enter the book ID you want to update:\n");
    if(scanf("%d",&book_id)!=1){
        printf("Invalid book ID entered.\n");
        while(getchar()!='\n'); //clears the input buffer
        return;
    }
    int found=0;
    for(int i=0;i<bookcounter;i++){
        if(books[i].Book_id==book_id){
            found=1;
            printf("Book with ID %d exist in the catalog.\n",book_id);
            printf("What do you want to update.\n");
            printf("*****UPDATE MENU*****\n");
            printf("     1.Price\n");
            printf("     2.Quantity\n");
            int choice;
            printf("Enter your choice:\n");
            if(scanf("%d",&choice)!=1){
                printf("Invalid choice entered.Enter 1 or 2.\n");
                while(getchar()!='\n'); //clears the input buffer
                return;
            }
            if(choice==1){
                do{ 
                    printf("Enter the new price:\n");
                    if(scanf("%f",&books[i].Price)!=1){
                        Printf("Invalid price entered . Enter a numeric value(positive and greater than 0).\n");
                        while(getchar()!='\n'); //clears the input buffer
                        continue;
                    }
                
                if(books[i].Price<=0)
                printf("Invalid price entered.Enter a positive and greater than 0 price.\n");
            }while(books[i].Price<=0);
               Savefile();
               printf("Price updated successfully!\n");
            }
            else if(choice==2){
                do{
                    
                        printf("Enter the new quantity:\n");
                        if(scanf("%d",&books[i].Quantity)!=1){
                            printf("Invalid quantity entered. Enter a numeric value(positive and greater than 0\n");
                            while(getchar()!='\n'); //clears the input buffer
                            continue;
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
        printf("Book with ID %d doesnot exist in the catalog.\n",book_id);
     
}
void Delete_book(void){
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
           for(int j=i;j<bookcounter-1;j++){
            books[j]=books[j+1];
            sale[j]=sale[j+1];
           }
           bookcounter--;
           saveSales();
           Savefile();
           printf("Book with name %s deleted successfully\n",title);
        break;}
    }
    if(found==0){
        printf("Book with ID %d does not exist in the catalog\n",Book_id);
    }
    printf("Do you want to delete another book?(y/n):\n");
    scanf(" %c",&choice);}
    while(choice == 'y' || choice == 'Y');}
    void Delete_book(void){
    char choice;
    char title[100];
    do{
    printf("Enter the Book name to be deleted:\n");
        if(scanf(" %99[^\n]",title)!=1){
            printf("Invalid book input\n");
            while(getchar()!='\n');
        return;}
     int found=0;
    for(int i=0;i<bookcounter;i++){
        if(strcmpi(title,books[i].Title)==0)
        { found=1;
          printf("Book with name %s exist \n Deleting it...",title);
           for(int j=i;j<bookcounter-1;j++){
            books[j]=books[j+1];
            sale[j]=sale[j+1];
           }
           bookcounter--;
           saveSales();
           Savefile();
           printf("Book with name %s deleted successfully\n",title);
        break;}
    }
    if(found==0){
        printf("Book with name %s does not exist in the catalog\n",title);
    }
    printf("Do you want to delete another book?(y/n):\n");
    scanf(" %c",&choice);}
    
    while(choice == 'y' || choice == 'Y');}


    void sell(void){ 
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
            printf("Book with Id %d exist in the catalog\n",Book_Id);
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
void showcatalog(void){
    int choice;
printf("\nWould you like to browse the available books before making a selection?\n");
printf("1. View Book Catalog\n");
printf("2. Continue to Book Selection\n");
printf("Enter your choice: ");
if(scanf("%d",&choice)!=1){
    printf("Invalid choice.\nExiting from here.\n");
    while(getchar()!='\0');
    return;
}
if(choice==1)
catalog();
else if(choice ==2)
return;
}