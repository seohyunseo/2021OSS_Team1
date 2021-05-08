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
    int group_mem[4][10];
    int group_num;
} Group;

int selectMenu();

int createStudent(Student *s);

int readStudent(Student *s);

int updateStudent(Student *s);

int deleteStudent(Student *S);

int readGroup(Group *g);