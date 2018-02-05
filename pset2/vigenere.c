#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int alphaCheck(string s)
{
    int i, n, ch;
    for (i = 0, n < strlen(s); i < n; i++)
    {
        ch = s[i];
        if ( isalpha(ch) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int calKey(int ch)
{
    int k = 0;
    if (ch >= 65 && ch <= 90)
    {
        k = (ch - 65);
    }
    else if (ch >= 97 && ch <= 122)
    {
        k = (ch - 97);
    }
    return k;
}

int main(int argc, string argv[])
{
    int i, j, k, c, p, index, in = 0;
    string key = argv[1];
    if (argc != 2 || alphaCheck(key) == 1)
    {
        printf("Wrong command-line argument");
        return 1;
    }
    //k = atoi(argv[1]);
    int lenKey = strlen(key);
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
        // Calculate key :
        if (in < lenKey)
        {
            k = calKey(key[in]);
        }
        else
        {
            index = ((in - lenKey) % lenKey);
            k = calKey(key[index]);
        }
        c = (c + k) % 26;
        plaintext[i] = (c + p);
        in++;
    }
    printf("ciphertext: %s", plaintext);
    printf("\n");
    return 0;
}