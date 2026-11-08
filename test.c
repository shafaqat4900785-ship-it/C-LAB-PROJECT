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