#include <stdio.h>
#include <string.h>
#define MAX_BOOKS 100
// Structure to hold book details
typedef struct {
    char title[100];
    char author[50];
    int available;
} Book;
Book library[MAX_BOOKS];
int bookCount = 0;
// Function to add a book
void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    printf("Enter book title: ");
    scanf(" %[^\n]", library[bookCount].title);
    printf("Enter author name: ");
    scanf(" %[^\n]", library[bookCount].author);
    library[bookCount].available = 1;
    bookCount++;
    printf("Book added successfully!\n");
}
// Function to display all books
void displayBooks() {
    if (bookCount == 0) {
        printf("No books available in the library.\n");
        return;
    }
    printf("\nLibrary Books:\n");
    printf("Title\t\tAuthor\t\tAvailability\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < bookCount; i++) {
        printf("%s\t\t%s\t\t%s\n", library[i].title, library[i].author, library[i].available ? "Available" : "Not Available");
    }
}
// Function to search for a book
void searchBook() {
    char searchTitle[100];
    printf("Enter book title to search: ");
    scanf(" %[^\n]", searchTitle);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, searchTitle) == 0) {
            printf("Book Found: %s by %s - %s\n", library[i].title, library[i].author, library[i].available ? "Available" : "Not Available");
            return;
        }
    }
    printf("Book not found in the library.\n");
}
int main() {
    int choice;
    while (1) {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                printf("Exiting the program.\n");
                return 0;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
