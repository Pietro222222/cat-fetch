#ifndef __CONFIG__
#define __CONFIG__
#include <stdbool.h>

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
char* get_file_content(char * filename); //two different methods cuz its so annoying to read files in C. btw this methods exists if the file doesnt exist
Config* get_config(ParsedElement* elements, size_t length);

#endif 