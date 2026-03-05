#include "Magnus_libFS.h"

int main() {

    // introduction
    char introduction[250] = "Hello my name is Magnus Hayden! \n\nThis is my implementation for Lab5! This program \nsimulates file operations by using separate methods for \neach file operation\n\nI hope you enjoy!";
    printf("Introduction:\n%s\n", introduction);


    // loop through menu until user exits
    int choice = 0;
    FILE *fp = NULL;
    while (choice != 7) {

        // reset choice
        choice = 0;

        // print out the menu to the user
        printf("\n--- Menu ---\n");
        printf("1. Create a File\n");
        printf("2. Open a File\n");
        printf("3. Write to a File\n");
        printf("4. Read a File\n");
        printf("5. Close a File\n");
        printf("6. Delete a File\n");
        printf("7. Exit\n\n");
        // get the choice from the user
        printf("Enter your Choice: ");
        scanf("%d", &choice);
        while(getchar() != '\n');

        if (choice < 1 || choice > 7) {
            printf("Invalid Menu Choice (1-7).\n");
            // clear input buffer
            char ch;
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }

        switch (choice) {
            // Create a File
            case 1:
                fileCreate();
                break;

            // Open a File
            case 2:
                fp = fileOpen();
                break;

            // Write to a file
            case 3:
                fileWrite(introduction);
                break;
                
            // Read a File
            case 4:
                fileRead();
                break;
            
            // CLose file
            case 5:
                fileClose(&fp);
                break;
            
            // delete a file
            case 6:
                fileDelete();
                break;

            // exit loop
            case 7:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Menu Choice (1-7).\n");
        }
    } 
}