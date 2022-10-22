#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int n = 3;
    char str[10] = "vinaypatel";
    for(int i=0; i<strlen(str); i++) {
        if(str[i] > 'A' && str[i] < 'Z') {
            str[i] -= 65;
            str[i] = (str[i]+n)%26;
            str[i] += 65;
        }
        else if(str[i] > 'a' && str[i] < 'z') {
            str[i] -= 97;
            str[i] = (str[i]+n)%26;
            str[i] += 97;
        }
    }
    printf("cipher text : %s\n",str);
}
