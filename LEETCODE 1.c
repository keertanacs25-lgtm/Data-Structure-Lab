#include <stdio.h>
#include <string.h>

#define MAX 50

char stack[MAX];
int top = -1;

void push(char item)
{
    if (top < MAX - 1)
        stack[++top] = item;
}

char pop()
{
    if (top != -1)
        return stack[top--];

    return '\0';
}

void rev(char string[], char result[], char ch)
{
    int i, j = 0;

    top = -1;  // initialize stack

    for (i = 0; string[i] != '\0'; i++)
    {
        if (string[i] != ch)
        {
            push(string[i]);
        }
        else
        {
            result[j++] = string[i];

            while (top != -1)
            {
                result[j++] = pop();
            }

            break;
        }
    }

    /* If character not found, copy original string */
    if (string[i] == '\0')
    {
        strcpy(result, string);
        return;
    }

    i++;    // move to next character after ch

    while (string[i] != '\0')
    {
        result[j++] = string[i++];
    }

    result[j] = '\0';
}

int main()
{
    char string[50], result[50], ch;

    printf("Enter the string: ");
    scanf("%49s", string);

    printf("Enter the character: ");
    scanf(" %c", &ch);

    rev(string, result, ch);

    printf("The reversed string is: %s\n", result);

    return 0;
}
