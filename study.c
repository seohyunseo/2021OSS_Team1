#include <stdio.h>
typedef struct
{
    char name[20]; //student name
    char id[10];   //student ID
    char sub[20];
    int year;
} Student;

int selectMenu()
{
    int menu;

    printf("\n*****Study Together*****\n");
    printf("1. 학생 조회하기       *\n");
    printf("2. 그룹 조회하기       *\n");
    printf("3. 학생 추가하기       *\n");
    printf("4. 학생 수정하기       *\n");
    printf("5. 학생 삭제하기       *\n");
    printf("6. 그룹 생성하기       *\n");
    printf("7. 학생 검색하기       *\n");
    printf("8. 그룹 검색하기       *\n");
    printf("9. 그룹 저장하기       *\n");
    printf("0. 프로그램 종료       *\n");
    printf("************************\n");
    printf("\n=> 메뉴를 고르시오 : ");
    scanf("%d", &menu);

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
