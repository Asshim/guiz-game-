#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Define maximum number of question
#define MAX_QUESTIONS 100
#define MAX_LENGTH 256
//Define the structure for a question
typedef struct {
    char question[MAX_LENGTH];
    char options[4][MAX_LENGTH];
    char correctOption;
} Question;

typedef struct {
    Question questions[MAX_QUESTIONS];
    int count;
} Quiz;
//function 
void addQuestion(Quiz *quiz);
void editQuestion(Quiz *quiz);
void deleteQuestion(Quiz *quiz);
void displayAdminMenu(Quiz *quiz);
void displayPlayerMenu(Quiz *quiz);
void takeQuiz(Quiz *quiz);
void displayMainMenu(Quiz *quiz);

int main() {
    Quiz quiz;
    quiz.count = 0;
//main menu 
    displayMainMenu(&quiz);

    return 0;
}

void addQuestion(Quiz *quiz) {
    if (quiz->count >= MAX_QUESTIONS) {
        printf("Question limit reached!\n");
        return;
    }

    Question q;
    printf("Enter the question: ");
    getchar();  // to consume the newline character left by the previous input
    fgets(q.question, MAX_LENGTH, stdin);
    q.question[strcspn(q.question, "\n")] = 0;  // Remove the newline character

    for (i= 0; i<4; i++) {
        printf("Enter option %c: ", 'A' + i);
        fgets(q.options[i], MAX_LENGTH, stdin);
        q.options[i][strcspn(q.options[i], "\n")] = 0;  // Remove the newline character
    }

    printf("Enter the correct option (A, B, C, or D): ");
    scanf(" %c", &q.correctOption);

    quiz->questions[quiz->count++] = q;
    printf("Question added successfully!\n");
}

void editQuestion(Quiz *quiz) {
    int index;
    printf("Enter the question number to edit: ");
    scanf("%d", &index);

    if (index < 1 || index > quiz->count) {
        printf("Invalid question number!\n");
        return;
    }

    Question *q = &quiz->questions[index - 1];
    printf("Editing question %d:\n", index);
    printf("Enter the new question: ");
    getchar();  // to consume the newline character left by the previous input
    fgets(q->question, MAX_LENGTH, stdin);
    q->question[strcspn(q->question, "\n")] = 0;  // Remove the newline character

    for (i = 0; i < 4; i++) {
        printf("Enter new option %c: ", 'A' + i);
        fgets(q->options[i], MAX_LENGTH, stdin);
        q->options[i][strcspn(q->options[i], "\n")] = 0;  // Remove the newline character
    }

    printf("Enter the new correct option (A, B, C, or D): ");
    scanf(" %c", &q->correctOption);

    printf("Question edited successfully!\n");
}

void deleteQuestion(Quiz *quiz) {
    int index;
    printf("Enter the question number to delete: ");
    scanf("%d", &index);

    if (index < 1 || index > quiz->count) {
        printf("Invalid question number!\n");
        return;
    }

    for (i = index - 1; i < quiz->count - 1; i++) {
        quiz->questions[i] = quiz->questions[i + 1];
    }

    quiz->count--;
    printf("Question deleted successfully!\n");
}

void displayAdminMenu(Quiz *quiz) {
    int choice;
    do {
        printf("\nAdmin Menu:\n");
        printf("1. Add Question\n");
        printf("2. Edit Question\n");
        printf("3. Delete Question\n");
        printf("4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addQuestion(quiz);
                break;
            case 2:
                editQuestion(quiz);
                break;
            case 3:
                deleteQuestion(quiz);
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
}

void takeQuiz(Quiz *quiz) {
    int score = 0;
    char answer;

    for ( i = 0; i < quiz->count; i++) {
        printf("\nQuestion %d: %s\n", i + 1, quiz->questions[i].question);
        for (int j = 0; j < 4; j++) {
            printf("%c. %s\n", 'A' + j, quiz->questions[i].options[j]);
        }
        printf("Your answer: ");
        scanf(" %c", &answer);

        if (answer == quiz->questions[i].correctOption) {
            score++;
        }
    }

    printf("\nQuiz completed! Your score: %d/%d\n", score, quiz->count);
}

void displayPlayerMenu(Quiz *quiz) {
    int choice;
    do {
        printf("\nPlayer Menu:\n");
        printf("1. Take Quiz\n");
        printf("2. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                takeQuiz(quiz);
                break;
            case 2:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 2);
}

void displayMainMenu(Quiz *quiz) {
    int choice;
    do {
        printf("\nMain Menu:\n");
        printf("1. Admin Section\n");
        printf("2. Player Section\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayAdminMenu(quiz);
                break;
            case 2:
                displayPlayerMenu(quiz);
                break;
            case 3:
                printf("Exiting the program...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 3);
}
