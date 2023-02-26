#include <stdio.h>      // printf
#include <getopt.h>     // getopt, optarg, ...
#include <string.h>     // strlen
#include <stdlib.h>     // atoi
#include "GetOptions.h"
#include "../Dependency_files/Header_files/SeverityLog_api.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Generates a string including the options that are meant to be inputed properly formatted.
/// @param option_descr Array of option_description structs. Each one includes information about a parameter.
/// @param option_descr_size Size of the previous input parameter.
/// @param opt_short Short form of command line arguments, properly formatted.
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
void PreParseOptions(option_description* option_descr, int option_descr_size, char* opt_short)
{
    char option_short[option_descr_size * 2 + 1];
    memset(option_short, 0, sizeof(option_short));
    
    for(int i = 0; i < option_descr_size; i++)
    {
        option_short[strlen(option_short)] = option_descr[i].opt_char;

        if(option_descr[i].has_value == HAS_VALUE_ON)
        {
            option_short[strlen(option_short)] = COLON_CHAR;
        }
    }

    strcpy(opt_short, option_short);
}

////////////////////////////////////////////////////////////////////////////////////////
/// @brief Parse all the command line parameters that are passed to the current program.
/// @param argc Argument count.
/// @param argv Argument vector.
/// @param option_descr Options description.
/// @param option_descr_size Options description strut instance size.
/// @param opt_short Short form for program's options. Autogenerated by PreParseOptions.
/// @return 0 if success, < 0 otherwise.
////////////////////////////////////////////////////////////////////////////////////////
int ParseArguments(int argc, char** argv, option_description* option_descr, int option_descr_size, char* opt_short)
{
    int option;
    int curr_opt;

    while((option = getopt(argc, argv, opt_short)) != -1)
    {
        for(curr_opt = 0; curr_opt < option_descr_size; curr_opt++)
        {
            // Check if the option exists within option_descr. 
            if(option == option_descr[curr_opt].opt_char)
            {
                // If so, checki if the option has already been assigned a value.
                if(option_descr[curr_opt].assigned_value != 0)
                {
                    SeverityLog(SVRTY_LVL_ERR, "Value already assigned to the current parameter (%s).\r\n", option_descr[curr_opt].detail);
                    return ERR_OPT_ALREADY_VALUED;
                }
                
                // Check if the option is binary, or if any value requires to be provided instead.
                if(option_descr[curr_opt].has_value == HAS_VALUE_OFF)
                {
                    option_descr[curr_opt].assigned_value = true;
                    break;
                }

                // If the option is not binary (i.e., it has to be given a value), then check if any value is provided.
                // It may also happen that the option's value is assumed to be the following parameter's first character (-p).
                if( (optarg == NULL) || (optarg[0] == '-') )
                {
                    SeverityLog(SVRTY_LVL_ERR, "A value should be passed to the current parameter (%s).\r\n", option_descr[curr_opt].detail);
                    return ERR_OPT_NEEDS_VALUE;
                }
                
                // Get integer value from provided option value.
                int option_int = atoi(optarg);

                // Check if the option value is out of boundaries or not.
                if(option_int < option_descr[curr_opt].min_value || option_int > option_descr[curr_opt].max_value)
                {
                    SeverityLog(SVRTY_LVL_ERR, "Provided option value is out of boundaries (%s) [%d-%d].\r\n",  option_descr[curr_opt].detail   ,
                                                                                                                option_descr[curr_opt].min_value,
                                                                                                                option_descr[curr_opt].max_value);
                    return ERR_OPT_VALUE_OUT_OF_BOUNDS;
                }

                // Assign the given value to the current option.
                option_descr[curr_opt].assigned_value = option_int;
                break;
            }
        }
        
        // If (iterator value) == (option_descr_size), it means that the option has noot been found.
        if(curr_opt == option_descr_size)
        {
            SeverityLog(SVRTY_LVL_ERR, "Option %c does not exist.\r\n", option);
            return ERR_OPT_DOES_NOT_EXIST;
        }
    }

    return OPT_SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////
/// @brief Calls PreparseOptions and ParseArguments. Public function.
/// @param argc Argument count.
/// @param argv Argument vector.
/// @param option_descr Options description.
/// @param option_descr_size Options description struct instance size.
/// @param opt_short Short form for program's options. Autogenerated by PreParseOptions.
/// @return 0 if success, < 0 otherwise.
////////////////////////////////////////////////////////////////////////////////////////
int GetOptions(int argc, char** argv, option_description* option_descr, int option_descr_size, char* opt_short)
{
    PreParseOptions(option_descr, option_descr_size, opt_short);
    return ParseArguments(argc, argv, option_descr, option_descr_size, opt_short);
}
