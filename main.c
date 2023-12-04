#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 50
#define MAX_PASSWORD_LENGTH 50

int authenticateUser(const char *username, const char *password) {
    FILE *file = fopen("users.txt", "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char buffer[MAX_USERNAME_LENGTH + MAX_PASSWORD_LENGTH + 2];
    int authenticated = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        char *storedUsername = strtok(buffer, " ");
        char *storedPassword = strtok(NULL, " \n");

        if (storedUsername != NULL && storedPassword != NULL &&
            strcmp(username, storedUsername) == 0 &&
            strcmp(password, storedPassword) == 0) {
            authenticated = 1;
            break;
        }
    }

    fclose(file);
    return authenticated;
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    if (authenticateUser(username, password)) {
        printf("Authentication successful. Welcome, %s!\n", username);
    } else {
        printf("Authentication failed. Invalid username or password.\n");
    }

    return 0;
}
