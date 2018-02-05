#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    int i, j, c, k, p;
    if (argc != 2)
    {
        printf("Wrong command-line argument");
        return 1;
    }
    k = atoi(argv[1]);
    string plaintext = get_string("plaintext:");
    for (i = 0, j = strlen(plaintext); i < j; i++)
    {
        c = plaintext[i];
        if (isalpha(c) == 0)
        {
            plaintext[i] = c;
            continue;
        }
        if (c >= 65 && c <= 90)
        {
            c = (c - 65);
            p = 65;
        }
        else if (c >= 97 && c <= 122)
        {
            c = (c - 97);
            p = 97;
        }
        c = (c + k) % 26;
        plaintext[i] = (c + p);
    }
    printf("ciphertext: %s", plaintext);
    printf("\n");
    return 0;
}