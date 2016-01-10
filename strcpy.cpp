#include <iostream>

using namespace std;

char* strcpy(char *s1, const char *s2)
{
    char *s = s1;
    while ((*s++ = *s2++) != 0);
    return (s1);
}

int main(int argc, char const *argv[])
{
    char* a = "asfd df";
    char b[10];
    strcpy(b, a);
    cout << b;
    return 0;
}
