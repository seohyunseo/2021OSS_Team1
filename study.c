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
    printf("1. 학생 조회하기[S]");
    printf("\t2. 그룹 조회하기[G]\n");
    printf("3. 학생 추가하기[S]");
    printf("\t4. 그룹 생성하기[G]\n");
    printf("5. 학생 수정하기[S]");
    printf("\t6. 그룹 검색하기[G]\n");
    printf("7. 학생 삭제하기[S]");
    printf("\t8. 그룹 저장하기[G]\n");
    printf("9. 학생 검색하기[S]\n");
    printf("11. 학생 저장하기[S]\n");
    printf("12. 학생 불러오기[S]");
    printf("\t0. 프로그램 종료[Q]\n");
    printf("******************************************\n");
    printf("               # 주의사항 #\n");
    printf("# 그룹 생성은 한 과목씩 생성 가능\n");
    printf("# 같은 과목 4명 이상일때 그룹 생성 가능\n");
    printf("******************************************\n");
    printf("\n=> 메뉴를 고르시오 : ");
    scanf("%d", &menu);
    getchar();

    return menu;
}

int createStudent(Student *s)
{
    printf("학생 이름(ex. 홍길동) : ");
    scanf("%s", s->name);
    printf("학번 (ex. 21700***) : ");
    scanf("%s", s->id);
    printf("학년 : ");
    scanf("%d", &s->year);
    getchar();
    printf("희망 과목 (ex. 성경의 이해) :");
    scanf("%[^\n]", s->sub);

    return 1;
}

void readStudent(Student s)
{
    printf("%s\t%s\t%d\t%s\n", s.name, s.id, s.year, s.sub);
}

int updateStudent(Student *s)
{
    printf("학생 이름(ex. 홍길동) : ");
    scanf("%s", s->name);
    printf("학번 (ex. 21700***) : ");
    scanf("%s", s->id);
    printf("학년 : ");
    scanf("%d", &s->year);
    getchar();
    printf("희망 과목 (ex. 성경의 이해) :");
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