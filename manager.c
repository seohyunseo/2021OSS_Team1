#include "manager.h"
#include <stdio.h>
#include <string.h>

int listStudent(Student *s, int count)
{
    int i;
    printf("No.\t �̸�\t�й�\t\t�г�\t����\n");
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
    printf("�л� ��Ϲ�ȣ(���:0) : ");
    scanf("%d", &no);
    getchar();
    return no;
}

int makeGroup(Student *s, Group *g, int count)
{

    char targetsub[20];
    int gn = 0;

    printf("�׷��� ������ ����(ex. ������ ����) : ");
    scanf("%[^\n]", targetsub);

    for (int i = 0; i < 10; i++)
    {
        g[i].group_num = i + 1;
        g[i].st_num = 0;
        strcpy(g[i].sub, targetsub);
    }

    for (int j = 0; j < count; j++)
    {
        if (s[j].year == -1)
            continue;
        if (strstr(s[j].sub, targetsub))
        {
            strcpy(g[gn].group_mem[g[gn].st_num].id, s[j].id);
            strcpy(g[gn].group_mem[g[gn].st_num].name, s[j].name);
            strcpy(g[gn].group_mem[g[gn].st_num].sub, s[j].sub);
            g[gn].group_mem[g[gn].st_num].year = s[j].year;
            g[gn].st_num++;
            if (g[gn].st_num == 4)
                gn++;
        }
    }

    printf("=> �׷� ���� �Ϸ�\n");

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
    FILE *fp;
    char fileName[30];

    printf("������ ������ �̸�(ex. Student1.txt) : ");
    scanf("%s", fileName);

    fp = fopen(fileName, "wt");

    for (int i = 0; i < count; i++)
    {
        if (s[i].year == -1)
            continue;
        fprintf(fp, "%s %s %d %s\n", s[i].name, s[i].id, s[i].year, s[i].sub);
    }

    fclose(fp);
    printf("����Ǿ����ϴ�.\n");
}

int loadStudents(Student *s)
{
    int i = 0;
    FILE *fp;

    char fileName[30];
    printf("�ҷ��� ���� �̸�(ex. sampleStudents.txt): ");
    scanf("%s", fileName);

    fp = fopen(fileName, "rt");
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

    printf("�˻��� �л� �й�(ex. 21700xxx): ");
    scanf("%[^\n]", target);

    printf("No.\t �̸�\t�й�\t\t�г�\t����\n");
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
        printf("=> ������ ����\n");
}

void saveGroups(Group g[], int count)
{
    FILE *fp;
    char fileName[30];

    printf("������ ������ �̸�(ex. gr_����������.txt) : ");
    scanf("%s", fileName);

    fp = fopen(fileName, "wt");

    for (int i = 0; i < count; i++)
    {
        fprintf(fp, "Group%d :\n", g[i].group_num);
        for (int j = 0; j < 4; j++)
        {
            fprintf(fp, "%s %s %d %s\n", g[i].group_mem[j].name, g[i].group_mem[j].id, g[i].group_mem[j].year, g[i].group_mem[j].sub);
        }
    }

    fclose(fp);
    printf("=> ����Ϸ�\n");
}

// int loadGroups(Group *g)
// {
//     int i = 0;
//     FILE *fp;

//     char fileName[30];
//     printf("�ҷ��� ���� �̸�(ex. sampleGroups.txt): ");
//     scanf("%s", fileName);

//     fp = fopen(fileName, "rt");
//     for (i = 0; i < 100; i++)
//     {
//         // fscanf(fp, "Group%d :\n", &g[i].group_num);
//         if (feof(fp))
//             break;
//         for (int j = 0; j < 4; j++)
//         {
//             fscanf(fp, "%s ", g[i].group_mem[j].name);
//             fscanf(fp, "%s ", g[i].group_mem[j].id);
//             fscanf(fp, "%d", &g[i].group_mem[j].year);
//             fscanf(fp, " %[^\n]", g[i].group_mem[j].sub);
//         }
//     }

//     fclose(fp);

//     return i;
// }

void searchGroup(Group *g, int count)
{
    int scnt = 0;
    char targetSub[20];
    int targetNum = 0;

    printf("�˻��� �׷� ����(ex. ������ ����): ");
    scanf("%s", targetSub);

    printf("�˻��� �׷��� ��ȣ(ex. 1): ");
    scanf("%d", &targetNum);

    for (int i = 0; i < count; i++)
    {
        if (g[i].group_num == targetNum)
        {
            printf("Group%d :\n", g[i].group_num);
            for (int j = 0; j < 4; j++)
            {
                readStudent(g[i].group_mem[j]);
            }
            scnt++;
        }
    }
    if (scnt == 0)
        printf("=> ������ ����\n");
}