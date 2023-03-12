#ifndef GET_OPTIONS_H
#define GET_OPTIONS_H

#include "GetOptions_api.h"

#define IS_BOOL_OFF false
#define IS_BOOL_ON  true

#define COLON_CHAR      ':'

#define OPT_SUCCESS                  0
#define ERR_OPT_ALREADY_VALUED      -1
#define ERR_OPT_NEEDS_VALUE         -2
#define ERR_OPT_VALUE_OUT_OF_BOUNDS -3
#define ERR_OPT_DOES_NOT_EXIST      -4
#define ERR_OPT_UNKNOWN_VAR_TYPE    -5

void PreParseOptions(option_description* option_descr, int option_descr_size, char* opt_short);
int ParseArguments(int argc, char** argv, option_description* option_descr, int option_descr_size, char* opt_short);

#endif
