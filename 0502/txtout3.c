#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[])
{
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int lineNum = 0;
    char *find;
    char *target = argv[3];
    if (argc < 2)
        fp = stdin; // 명령줄 인수가 없으면 표준입력 사용
    else
        fp = fopen(argv[1], "r"); // 읽기 전용으로 파일 열기

    while (((read = getline(&line, &len, fp)) != -1))
    {
        lineNum++;
        if (lineNum == atoi(argv[2]))
        {
            find = strstr(line, target);
            if (find == NULL)
                printf("Can't find %s", target);
            printf("%s", find);
            break;
        }
    }
    free(line); /* getline에서 할당된 힙 메모리 해제 */
    fclose(fp);
    return 0;
}
