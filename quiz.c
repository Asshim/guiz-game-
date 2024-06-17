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

// Declare the Question
 array and count
question question[MAX_Question];
int QuestionCount = 0;

// Function prototypes
void displayHomePage();
void displayAdminMenu();
void displayUserMenu();
void addQuestion();
void viewQuestion();
void updateQuestion();
void deleteBook();
int findQuestionByQuestion(int Question);
int adminLogin();
void userViewQuestion();
void adminProcess();

int main() {
    while (1) {
        displayHomePage();
    }
    return 0;
}

void displayHomePage() {
    int roleChoice;
    printf("                Quiz game  System\n");
	printf("||==============================================================||\n");
	printf("||            		Home Page                               	||\n");
	printf("||              Your role:                        		    	||\n");
    printf("||         1.Admin                              			 	||\n");
    printf("||         2.User                                 		 		||\n");
	printf("||         3.Exit                                         		||\n");
	printf("||         Enter your choice:                           		||\n");
	printf("||==============================================================||\n\n");
    scanf("%d", &roleChoice);
    if (roleChoice == 1) {
        if (adminLogin() == 1) {
            adminProcess();
        } else {
            printf("Invalid username or password.\n");
        }
    } else if (roleChoice == 2) {    int id;
    printf("Enter Question ID to delete: ");
    scanf("%d", &id);

    int index = findQuestionById(id);
    if (index != -1) {
        for (int i = index; i < QuestionCount - 1; i++) {
            Question[i] = Question[i + 1];
        }
        bookCount--;
        printf("Question deleted successfully.\n");
    } else {
        printf("Question not found.\n");
    }
}

int findQuestionById(int id) {
    for (int i = 0; i < QuestionCount; i++) {
        if (Question[i].id == id) {
            return i;
        }
    }
    return -1;
}

void userViewQuestion() {
    int choice;
    do {
        displayUserMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                viewQuestion();
                break;
            case 2:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);
}