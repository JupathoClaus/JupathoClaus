#include <stdio.h>
#include <stdbool.h>

void displayAvailability(const int availableBooks[], int size);
int checkAvailability(const int availableBooks[], int size, int bookID);
void borrowBook(int availableBooks[], int *size, int bookID);
void returnBook(int availableBooks[], int *size, int bookID); 
void displayMenu();


#define MAX_BOOKS 100 
int availableBooks[MAX_BOOKS];
int numAvailableBooks; 


void displayAvailability(const int availableBooks[], int size) {
    printf("\n--- Current Book Availability ---\n");
    if (size == 0) {
        printf("No books currently in the library.\n");
        return;
    }
    printf("Available Book IDs: ");
    for (int i = 0; i < size; i++) {
        printf("%d", availableBooks[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("\n-----------------------------------\n");
}


int checkAvailability(const int availableBooks[], int size, int bookID) {
    for (int i = 0; i < size; i++) {
        if (availableBooks[i] == bookID) {
            return 1; // Available
        }
    }
    return 0; // Not available
}


void borrowBook(int availableBooks[], int *size, int bookID) {
    int foundIndex = -1;
    for (int i = 0; i < *size; i++) {
        if (availableBooks[i] == bookID) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Book ID %d has been checked out.\n", bookID);
        
        for (int i = foundIndex; i < *size - 1; i++) {
            availableBooks[i] = availableBooks[i + 1];
        }
        (*size)--; 
    } else {
        printf("Book ID %d is not available.\n", bookID);
    }
}


void returnBook(int availableBooks[], int *size, int bookID) {
    if (*size < MAX_BOOKS) {
        availableBooks[*size] = bookID;
        (*size)++;
        printf("Book ID %d has been returned.\n", bookID);
    } else {
        printf("Library is at full capacity, cannot return book ID %d at the moment.\n", bookID);
    }
}


void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. View Current Availability\n");
    printf("2. Borrow a Book\n");
    printf("3. Return a Book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
   
    numAvailableBooks = 5;
    availableBooks[0] = 101;
    availableBooks[1] = 105;
    availableBooks[2] = 110;
    availableBooks[3] = 115;
    availableBooks[4] = 120;

    int choice, bookID;

    do {
        displayMenu();
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                displayAvailability(availableBooks, numAvailableBooks);
                break;
            case 2:
                printf("Enter the Book ID to borrow: ");
                if (scanf("%d", &bookID) == 1) {
                    borrowBook(availableBooks, &numAvailableBooks, bookID);
                } else {
                    printf("Invalid Book ID format.\n");
                    while (getchar() != '\n');
                }
                break;
            case 3:
                printf("Enter the Book ID to return: ");
                if (scanf("%d", &bookID) == 1) {
                    returnBook(availableBooks, &numAvailableBooks, bookID);
                } else {
                    printf("Invalid Book ID format.\n");
                    while (getchar() != '\n');
                }
                break;
            case 4:
                printf("Exiting the Library Management System. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}