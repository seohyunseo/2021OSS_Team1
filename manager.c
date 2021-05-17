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

    char targetsub[20];
    int gn = 0;

    printf("그룹을 생성할 과목(ex. 성경의 이해) : ");
    scanf("%[^\n]", targetsub);

    for(int i = 0; i < 10; i++){
        g[i].group_num = i + 1;
        g[i].st_num = 0;
        strcpy(g[i].sub, targetsub);
    }

    for(int j = 0; j < count; j++){
        if(strstr(s[j].sub, targetsub)){
            strcpy(g[gn].group_mem[g[gn].st_num].id, s[j].id);
            strcpy(g[gn].group_mem[g[gn].st_num].name, s[j].name);
            strcpy(g[gn].group_mem[g[gn].st_num].sub, s[j].sub);
            g[gn].group_mem[g[gn].st_num].year = s[j].year;
            g[gn].st_num++;
            if(g[gn].st_num == 4) gn++;
        }
    }

    printf("=> 그룹 생성 완료\n");

    return gn;
}

int listGroup(Group *g, int count)
{
    int i;
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
    FILE* fp;
    char fileName[30];

    printf("저장할 파일의 이름(ex. student_list1.txt) : ");
    scanf("%s", fileName);
    
    fp = fopen(fileName, "wt");

    for(int i = 0; i < count; i++)
    {
        if(s[i].year == -1) continue;
        fprintf(fp, "%s %s %d %s\n", s[i].name, s[i].id, s[i].year, s[i].sub);
    }

    fclose(fp);
    printf("저장되었습니다.\n");
}

int loadStudents(Student *s)
{
    int i = 0;
    FILE* fp;

    char fileName[30];
    printf("불러올 파일 이름(ex. student_list1.txt): ");
    scanf("%s", fileName);

    fp = fopen(fileName, "rt");
    for(i = 0; i  < 100; i++){
        fscanf(fp, "%s", s[i].name);
        if(feof(fp)) break;
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
    for(int i = 0; i < count; i++)
    {
        if(s[i].year == -1) continue;
        if(strstr(s[i].id, target))
        {
            printf("%d\t", i + 1);
            readStudent(s[i]);
            scnt++;
        }
    }
    if (scnt == 0) printf("데이터 없음\n");
}

void saveGroups(Group g[], int count)
{
    FILE* fp;
    char fileName[30];

    printf("저장할 파일의 이름(ex. Group1.txt) : ");
    scanf("%s", fileName);
    
    fp = fopen(fileName, "wt");

    for(int i = 0; i < count; i++)
    {
        fprintf(fp, "Group%d :\n", g[i].group_num);
        for(int j = 0; j < 4; j++){
            fprintf(fp, "%s %s %d %s\n", g[i].group_mem[j].name, g[i].group_mem[j].id, g[i].group_mem[j].year, g[i].group_mem[j].sub);
        }
    }

    fclose(fp);
    printf("저장되었습니다.\n");
}

int loadGroups(Group *g)
{
    int i = 0;
    FILE* fp;

    char fileName[30];
    printf("불러올 파일 이름(ex. Group1.txt): ");
    scanf("%s", fileName);

    fp = fopen(fileName, "rt");
    for(i = 0; i  < 100; i++){
        fscanf(fp, "Group%d :\n", &g[i].group_num);
        if(feof(fp)) break;
        for(int j = 0; j < 4; j++){
            fscanf(fp, "%s", g[i].group_mem[j].name);
            fscanf(fp, "%s", g[i].group_mem[j].id);
            fscanf(fp, "%d", &g[i].group_mem[j].year);
            fscanf(fp, " %[^\n]", g[i].group_mem[j].sub);
        }
    }
    
    fclose(fp);

    return i;
}

void searchGroup(Group *g, int count)
{
    int scnt = 0;
    char targetSub[20];
    int targetNum = 0;

    printf("검색할 그룹 과목(ex. 성경의 이해): ");
    scanf("%s", targetSub);

    printf("검색할 그룹의 번호(ex. 1): ");
    scanf("%d", &targetNum);

    for(int i = 0; i < count; i++){
        if(g[i].group_num == targetNum){
            printf("Group%d :\n", g[i].group_num);
            for(int j = 0; j < 4; j++){
                readStudent(g[i].group_mem[j]);
            }
            scnt++;
        }
    }
    if (scnt == 0) printf("데이터 없음\n");
}