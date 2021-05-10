#include "manager.h"
#include <stdio.h>

int listStudent(Student *s, int count)
{
    int i;
    printf("No.\t 이름\t학번\t\t학년\t과목\n");
    for (i = 0; i < count; i++)
    {
        if (s[i].year == -1)
            continue;
        printf("%d\t", i + 1);
        readStudent(s[i]);
    }
    if (i == 0)
        return 0;
    return 1;
}

int selectStudent(Student *s, int count)
{
    int no;
    listStudent(s, count);
    printf("학생 목록번호(취소:0) : ");
    scanf("%d", &no);
    getchar();
    return no;
}
