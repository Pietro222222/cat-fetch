/* Meow!
 /'._
(° o 7
|'-'"~.  .
Uu^~C_J._."  
cute cat made by me! Inspired from this image: <https://knowyourmeme.com/photos/51151-ascii-art>  
*/
// Libs [just 5!]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "config.h"
// Thanks to Zelis for helping me figure out what was a macro
#define BUFFER char * buffer = malloc((sizeof(char) * 256))

// Uppercase function because yes
char uppercase(char letter) {
    // made with the help of Eisenchan!
    return letter >= 'a' && letter <= 'z' ? letter & ~32 : letter;
}

// CPU info function
char * cpu() {
    FILE* cpu;
    BUFFER;
    cpu = fopen("/proc/cpuinfo", "r");
    for (int i=0; i < 5; i++) {
        fgets(buffer, 256, (FILE *) cpu);
    }
    memmove(buffer, buffer+13, strlen(buffer));
    fclose(cpu);
    return buffer;
}

// Uptime info function
char * uptime() {
    int hours = 0;
    int minutes = 0;
    int seconds = 0;
    int j = 0;
    char space[] = {' '};
    FILE* uptime;
    BUFFER;
    uptime = fopen("/proc/uptime", "r");
    fscanf(uptime, "%s", buffer);
    hours = (atoi(buffer)/3600); 
	minutes = (atoi(buffer) - (3600*hours))/60;
	seconds = (atoi(buffer) - (3600*hours) - (minutes*60));
    sprintf(buffer, "%12dh %dm %ds", hours, minutes, seconds);
    while (j < 1)
    {
    memmove(buffer, buffer+1, strlen(buffer));       
    if (buffer[0] != space[0]) {
        j ++;
        }
    }
    fclose(uptime);
    return buffer;
}

// Distro name function
char * distro() {
    BUFFER;
    FILE* distro;
    distro = fopen("/etc/os-release", "r");
    for (int i=0; i < 3; i++) {
        fgets(buffer, 256, (FILE *) distro);
    }
    memmove(buffer, buffer+3, strlen(buffer));
    buffer[0] = uppercase(buffer[0]);
    fclose(distro);
    return buffer;
}

// Window Manager info function
char * wm() {
    return getenv("DESKTOP_SESSION");
}


// MAIN FUNCTION. oh really?
int main(int argc, char** argv) {
    size_t elements;
    Config* cfg = get_config(parse_file(get_file_content(get_config_path()), &elements), elements);
    BUFFER;

    if(cfg->awesome_icons == false)
    {
        puts("");
        printf("%s       /'._        \t%scpu: \t%s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color ,cpu());
        printf("%s      (° o 7       \t%suptime: %s%s\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, uptime());
        printf("%s       |'-'\"~.  ,  \t%sdistro: %s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color, distro());
        printf("%s       Uu^~(_J._.\" \t%swm: \t%s%s\n\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, wm());
    }
    else {
        puts("");
        printf("%s      /'._        \t%s\uf2db  %s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color ,cpu());
        printf("%s     (° o 7       \t%s\uf017  %s%s\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, uptime());
        printf("%s      |'-'\"~.  ,  \t%s\uf085  %s%s", cfg->cat_color ,cfg->primary_color, cfg->secondary_color, distro());
        printf("%s      Uu^~(_J._.\" \t%s\uf2d2  %s%s\n\n",cfg->cat_color ,cfg->primary_color, cfg->secondary_color, wm());
    }


    return 0;
}
