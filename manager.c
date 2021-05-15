#include "manager.h"
#include <stdio.h>
#include <string.h>

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

int makeGroup(Student *s, Group *g, int count)
{

    char targetsub[10];
    printf("그룹을 생성할 과목(ex. 성경의 이해) : ");
    scanf("%[^\n]", targetsub);
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (strstr(s[i].sub, targetsub))
            {
                strcpy(g->group_mem[j], s[j].id);
                strcpy(g->sub, targetsub);
                g->group_num = i + 1;
                g->st_num = j + 1;
            }
            else
                return 1;
        }
        printf("멤버 수 : %d", g[i].st_num);
        printf("그룹 수 : %d", g[i].group_num);
    }

    return 1;
}
int listGroup(Group *g, int count)
{
    int i;
    printf("과목명\t그룹 번호\t그룹원\n");
    for (i = 0; i < count; i++)
    {
        readGroup(g[i]);
    }
    if (i == 0)
        return 0;
    return 1;
}

void saveStudents(Student s[], int count)
{
    FILE *fp;
    // char fileName[30];

    // printf("저장할 파일의 이름(ex. student_list1.txt) : ");
    // scanf("%s", fileName);

    fp = fopen("student_list.txt", "wt");

    for (int i = 0; i < count; i++)
    {
        if (s[i].year == -1)
            continue;
        fprintf(fp, "%s %s %d %s\n", s[i].name, s[i].id, s[i].year, s[i].sub);
    }

    fclose(fp);
    printf("저장되었습니다.\n");
}

int loadStudents(Student *s)
{
    int i = 0;
    FILE *fp;

    // char fileName[30];
    // printf("불러올 파일 이름(ex. student_list1.txt): ");
    // scanf("%s", fileName);

    fp = fopen("student_list.txt", "rt");
    for (i = 0; i < 100; i++)
    {
        fscanf(fp, "%s", s[i].name);
        if (feof(fp))
            break;
        fscanf(fp, "%s", s[i].id);
        fscanf(fp, "%d", &s[i].year);
        fscanf(fp, " %[^\n]", s[i].sub);
    }

    fclose(fp);

    return i;
}

void searchStudent(Student *s, int count)
{
    int scnt = 0;
    char target[20];

    printf("검색할 학생 학번(ex. 21700xxx): ");
    scanf("%s", target);

    printf("No.\t 이름\t학번\t\t학년\t과목\n");
    for (int i = 0; i < count; i++)
    {
        if (s[i].year == -1)
            continue;
        if (strstr(s[i].id, target))
        {
            printf("%d\t", i + 1);
            readStudent(s[i]);
            scnt++;
        }
    }
    if (scnt == 0)
        printf("데이터 없음\n");
}