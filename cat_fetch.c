/* Meow!
 /'._
(° o 7
|'-'"~.  .
Uu^~C_J._."  
cute cat made by me! Inspired from this image: <https://knowyourmeme.com/photos/51151-ascii-art>  
*/

// Thanks to Zelis for helping me figure out what was a macro
#define BUFFER char * buffer = malloc((sizeof(char) * 256))

// Libs [just 4!]
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <string.h>

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
    if (strlen(getenv("XDG_SESSION_DESKTOP")) > 0) {
        return getenv("XDG_SESSION_DESKTOP");
    }else if (strlen(getenv("GDMSESSION")) > 0) {
        return getenv("GDMSESSION");
    }else {
        return getenv("DESKTOP_SESSION");
    }
    return (char*) "unknown";
}

// MAIN FUNCTION
int main() {
BUFFER;
printf(" /'._        \t%s", cpu());
printf("(° o 7       \t%s\n", uptime());
printf(" |'-'\"~.  ,  \t%s", distro());
printf(" Uu^~(_J._.\" \t%s\n", wm());

return 0;
}
