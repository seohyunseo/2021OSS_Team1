#include "study.h"

int listStudent(Student *s, int count);
int selectStudent(Student *s, int count);

int listGroup(Group *g, int count);
int makeGroup(Student *s, Group *g, int count);

int searchStudent(Student *s, int count);
int searchGroup(Group *g, int count);

void saveGroup(Group *g, int count);
int loadGroup(Group *g);
