#define _DEFAULT_SOURCE
#include <dirent.h>
#include <fcntl.h>
#include <locale.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

//Globals
#define MAX_NAME 50

int health = 99;
int level  = 1;
char name_buf[MAX_NAME];
int name_len;
char *name = &name_buf[0];

//Room descriptions
static const char* global_filter_name = ".dungeon";

int nameFilter(const struct dirent *entry) {
    return strstr(entry->d_name, global_filter_name) != NULL;
}

//Print the room description
void describe()
{
    FILE *f;
    char s;
    f=fopen(".dungeon","r");
    printf("***********\n");
    while((s=fgetc(f))!=EOF) {
        printf("%c",s);
    }
    printf("***********\n");
    fclose(f);
}

//Save the game
void save_game()
{
    uint16_t sep = 0xFFFF;
    int fd = open(".game", O_CREAT|O_WRONLY|O_TRUNC, S_IRUSR|S_IWUSR);
    write(fd, &level, sizeof(level));
    write(fd, &sep, sizeof(sep));
    write(fd, &health, sizeof(health));
    write(fd, &sep, sizeof(sep));
    write(fd, name_buf, name_len);
    close(fd);
}

void load_game()
{
    uint16_t sep = 0xFFFF;
    int fd = open(".game", O_RDONLY, S_IRUSR|S_IWUSR);
    read(fd, &level, sizeof(level));
    read(fd, &sep, sizeof(sep));
    read(fd, &health, sizeof(health));
    read(fd, &sep, sizeof(sep));
    read(fd, name_buf, name_len);
}

//Getting Started
int main(void) {
    setlocale(LC_ALL, "");

    //read
    load_game();
    printf("AFTER READING\nLevel: %d\nHealth: %d\n", level, health);

    //write
    printf("What is your name, brave adventurer? ");
    fgets(name_buf, MAX_NAME, stdin);
    char *pos;
    if ((pos=strchr(name_buf, '\n')) != NULL) { *pos = '\0'; }
    name_len = strlen(name_buf);
    printf("Welcome, %s\n", name);

    level += 20;
    health -= 20;

    printf("AFTER WRITING\nLevel: %d\nHealth: %d\n", level, health);

    save_game();

    //Room descriptions
    struct dirent **namelist;
    int n;

    n = scandir(".", &namelist, nameFilter, alphasort);  
    if (n == -1) {
        exit(EXIT_FAILURE);
    } else if (n == 1) {
        describe();  // will read and print the room description
    } else {}

    free(namelist);
}

//"Suggest an enhancement for the game and some implementation details"
//Punish players for reaching a dead end. Something like lose a level, or some
//health when reaching a directory that has no more directories in it.