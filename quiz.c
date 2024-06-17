#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of books
#define MAX_Question 100
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "password"

// Define the structure for a Question
typedef struct {
    int Question ;
    char question[100];
    char answer[100];
    int Option;
    
 
} Question;

// Declare the Question array and count
question question[MAX_Question];
int bookCount = 0;

// Function prototypes
void displayHomePage();
void displayAdminMenu();