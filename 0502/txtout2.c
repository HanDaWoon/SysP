#include <stdio.h>
/* 텍스트 파일 내용을 표준출력에 프린트 */
int main(int argc, char *argv[])
{
    FILE *fp;
    char buffer[10] = {
        0,
    };
    if (argc < 2)
        fp = stdin; // 명령줄 인수가 없으면 표준입력 사용
    else
        fp = fopen(argv[1], "r"); // 읽기 전용으로 파일 열기

    fseek(fp, 17, SEEK_SET); // 파일 포인터를 2바이트 만큼 순방향 이동
    fread(buffer, 4, 1, fp); // 현재위치부터 4바이트만큼 순방향으로 이동
    printf("%s\n", buffer);  // 출력
    fclose(fp);
    return 0;
}
