#include "study.h"

int listStudent(Student *s, int count);
int selectStudent(Student *s, int count);

int listGroup(Group *g, int count);
int makeGroup(Student *s, Group *g, int count);

void searchStudent(Student *s, int count);
void searchGroup(Group *g, int count);

void saveGroups(Group g[], int count);
int loadGroups(Group *g);

void saveStudents(Student s[], int count);
int loadStudents(Student *s);