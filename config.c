#include <stdio.h>
#include "config.h"
#include <stdlib.h>
#include <string.h>

// if you have a 10mbs file this function will take 2 years to run.
char* get_file_content(char* filename) {
    FILE* config = fopen(filename, "r");
    if (config == NULL) {
        printf("The file %s doesnt exist!", filename);
        exit(1);
    }

    size_t length = 0;
    char c;
    char* content = malloc(length+1); //zero terminated strings require 1 byte at the end otherwise trash go brrr.

    while((c = fgetc(config)) && c != EOF) {
        length++;
        content = realloc(content, length+1); //realloc memory cuz C
        content[length-1] = c;
    }

    content[length] = '\0'; //put zero at the end because nobody wants trash
    return content; //who cares about freeing stuff, this program runs in like, half a second
}

ParsedElement* parse_file(char* content, size_t* length) {
    char* name = malloc(1); 
    name[0] = '\0'; //just to make sure it'll work, C is weird
    bool is_parsing_a_value = false; //if its not parsing a value, then its parsing a name, big brain moment
    char* value = malloc(1);
    name[0] = '\0'; //same reason 

    char c = content[0];
    size_t byte = 0; //its like, the index in the string, hopefully it'll work


    ParsedElement* elements = malloc(sizeof(ParsedElement));
    size_t elements_length = 0;


    while(c != EOF && byte < strlen(content)) {
        
        if(c == ' ') {
            byte++;
            c = content[byte];
            continue;
        }
        if((c == '=' && strlen(name) == 0) || (c == '\n' && !is_parsing_a_value) || byte == strlen(content)-1 && !is_parsing_a_value) {
            printf("Parser Error: config file is invalid"); //nobody needs a proper error message
            exit(1);
        }else if (!is_parsing_a_value && c == '=') {
            is_parsing_a_value = true;
        } else if (c == '\n' || (byte == strlen(content)-1)) {
            elements_length++;
            elements = realloc(elements, elements_length*sizeof(ParsedElement));
            ParsedElement* parsed_el = malloc(sizeof(ParsedElement));
            parsed_el->name = malloc(strlen(name)+1);
            parsed_el->value = malloc(strlen(value)+1);
            strcpy(parsed_el->name, name);
            strcpy(parsed_el->value, value); 
            elements[elements_length-1] = *parsed_el; //perhaps theres a memory leak, not sure tho
            free(parsed_el);
            name = realloc(name, 1);
            name[0] = '\0';
            value = realloc(value, 1);
            value[0] = '\0';
            is_parsing_a_value = false;

            //oh god look at how many things
        }else if(!is_parsing_a_value) {
            int str_length = strlen(name);
            name = realloc(name, str_length+2);
            name[str_length] = c;
            name[str_length+1] = '\0';
           // printf("%s\n", name);
        }else {
            int str_length = strlen(value);
            value = realloc(value, str_length+2);
            value[str_length] = c;
            value[str_length+1] = '\0';
            //copy pasted code
        }
        byte++;
        c = content[byte];
    }
    *length = elements_length; //thats the way 
    return elements;
}

Config* get_config(ParsedElement* elements, size_t length) {
    Config* cfg = malloc(sizeof(Config));
    printf("%d", length);
    for(int i = 0; i < length; i++) {
        ParsedElement element = elements[i];
        //lets pretend switch doesnt exist
        if(!strcmp(element.name, "primary_color")) {

        }else if(!strcmp(element.name, "secondary_color")) {

        }else if(!strcmp(element.name, "cat_color")) {
            //handle all the colors lololololololololololol
        }else if(!strcmp(element.name, "awesome_icons")) {
            if(!strcmp(element.value, "true")) { //haha crappy code go brrr 
                cfg->awesome_icons = true;
            }else {
                cfg->awesome_icons = false; //if you put like, segs as the value it'll be false
            }
        }else{
            printf("%s is invalid", element.name);
        }
    };
    return cfg; //the compiler is screamimg on me
}