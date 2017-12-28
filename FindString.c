#include <stdio.h>
#include <string.h>
#include <ctype.h>




/**
 * This function opens the given files. We check that we are able to open it. Once we are able to open it, we go over
 * the lines, and try to find if the string is indeed in the file, and if so, we return the line.
 * @param wantedWord - the wanted word we are looking for.
 * @param fp - the file path.
 * @param length - length of the word.
 * @param argc - argument count.
 * @return -1 if the word isn't found, other wise 0.
 */
int openFile(char wantedWord[257], char* filePath, int length, int argc)
{
    char line[257];
    char *pLine;
    char *beginningOfTheWord;
    int i = 0;


    FILE *file = fopen(filePath, "rt"); // opening the file

    if (file == NULL) // there is no file
    {
        fprintf(stderr, "file is not valid"); // telling the user there is no file
        return -1;
    }

    while (fgets(line, 256, file) != NULL) // there is an existing file
    {
        pLine = line;
        for (int i; pLine[i]; i++) // converting to the lower letter
        {
            pLine[i] = (char) tolower(pLine[i]);
        }
        beginningOfTheWord = strchr(line, wantedWord[0]); // We found the first letter, and we can continue searching
        while (beginningOfTheWord != NULL && *beginningOfTheWord == wantedWord[i])
        {
            if (*beginningOfTheWord != wantedWord[i]) // searching the rest of line
            {
                beginningOfTheWord = strchr((line + 1), wantedWord[0]);
                i = 0;
            }
            i++;
            beginningOfTheWord++;
            if (i == length) // this means we found the entire word
            {
                if (argc == 3)
                {
                    printf("%s \n", line); // this prints the row
                }
                return 0;
            }
        }
    }
    return 0;
}

/**
 * This is the main function that runs the program.
 * @param argc - number of arguments.
 * @param argv
 * @return the line in which we found the word.
 */

int main(int argc, char *argv[])
{
//    char wantedWord[257];
    char *wantedWord = argv[1];
    char *pWantedWord = wantedWord;
//    int numOfTheFiles = argc - 2;
    int length = (int)strlen(argv[1]);
    int foundWord = 0;

    if (argc < 3) // not enough arguments
    {
        fprintf(stderr, "not enough arguments given\n");
        return 1;
    }
    else // 2 arguments given
    {

        for (int i = 2; i < argc; i++) // checking the files in a loop
        {
            foundWord = openFile(pWantedWord, argv[i], length, argc);
        }
        return foundWord;
    }
    return 0;
}







