#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "study.h"
// typedef struct
// {
//     char name[20]; //student name
//     char id[10];   //student ID
//     char sub[20];
//     int year;
// } Student;
// typedef struct
// {
//     char sub[20];
//     char group_mem[10][10];
//     int group_num;
//     int st_num;
// } Group;

int selectMenu()
{
    int menu;

    printf("\n**************Study Together**************\n");
    printf("1. �л� ��ȸ�ϱ�[S]");
    printf("\t2. �׷� ��ȸ�ϱ�[G]\n");
    printf("3. �л� �߰��ϱ�[S]");
    printf("\t4. �׷� �����ϱ�[G]\n");
    printf("5. �л� �����ϱ�[S]");
    printf("\t6. �׷� �˻��ϱ�[G]\n");
    printf("7. �л� �����ϱ�[S]");
    printf("\t8. �׷� �����ϱ�[G]\n");
    printf("9. �л� �˻��ϱ�[S]\n");
    printf("11. �л� �����ϱ�[S]\n");
    printf("12. �л� �ҷ�����[S]");
    printf("\t0. ���α׷� ����[Q]\n");
    printf("******************************************\n");
    printf("               # ���ǻ��� #\n");
    printf("# �׷� ������ �� ���� ���� ����\n");
    printf("# ���� ���� 4�� �̻��϶� �׷� ���� ����\n");
    printf("******************************************\n");
    printf("\n=> �޴��� ���ÿ� : ");
    scanf("%d", &menu);
    getchar();

    return menu;
}

int createStudent(Student *s)
{
    printf("�л� �̸�(ex. ȫ�浿) : ");
    scanf("%s", s->name);
    printf("�й� (ex. 21700***) : ");
    scanf("%s", s->id);
    printf("�г� : ");
    scanf("%d", &s->year);
    getchar();
    printf("��� ���� (ex. ������ ����) :");
    scanf("%[^\n]", s->sub);

    return 1;
}

void readStudent(Student s)
{
    printf("%s\t%s\t%d\t%s\n", s.name, s.id, s.year, s.sub);
}

int updateStudent(Student *s)
{
    printf("�л� �̸�(ex. ȫ�浿) : ");
    scanf("%s", s->name);
    printf("�й� (ex. 21700***) : ");
    scanf("%s", s->id);
    printf("�г� : ");
    scanf("%d", &s->year);
    getchar();
    printf("��� ���� (ex. ������ ����) :");
    scanf("%[^\n]", s->sub);

    return 1;
}

int deleteStudent(Student *s)
{
    s->year = -1;

    return 1;
}

void readGroup(Group g)
{
    printf("Group%d :\n", g.group_num);
    for (int i = 0; i < 4; i++)
    {
        readStudent(g.group_mem[i]);
    }
    printf("\n");
}

void addGroupMember(Student s, Student g)
{

    strcpy(g.name, s.name);
    strcpy(g.id, s.id);
    strcpy(g.sub, s.sub);
    g.year = s.year;
}