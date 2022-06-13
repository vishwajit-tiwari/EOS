#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 8192

void *buff[MAX_SIZE];
//char buff1[BUFSIZ];

int main(int argc, char const *argv[])
{
    // argv[0] = Name of program, argv[1] = first argument, argv[2] = second argument
    FILE *fp1 = NULL, *fp2 = NULL;   // File pointer
    size_t fread_ret, fwrite_ret;
    int buffsize;                    // to check size of source file

    fp1 = fopen(argv[1],"r");   // Open source file in read only mode

    if(fp1 == NULL) {
        perror("Error opening source file\n");
        exit(EXIT_FAILURE);
    }

    fp2 = fopen(argv[2],"w");  // Open destination file in write only mode
    
    if(fp2 == NULL) {
        perror("Error opening destination file\n");
        exit(EXIT_FAILURE);
    }

    buffsize = atoi(argv[1]);
    ///if(buffsize > BUFSIZ)
    

    if(buffsize > MAX_SIZE)
    {
        perror("Source File size is greater than buffer\n");
        exit(EXIT_FAILURE);
    }

    // Read contents from file
    while(1)
    {
        fread_ret = fread(buff, 1, /*BUFSIZ*/sizeof(buff), fp1);
        if(fread_ret == 0) break;
        fwrite_ret = fwrite(buff, 1, fread_ret, fp2);
        if(fwrite_ret == 0) break;
    }

    printf("\nContents copied to %s\n", argv[2]);

    fclose(fp1);
    fclose(fp2);

    return 0;
}
