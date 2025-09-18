#include <stdio.h>

int main() {
    FILE *fp = fopen("monfichier.txt", "w");

    fprintf(fp, "Hello world\n");

    printf("salut"); // fprintf(stdout, "salut");

    flcose(fp);
}