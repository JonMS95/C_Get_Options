#ifndef GET_OPTIONS_API_H
#define GET_OPTIONS_API_H

#include <stdbool.h>    // bool

#define MAX_DETAIL_LEN  100

typedef struct 
{
    char    opt_char;
    char    detail[MAX_DETAIL_LEN];
    bool    has_value;
    int     min_value;
    int     max_value;
    int     assigned_value;

}option_description;

int GetOptions(int argc, char** argv, option_description* option_descr, int option_descr_size, char* opt_short);
void ShowOptions(option_description* option_descr, int option_descr_size);

#endif
