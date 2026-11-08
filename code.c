#include <stdio.h>
int main(void){

typedef struct {
    int id;
    char title[100];
    char author[100];
    float price;
    int quantity;
} Book;

Book books[50];
int bookCount = 0;

void loadBooks() {
    FILE *fp = fopen("books.dat", "rb");
    if (fp == NULL) return;                       // no file yet, start empty
    bookCount = fread(books, sizeof(Book), 50, fp);
    fclose(fp);
}

void addBook() {
    if (bookCount == 50) {
        printf("Catalog is full.\n");
        return;
    }

    Book b;
    printf("Enter ID: ");
    scanf("%d", &b.id);
    printf("Enter title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter author: ");
    scanf(" %[^\n]", b.author);
    printf("Enter price: ");
    scanf("%f", &b.price);
    printf("Enter quantity: ");
    scanf("%d", &b.quantity);

    books[bookCount] = b;     // save in array
    bookCount++;

    FILE *fp = fopen("books.dat", "ab");   // save in file
    fwrite(&b, sizeof(Book), 1, fp);
    fclose(fp);

    printf("Book added.\n");
}}

