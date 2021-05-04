#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main () {
    char text[100];
    scanf (" %[^\n]", text);

    char reverse[strlen(text)-1];
    for (int i=0, j=strlen(text)-1; i<strlen(text); ++i, --j) {
        reverse[j] = text[i];
    }
    reverse[strlen(text)] = '\0';

    char rev[strlen(text)];
    char temp['!'];
    int i=0, j=0, k=0;
    for (i; i<=strlen(text); ++i) {
        if (isalpha(reverse[i])) {
            temp [j++] = reverse[i];
        }
        else {
            --j;
            while (j>=0) {
                rev [k++] = temp [j--];
            }
            rev [k++] = ' ';
            j = 0;
        }
    }
    rev[--k] = '\0';   
    printf ("%s", rev);
    return 0;
}