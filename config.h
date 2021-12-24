/*
THIS FILE IS NOT A CONFIGURATION FILE. USE ~/.config/catfetch.conf INSTEAD.
*/

#ifndef __CONFIG__
#define __CONFIG__
#include <stdbool.h>

/*Colors because yes*/
#define COLOR_DEFAULT "\e[39m"
#define COLOR_BLACK "\e[30m"
#define COLOR_RED "\e[31m"
#define COLOR_GREEN "\e[32m"
#define COLOR_YELLOW "\e[33m"
#define COLOR_BLUE "\e[34m"
#define COLOR_MAGENTA "\e[35m"
#define COLOR_CYAN "\e[36m"
#define COLOR_LIGHT_GRAY "\e[37m"
#define COLOR_DARK_GRAY "\e[90m"
#define COLOR_LIGHT_RED "\e[91m"
#define COLOR_LIGHT_GREEN "\e[92m"
#define COLOR_LIGHT_YELLOW "\e[93m"
#define COLOR_LIGHT_BLUE "\e[94m"
#define COLOR_LIGHT_MAGENTA "\e[95m"
#define COLOR_LIGHT_CYAN "\e[96m"
#define COLOR_WHITE "\e[97m"
/*
So basically 420=69
becomes { name: "420", value: "69" }
*/

typedef struct {
    char* name;
    char* value;
}ParsedElement;

typedef struct {
    char* primary_color;
    char* secondary_color;
    char* cat_color;
    bool awesome_icons;
}Config;

ParsedElement* parse_file(char* content, size_t* length);
char* get_file_content(char * filename); //two different methods cuz its so annoying to read files in C. btw this methods exits if the file doesnt exist
Config* get_config(ParsedElement* elements, size_t length);
char* get_config_path();

#endif 