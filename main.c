#define _GNU_SOURCE
#include "monty.h"

int stack_arr[15];
int top = -1;

void process(unsigned int count, char *line);
void push(int data, unsigned int count);
int main(int argc, char *argv[])
{
        char *line = NULL;
        FILE *file;
    size_t len = 0;
    ssize_t read = 1;
    unsigned int count = 0;

    top = -1;

        if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit(EXIT_FAILURE);
        }

        file = fopen(argv[1], "r");

        if (file == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }

        while (read > 0)
        {
                line = NULL;
                if (read > 0)
                {
                        read = getline(&line, &len, file);
                }
                count++;
                process(count, line);
                free(line);
        }
        fclose(file);
        return (0);
}
void process(unsigned int count, char *line)
{
        char *command;
        char *arg;
        int k;
        int z;
        
        count = count + 1;

        command = strtok(line, " \n\t");
        if (command != NULL && strcmp(command, "push") == 0)
        {
                arg = strtok(NULL, " \n\t");
                k = atoi(arg);
                push (k, count);
        }
        if (command != NULL && strcmp(command, "pall") == 0)
        {
                z = top;
                while (z > -1)
                {
                        printf("%d", stack_arr[z]);
                        printf("\n");
                        z = z -1;
                }
        }

}

void push(int data, unsigned int count)
{
        top++;
        stack_arr[top] = data;
        count++;
}
