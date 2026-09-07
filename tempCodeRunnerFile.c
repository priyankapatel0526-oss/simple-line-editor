#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 200

char document[MAX_LINES][MAX_LENGTH];
int lineCount = 0;


/* Remove the newline from fgets() */
void removeNewline(char text[])
{
    int length = strlen(text);

    if (length > 0 && text[length - 1] == '\n')
    {
        text[length - 1] = '\0';
    }
}


/* Display all lines */
void displayDocument()
{
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\n----- DOCUMENT -----\n");

    for (i = 0; i < lineCount; i++)
    {
        printf("%d. %s\n", i + 1, document[i]);
    }

    printf("--------------------\n");
}


/* Insert a new line */
void insertLine()
{
    int lineNumber;
    int i;

    if (lineCount == MAX_LINES)
    {
        printf("\nDocument is full.\n");
        return;
    }

    printf("\nEnter line number (1 to %d): ", lineCount + 1);
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount + 1)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift existing lines downward */
    for (i = lineCount; i >= lineNumber; i--)
    {
        strcpy(document[i], document[i - 1]);
    }

    printf("Enter text: ");
    fgets(document[lineNumber - 1], MAX_LENGTH, stdin);

    removeNewline(document[lineNumber - 1]);

    lineCount++;

    printf("Line inserted successfully.\n");
}


/* Delete a line */
void deleteLine()
{
    int lineNumber;
    int i;

    if (lineCount == 0)
    {
        printf("\nDocument is empty. Nothing to delete.\n");
        return;
    }

    printf("\nEnter line number to delete: ");
    scanf("%d", &lineNumber);
    getchar();

    if (lineNumber < 1 || lineNumber > lineCount)
    {
        printf("Invalid line number.\n");
        return;
    }

    /* Shift lines upward */
    for (i = lineNumber - 1; i < lineCount - 1; i++)
    {
        strcpy(document[i], document[i + 1]);
    }

    lineCount--;

    printf("Line deleted successfully.\n");
}


/* Search for a word or phrase */
void searchDocument()
{
    char searchText[MAX_LENGTH];
    int i;
    int found = 0;

    if (lineCount == 0)
    {
        printf("\nDocument is empty.\n");
        return;
    }

    printf("\nEnter word or phrase to search: ");

    fgets(searchText, MAX_LENGTH, stdin);
    removeNewline(searchText);

    if (strlen(searchText) == 0)
    {
        printf("Search text cannot be empty.\n");
        return;
    }

    for (i = 0; i < lineCount; i++)
    {
        if (strstr(document[i], searchText) != NULL)
        {
            printf("Found at line %d: %s\n",
                   i + 1,
                   document[i]);

            found = 1;
        }
    }

    if (found == 0)
    {
        printf("Text not found.\n");
    }
}


/* Count words in a line */
int countWords(char text[])
{
    int count = 0;
    int insideWord = 0;
    int i;

    for (i = 0; text[i] != '\0'; i++)
    {
        if (!isspace((unsigned char)text[i]))
        {
            if (insideWord == 0)
            {
                count++;
                insideWord = 1;
            }
        }
        else
        {
            insideWord = 0;
        }
    }

    return count;
}


/* Display line and word count */
void showStatistics()
{
    int totalWords = 0;
    int i;

    for (i = 0; i < lineCount; i++)
    {
        totalWords += countWords(document[i]);
    }

    printf("\n----- STATISTICS -----\n");
    printf("Number of lines : %d\n", lineCount);
    printf("Number of words : %d\n", totalWords);
    printf("----------------------\n");
}


/* Display help */
void showHelp()
{
    printf("\n========== HELP ==========\n");

    printf("i - Insert a new line\n");
    printf("d - Delete a line\n");
    printf("p - Display document\n");
    printf("f - Search for text\n");
    printf("c - Count lines and words\n");
    printf("h - Show help\n");
    printf("q - Quit editor\n");

    printf("==========================\n");
}


/* Main function */
int main()
{
    char command;

    printf("==============================\n");
    printf("       SIMPLE LINE EDITOR\n");
    printf("==============================\n");

    printf("Type 'h' for help.\n");

    while (1)
    {
        printf("\nEnter command: ");
        scanf(" %c", &command);
        getchar();

        switch (command)
        {
            case 'i':
            case 'I':
                insertLine();
                break;

            case 'd':
            case 'D':
                deleteLine();
                break;

            case 'p':
            case 'P':
                displayDocument();
                break;

            case 'f':
            case 'F':
                searchDocument();
                break;

            case 'c':
            case 'C':
                showStatistics();
                break;

            case 'h':
            case 'H':
                showHelp();
                break;

            case 'q':
            case 'Q':
                printf("\nExiting line editor...\n");
                return 0;

            default:
                printf("Invalid command. Type 'h' for help.\n");
        }
    }

    return 0;
}