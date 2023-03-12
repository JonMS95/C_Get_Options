#include "GetOptions_api.h"

option_description opt_desc[] =
{
    {
        .opt_char   = 'a',
        .detail     = "Boolean",
        .has_value  = false,
        .var_type   = GETOPT_VAR_TYPE_BOOL,
        .min_value  = 1,
        .max_value  = 2,
        .default_value = false,
    },
    {
        .opt_char   = 'b',
        .detail     = "Integer",
        .has_value  = false,
        .var_type   = GETOPT_VAR_TYPE_INT,
        .min_value  = 1,
        .max_value  = 2,
        .default_value = 0,
    },
    {
        .opt_char   = 'c',
        .detail     = "Character",
        .has_value  = false,
        .var_type   = GETOPT_VAR_TYPE_CHAR,
        .min_value  = 'a',
        .max_value  = 'z',
        .default_value = 'x',
    },
    {
        .opt_char   = 'd',
        .detail     = "float",
        .has_value  = false,
        .var_type   = GETOPT_VAR_TYPE_FLOAT,
        .min_value  = 1.1,
        .max_value  = 2.2,
        .default_value = 1.7,
    }
};

int main(int argc, char** argv)
{
    int opt_desc_size = sizeof(opt_desc) / sizeof(opt_desc[0]);
    char options_short[opt_desc_size * 2 + 1];

    int parse_arguments = GetOptions(argc, argv, opt_desc, opt_desc_size, options_short);

    ShowOptions(opt_desc, opt_desc_size);
}