#ifndef TRAND   /* Include guard */
#define TRAND


//LCC write a random number generator that returns a lower case char ; i.e. between 'a' and 'z' -- done
//UCC da.da.da upper case char ; i.e. between 'A' and 'Z' -- done
//ACC da.da single digit letter as a character i.e. '0' ... until '9' -- done
//DIG da.da.da any chase char ; i.e. either a-z or A-Z but not in between -- done
//VIS any char that is visible and valid non control chars i.e. all chars between (33)'!' upto '~'(126)
//ALN any character that is LCC or UCC or digit , but first character must not be digit


float trand_float();

int trand_intlimit(int limit);

int trand_range(int lower, int upper);

char trand_lowerchar();

char trand_upperchar();

char trand_charnumeric();

char * trand_day();

char trand_anycase();

char trand_visiblechar();

char * trand_alphanumeric(int len);

char * trand_someStr_lower(int len);

char * trand_someStr_upper(int len);

char * trand_pseudoword_v1(int len);

#endif // TRAND