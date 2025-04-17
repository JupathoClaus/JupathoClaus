#include <stdio.h>
#include <stdbool.h>

void displayAvailability(const int availableBooks[], int size);
int checkAvailability(const int availableBooks[], int size, int bookID);
void borrowBook(int availableBooks[], int *size, int bookID);
void returnBook(int availableBooks[], int *size, int bookID); 
void displayMenu();

// Global array to store available book IDs
#define MAX_BOOKS 100 // Define a maximum size for the array
int availableBooks[MAX_BOOKS];
int numAvailableBooks; // Keep track of the number of available books

// Function to display current availabilitoy
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

// Function to check if a book is available
int checkAvailability(const int availableBooks[], int size, int bookID) {
    for (int i = 0; i < size; i++) {
        if (availableBooks[i] == bookID) {
            return 1; // Available
        }
    }
    return 0; // Not available
}

// Function to mark a book as unavailable (remove from available list)
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
        // Shift elements to overwrite the borrowed book
        for (int i = foundIndex; i < *size - 1; i++) {
            availableBooks[i] = availableBooks[i + 1];
        }
        (*size)--; // Decrease the size of the available books array
    } else {
        printf("Book ID %d is not available.\n", bookID);
    }
}

// Function to mark a book as available (add back to the list)
void returnBook(int availableBooks[], int *size, int bookID) {
    if (*size < MAX_BOOKS) {
        availableBooks[*size] = bookID;
        (*size)++;
        printf("Book ID %d has been returned.\n", bookID);
    } else {
        printf("Library is at full capacity, cannot return book ID %d at the moment.\n", bookID);
    }
}

// Function to display the menu
void displayMenu() {
    printf("\n--- Library Management System ---\n");
    printf("1. View Current Availability\n");
    printf("2. Borrow a Book\n");
    printf("3. Return a Book\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    // Initialize the available books array with some initial book IDs
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
}//JUPATHO CLAUS     2024/DCS/DAY/0294
//WANDERA AISHA   2024/DCS/DAY/0854
//AKAREUT GRACE BERITA    2024/DCS/DAY/0796
//KATUMBA JULIUS    2024/DCS/DAY/0317
//AKORAGYE OSBERT   2024/DCS/DAY/0239
