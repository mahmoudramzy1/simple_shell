#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

extern char** environ;

int main() {
    char command[MAX_COMMAND_LENGTH];
    char* arguments[MAX_ARGUMENTS];

    while (1) {
        // Display the prompt
        printf("$ ");
        fflush(stdout);

        // Read the command from the user
        if (fgets(command, sizeof(command), stdin) == NULL) {
            // End of file condition (Ctrl + D)
            break;
        }

        // Remove the newline character at the end
        command[strcspn(command, "\n")] = '\0';

        // Tokenize the command into arguments
        int i = 0;
        arguments[i] = strtok(command, " ");
        while (arguments[i] != NULL && i < MAX_ARGUMENTS - 1) {
            i++;
            arguments[i] = strtok(NULL, " ");
        }
        arguments[i] = NULL;

        if (strcmp(arguments[0], "exit") == 0) {
            // Exit the shell
            exit(0);
        } else if (strcmp(arguments[0], "env") == 0) {
            // Print the environment variables
            char** env = environ;
            while (*env != NULL) {
                printf("%s\n", *env);
                env++;
            }
        } else {
            // Check if the command exists in the PATH
            char* path = getenv("PATH");
            char* token = strtok(path, ":");
            int commandExists = 0;

            while (token != NULL) {
                char commandPath[MAX_COMMAND_LENGTH];
                snprintf(commandPath, sizeof(commandPath), "%s/%s", token, arguments[0]);

                if (access(commandPath, F_OK) == 0) {
                    // Command exists in the PATH
                    commandExists = 1;
                    break;
                }

                token = strtok(NULL, ":");
            }

            if (commandExists) {
                // Fork a new process
                pid_t pid = fork();

                if (pid < 0) {
                    // Forking failed
                    perror("Fork failed");
                    exit(1);
                } else if (pid == 0) {
                    // Child process
                    // Execute the command
                    if (execvp(arguments[0], arguments) == -1) {
                        perror("Error executing command");
                        exit(1);
                    }
                } else {
                    // Parent process
                    // Wait for the child process to finish
                    wait(NULL);
                }
            } else {
                // Command not found in the PATH
                printf("Command not found: %s\n", arguments[0]);
            }
        }
    }

    return 0;
}
