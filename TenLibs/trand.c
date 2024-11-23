#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float trand_float()
{
    return ((float)rand() / (float)(RAND_MAX));
}

int trand_intlimit(int limit)
{
    return rand() % limit;
}

int trand_range(int lower, int upper){
    //NOTE: returns an integer between upper and lower limits both inclusive.
    return rand() % (upper + 1 - lower) + lower;
}
 
char trand_lowerchar()
{
    return (char) trand_range(97, 122);
}

char trand_upperchar()
{
    return (char) trand_range(65, 90);
}

char trand_charnumeric()
{
    int t = trand_range(0, 9);
    return t +'0';
}

char * trand_day()
{
    char days[7][10]  = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int day_index = rand()%7;
    char * day = days[day_index];
    char * rday = (char *)malloc(sizeof(char) * strlen(day));
    for(int i = 0; i <= strlen(day); i++){
        *(rday+i) = day[i];
    };
    return rday;
}

char trand_anycase()
{
    if(rand()%2==0)
        return trand_upperchar();
    else
        trand_lowerchar();
}

char trand_visiblechar()
{
    int t = trand_range(33, 126);
    return (char) t;
}

char * trand_alphanumeric(int len)
{
    char * aln = (char *) malloc((len+1)*sizeof(char));
    *(aln+len) = '\0';
    if(rand()%2==0)
        *(aln) = trand_lowerchar();
    else
        *(aln) = trand_upperchar();

    for(int i=1; i<len;i++)
    {
        if(rand()%2==0)
            *(aln+i) = trand_charnumeric();
        else
            *(aln+i) = trand_anycase();
    }
    
    return aln;
}

char * trand_someStr_lower(int len)
{
    char * str = (char *) malloc((len+1)*sizeof(char));
    * (str+len) = '\0';
    for(int i = 0; i < len; i++)
        * (str+i) = trand_lowerchar();
    return str;
}

char * trand_someStr_upper(int len)
{
    char * str = (char *) malloc((len+1)*sizeof(char));
    * (str+len) = '\0';
    for(int i = 0; i < len; i++)
        * (str+i) = trand_upperchar();
    return str;
}

char * trand_pseudoword_v1(int len)
{
    /*Generates a random lowercase pseudo-word.*/

    char * ptr = (char *)malloc(len + 1);
    *(ptr + len) = '\0';
    char vowels[] = {'a', 'e', 'i', 'o', 'u'};
    char consonants[] = {'b', 'c', 'd', 'e', 'f', 'k', 'l', 'm', 'n', 'p', 'r', 's', 't'};
    int clen = sizeof(consonants)/sizeof(char);
    for(int i = 0; i < len; i++)
    {
        if ((i+1)%2==0)
            *(ptr+i) = vowels[trand_range(0, 4)];
        else
            *(ptr+i) = consonants[trand_range(0, clen-1)];
    }   

    return ptr;
}

//LCC write a random number generator that returns a lower case char ; i.e. between 'a' and 'z' -- done
//UCC da.da.da upper case char ; i.e. between 'A' and 'Z' -- done
//ACC da.da single digit letter as a character i.e. '0' ... until '9' -- done
//DIG da.da.da any chase char ; i.e. either a-z or A-Z but not in between -- done
//VIS any char that is visible and valid non control chars i.e. all chars between (33)'!' upto '~'(126)
//ALN any character that is LCC or UCC or digit , but first character must not be digit
