typedef struct
{
    char name[20]; //student name
    char id[10];   //student ID
    char sub[20];
    int year;
} Student;

int selectMenu();

int createStudent(Student *s);

int readStudent(Student *s);

int updateStudent(Student *s);

int deleteStudent(Student *S);