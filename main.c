#define _GNU_SOURCE
#include "monty.h"

int stack_arr[15];
int top = -1;

void process(unsigned int count, char *line);
void push(int data);
void pint(unsigned int count);
void pop(unsigned int count);
void swap(unsigned int count);
void add(unsigned int count);
void nop();
void sub(unsigned int count);
void divi(unsigned int count);
void mul(unsigned int count);
void mod(unsigned int count);
void pchar(unsigned int count);
void pstr();

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
        
    

        command = strtok(line, " \n\t");

        if (command != NULL && strcmp(command, "push") == 0)
        {
                arg = strtok(NULL, " \n\t");
		if (arg == NULL || arg[0] < 48 || arg[0] > 57)
		{
			printf("L%u: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}	
                k = atoi(arg);
                push (k);
        }
	else if (command != NULL && strcmp(command, "pall") == 0 && top !=-1)
        {
                z = top;
                while (z > -1)
                {
                        printf("%d", stack_arr[z]);
                        printf("\n");
                        z = z -1;
                }
        }
	else if (command != NULL && strcmp(command, "pint") == 0)
	{
		pint(count);
	}
	else if (command != NULL && strcmp(command, "pop") == 0)
	{
		pop(count);
	}
	else if (command != NULL && strcmp(command, "swap") == 0)
	{
		swap(count);
	}
	else if (command != NULL && strcmp(command, "add") == 0)
	{
		add(count);
	}
	else if (command != NULL && strcmp(command, "nop") == 0)
	{
		nop();
	}
	else if (command != NULL && strcmp(command, "sub") == 0)
	{
		sub(count);
	}
	else if (command != NULL && strcmp(command, "div") == 0)
	{
		divi(count);
	}
	else if (command != NULL && strcmp(command, "mul") == 0)
        {
                mul(count);
        }
	else if (command != NULL && strcmp(command, "mod") == 0)
        {
                mod(count);
        }
	else if (command != NULL && strcmp(command, "pchar") == 0)
	{
		pchar(count);
	}
	else if (command != NULL && strcmp(command, "pstr") == 0)
        {
                pstr();
        }
	else
	{
		if (command != NULL)
		{
			printf("L%u: unknown instruction %s", count, command);
			exit (EXIT_FAILURE);
		}
	}
	
	

}

void push(int data)
{
        top++;
        stack_arr[top] = data;
}

void pint(unsigned int count)
{
	if (top == -1)
	{
		printf("L%u: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	printf("%d", stack_arr[top]);
	printf("\n");
}

void pop(unsigned int count)
{
	int m, sec;

	m = top;
	if (top == -1)
	{
		printf("L%u: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	sec = stack_arr[m -1];
	top = top - 1;
	stack_arr[top] = sec;
}

void swap(unsigned int count)
{
	int first, second, r;

	r = top;
	if (top < 1)
	{
		printf("L%u: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	first = stack_arr[r];
	second = stack_arr[r - 1];

	stack_arr[top] = second;
	stack_arr[top-1] = first;
}

void add(unsigned int count)
{
	int first, second, r;

	r = top;
	if (top < 1)
	{
		printf("L%u: can't add, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	first = stack_arr[r];
	second = stack_arr[r - 1];

	top = top - 1;

	stack_arr[top] = first + second;
}

void nop()
{
}

void sub(unsigned int count)
{
	int first, second, r;

	r = top;
	if (top < 1)
	{
		printf("L%u: can't sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	first = stack_arr[r];
	second = stack_arr[r - 1];

	top = top - 1;

	stack_arr[top] = second - first;
}

void divi(unsigned int count)
{
	int first, second, r;

        r = top;
        if (top < 1)
        {
                printf("L%u: can't sub, stack too short\n", count);
                exit(EXIT_FAILURE);
        }

        first = stack_arr[r];
        second = stack_arr[r - 1];

	if (stack_arr[top] == 0)
	{
		printf("L%u: division by zero", count);
		exit(EXIT_FAILURE);
	}

        top = top - 1;


        stack_arr[top] = second/first;
}

void mul(unsigned int count)
{
	int first, second, r;

        r = top;
        if (top < 1)
        {
                printf("L%u: can't sub, stack too short\n", count);
                exit(EXIT_FAILURE);
        }

        first = stack_arr[r];
        second = stack_arr[r - 1];

       
        top = top - 1;


        stack_arr[top] = second * first;
}

void mod(unsigned int count)
{
	int first, second, r;

        r = top;
        if (top < 1)
        {
                printf("L%u: can't sub, stack too short\n", count);
                exit(EXIT_FAILURE);
        }

	if (stack_arr[top] == 0)
	{
		printf("L%u: division by zero\n", count);
		exit(EXIT_FAILURE);
	}

        first = stack_arr[r];
        second = stack_arr[r - 1];

        top = top - 1;

        stack_arr[top] = second % first;
}

void pchar(unsigned int count)
{
	int k;
	char c;

	k = stack_arr[top];

	if (top == -1)
	{
		printf("L%u: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}
	if ((97 <= k && k <= 122) || (65 <= k && k <= 90))
	{
		c = (char)k;
		printf("%c\n", c);
		return;
	}
	
	printf("L%u: can't pchar, value out of range\n", count);
	exit(EXIT_FAILURE);
}

void pstr()
{
	int v;
	char c;
	int k;

	v = top;

	if (top == -1)
	{
		printf("\n");
		return;
	}
	while(v > -1)
	{
		k = stack_arr[v];
		if (k == 0)
		{
			break;
		}
		if ((97 <= k && k <= 122) || (65 <= k && k <= 90))
		{
			c = (char)k;
			printf("%c", c);
		}
		if(!( (97 <= k && k <= 122) || (65 <= k && k <= 90) ))
		{
			break;
		}
		v = v - 1;
	}
	printf("\n");
}

