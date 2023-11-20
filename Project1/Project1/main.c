#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

int main() {
    FILE* fs;
    fs = fopen("UpBitApi.txt", "r");
    while (feof(fs) == 0) {
        char str[MAX_LEN];
        fgets(str, MAX_LEN, fs);
        printf("%s", str);
    }
}