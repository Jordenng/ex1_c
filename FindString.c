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
int openFile(char wantedWord[257], char* filePath)
{
    char line[257];
    char *pLine;

    FILE *file = fopen(filePath, "rt"); // opening the file

    if (file == NULL) // there is no file
    {
        fprintf(stderr, "file is not valid"); // telling the user there is no file
        return -1;
    }

    while (fgets(line, 256, file) != NULL) // there is an existing file
    {
        pLine = line;
        int i =0;
        int a = tolower(wantedWord[i]);

        for (i = 0; i < 256; i++)
        {

            if (tolower(pLine[i]) == a)
            {
                if (pLine[i] == '\n')
                {
                    break;
                }
                int j = 1;
                int fine = 1;
                for (j; j < strlen(wantedWord); j++)
                {

                    if (tolower(pLine[i + j]) != tolower(wantedWord[j]))
                    {
                        fine = 0;
                        break;
                    }

                }
                if (fine)
                {
                    printf("%s \n", line);
                    break;
                }
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
    char *wantedWord = argv[1];
    char *pWantedWord = wantedWord;
//    int length = (int)strlen(argv[1]);
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
            foundWord = openFile(pWantedWord, argv[i]);
        }
        return foundWord;
    }
}







