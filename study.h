#ifndef _STUDY_H
#define _STUDY_H

typedef struct
{
    char name[20]; //student name
    char id[10];   //student ID
    char sub[20];
    int year;
} Student;

typedef struct
{
    char sub[20];
    Student group_mem[4];
    int group_num;
    int st_num;
} Group;

int selectMenu();

int createStudent(Student *s);

void readStudent(Student s);

int updateStudent(Student *s);

int deleteStudent(Student *S);

void readGroup(Group g);

void addGroupMember(Student s, Student g);

void setGroup(Group g, int groupNumber);

#endif