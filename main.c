#include "TenLibs/trand.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define UID_BUFFER_SIZE 11
#define MAX_UID_SIZE 10
#define MIN_UID_SIZE 2
#define DBG 0


struct tinyuid {
    char str[UID_BUFFER_SIZE];
};  

typedef struct tinyuid tinyuid_t;

int tinyUID(tinyuid_t *uid, int size)
{
    if(size < MIN_UID_SIZE || size > MAX_UID_SIZE) return -1;
    
    char * uid_buffer = trand_alphanumeric(size);
    memcpy(uid->str, uid_buffer, strlen(uid_buffer)+1);

    return 0;
}

/*
    Command line arguments:
    1. The length of the UID
    2. nothing defaults to 4 chars 
*/

int main(int argc, char* argv[])
{
    int uidSize = 4;
    srand(time(NULL));

    if(DBG) printf("Before strcmp() => argc is %d\n", argc);

    if ( argc > 2 && strcmp(argv[1], "help") == 0)
    {
        printf("Usage: %s [length]\n", argv[0]);
        return -1;
    }

    if(DBG) printf("Before atoi() => uid size is %d\n", uidSize);

    if (argc > 1)
        uidSize = atoi(argv[1]);

    if(DBG) printf("Generating a TinyUID of length %d\n", uidSize);

    tinyuid_t myUID;
    int res = tinyUID(&myUID, uidSize);

    if(res < 0){
        printf("Invalid TinyUID length.\n");
        printf("length should be between %d and %d characters\n", MIN_UID_SIZE, MAX_UID_SIZE);
        printf("Usage: %s [length]\n", argv[0]);
        return -1;
    }

    if(DBG) printf("length of uid: %lld\n", strlen(myUID.str));
    printf("%s\n", myUID.str);
}