#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char s[2000];
    unsigned int i;
    cin.get(s, 2000);
    if(s[0] >= 97 && s[0] <= 122)
        s[0] = s[0] - 32;

    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == ' ' && s[i - 1] >= 97 && s[i - 1] <= 122)
        {
            if (i == 1)
            {
                continue;
            }
            if(i > 1 && s[i - 2] == ' ')
            {
                continue;
            }
            s[i - 1] = s[i - 1] - 32;
        }

    }
    for(i = 0; i < strlen(s); i++)
    {
        if(s[i] == ' ' && s[i + 1] >= 97 && s[i + 1] <= 122)
        {
            if(i == strlen(s) - 2)
            {
                continue;
            }
            s[i + 1] = s[i + 1] - 32;
        }

    }
    if (s[strlen(s) - 1] >= 97 && s[strlen(s) - 1] <= 122)
        s[strlen(s) - 1] = s[strlen(s) - 1] - 32;
    cout << s;
    return 0;
}