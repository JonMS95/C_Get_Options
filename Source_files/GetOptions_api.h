#ifndef GET_OPTIONS_API_H
#define GET_OPTIONS_API_H

#include <stdbool.h>    // bool

#define GETOPT_MAX_DETAIL_LEN  100

#define GETOPT_VAR_TYPE_BOOL   0
#define GETOPT_VAR_TYPE_INT    1
#define GETOPT_VAR_TYPE_CHAR   2
#define GETOPT_VAR_TYPE_FLOAT  3

typedef union
{
    bool    boolean;
    int     integer;
    char    character;
    float   floating;

}option_data;


typedef struct 
{
    char        opt_char;
    char        detail[GETOPT_MAX_DETAIL_LEN];
    bool        has_value;
    int         var_type;
    option_data min_value;
    option_data max_value;
    option_data assigned_value;
    option_data default_value;

}option_description;

int GetOptions(int argc, char** argv, option_description* option_descr, int option_descr_size, char* opt_short);
void ShowOptions(option_description* option_descr, int option_descr_size);

#endif
