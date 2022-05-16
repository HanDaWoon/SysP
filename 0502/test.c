#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *findstr(char *fileN, int lineN, char *target)
{
    FILE *fp;
    fp = fopen(fileN, "r");
    if (fp == 0)
    {
        return "File Error";
    }
    char buffer[1025];
    for (int i = 0; i < lineN; i++)
    {
        if (fgets(buffer, 1024, fp) == 0)
        {
            fclose(fp);
            return "Err";
        }
    }
    char *find_str = strstr(buffer, target);
    if (find_str == 0)
        return "Can't find";
    else
        return find_str + strlen(target);
    fclose(fp);
    if (find_str == 0)
        return "";
}

int main(int argc, char *argv[])
{

    char fileN[200];
    int lineN;
    char target[200];
    printf("%s\t %s\t %s\n", "File", "Target Line", "Target STR");
    if (scanf("%s %d %s", fileN, &lineN, target) == 3)
        printf("%s", findstr(fileN, lineN, target));
    else
        printf("Try again");
    return 0;
}
