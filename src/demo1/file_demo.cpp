#include "demo1/file_demo.h"
#include <stdio.h>

void file_demo1() {
    FILE *fp;
    fp = fopen("D:\\code\\cpp\\cdemo1\\src\\test.txt", "r");
    if (fp != NULL) {
        while (!feof(fp)) {
            printf("%c", fgetc(fp));
        }

        fclose(fp);
    } else {
        printf("fp == null");
    }


}