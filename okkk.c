     // Function for admin login
     #include<stdio.h>
     #include<string.h>
int main()
{
    char adminUsername[20];
    char adminPassword[20];
    char correctUsername[20] = "admin";
    char correctPassword[20] = "password";
    printf("Enter admin username: ");
    scanf("%s", adminUsername);
    printf("Enter admin password: ");
    scanf("%s", adminPassword);
    if (strcmp(adminUsername, correctUsername) == 0 && strcmp(adminPassword, correctPassword) == 0) {
        return 1; // Login successful
    } else {
        return 0; // Login failed
    }}
