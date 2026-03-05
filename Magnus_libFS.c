#include "Magnus_libFS.h"

void fileCreate() {
    // get file name
    char fileName[25];
    printf("Enter File Name to Create: ");
    if (fgets(fileName, sizeof(fileName), stdin) != NULL)
        fileName[strcspn(fileName, "\n")] = '\0';

    // access file
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error creating file %s\n", fileName);
    } else {
        printf("File %s successfully created.\n", fileName);
        fileClose(&fp);
    }
}

FILE* fileOpen() {
    // get file name
    char fileName[25];
    printf("Enter File Name to Open: ");
    if (fgets(fileName, sizeof(fileName), stdin) != NULL)
        fileName[strcspn(fileName, "\n")] = '\0';

    // access file
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
    } else {
        printf("File %s successfully opened.\n", fileName);
    }
    return fp;
}

void fileWrite(char *intro) {
    // get file name
    char fileName[25];
    printf("Enter File Name to Write to: ");
    if (fgets(fileName, sizeof(fileName), stdin) != NULL)
        fileName[strcspn(fileName, "\n")] = '\0';

    // open file to write to
    FILE *fp = fopen(fileName, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    fprintf(fp, "%s", intro);

    printf("Succesfully wrote to %s\n", fileName);
    fileClose(&fp);
}

void fileRead() {
    // get file name
    char fileName[25];
    printf("Enter File Name to Read to: ");
    if (fgets(fileName, sizeof(fileName), stdin) != NULL)
        fileName[strcspn(fileName, "\n")] = '\0';

    // open file to read from
    FILE *fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", fileName);
        return;
    }

    // read from file
    char buffer[100];
    while(fgets(buffer, 100, fp)) {
        printf("%s", buffer);
    }
    printf("\n");
    fileClose(&fp);
}

void fileClose(FILE **fp) {
    if (*fp != NULL) {
        fclose(*fp);
        *fp = NULL;
        printf("Successfully closed file\n");
    } else {
        printf("No file to close\n");
    }
}

void fileDelete() {
    // get file name
    char fileName[25];
    printf("Enter File Name to Delete: ");
    if (fgets(fileName, sizeof(fileName), stdin) != NULL)
        fileName[strcspn(fileName, "\n")] = '\0';

    // create child process
    pid_t pid = fork();

    if (pid == 0) {
        // create file
        char *const args[] = {"rm", fileName, NULL};
        if (execvp(args[0], args) == -1) {
            printf("Failed to delete file.\n");
            exit(1);
        }
    } else if (pid > 0) {
        int status;
        waitpid(pid, &status, 0);
        if (WEXITSTATUS(status) != 1)
            printf("Successfully deleted file %s\n", fileName);
    }
}