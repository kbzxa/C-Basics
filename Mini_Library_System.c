#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//We define the maximum number of books, the length of the author's name, and the length of the title.
#define MAX_BOOKS 100
#define MAX_AUTHOR_LENGTH 50
#define MAX_TITLE_LENGTH 50

// We define a structure to represent a book.
 typedef struct {
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    int year;
    int isAvailable; // 1 if available, 0 if checked out
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

// We mention the functions we are going to use.
void addBook();
void deleteBook();
void searchBook();
void listBooks();

// Main function
int main(){
    int choice;
    printf("Welcome to the Mini Library System\n");
    do {
        printf("\nMenu:\n");
        printf("1. Add Book\n");
        printf("2. Delete Book\n");
        printf("3. Search Book\n");
        printf("4. List Books\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                deleteBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                listBooks();
                break;
            case 5:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid number. Please try again.\n");
        }
    } while (choice != 5);
    return 0;
}

// We define the functions we mentioned before.
// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full. Cannot add more books.\n");
        return;
    }
    Book newBook;
    printf("Enter book title: ");
    fgets(newBook.title, MAX_TITLE_LENGTH, stdin);
    newBook.title[strcspn(newBook.title, "\n")] = 0;

    printf("Enter author name: ");
    fgets(newBook.author, MAX_AUTHOR_LENGTH, stdin);
    newBook.author[strcspn(newBook.author, "\n")] = 0;

    printf("Enter publication year: ");
    scanf("%d", &newBook.year);
    getchar();

    newBook.isAvailable = 1;
    library[bookCount++] = newBook;
    printf("Book added successfully!\n");
}

// Function to delete a book
void deleteBook() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to delete: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book deleted successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to search for a book
void searchBook() {
    char title[MAX_TITLE_LENGTH];
    printf("Enter the title of the book to search: ");
    fgets(title, MAX_TITLE_LENGTH, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Book found:\n");
            printf("Title: %s\n", library[i].title);
            printf("Author: %s\n", library[i].author);
            printf("Year: %d\n", library[i].year);
            printf("Status: %s\n", library[i].isAvailable ? "Available" : "Checked Out");
            return;
        }
    }
    printf("Book not found.\n");
}

// Function to list all books
void listBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Listing all books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%d. Title: %s, Author: %s, Year: %d, Status: %s\n", 
               i + 1, library[i].title, library[i].author, library[i].year, 
               library[i].isAvailable ? "Available" : "Checked Out");
    }
}

