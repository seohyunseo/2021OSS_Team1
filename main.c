#include <stdio.h>
#include "study.h"
#include "manager.h"

int main()
{
    Student st[20];

    int count_st = 0, count_gr = 0;
    int index_st = 0;
    int menu;

    while (1)
    {
        menu = selectMenu();

        if (menu == 0)
            break;
        if ((menu != 3) && (count_st == 0))
        {
            printf("=> 데이터 없음\n");
            continue;
        }
        else if (menu == 3)
        {
            count_st += createStudent(&st[index_st++]);
        }
        else if (menu == 1)
        {

            int islist;
            islist = listStudent(st, index_st);
            if (islist == 0)
                printf("=> 데이터 없음\n");
        }
        else if (menu == 4)
        {
            int isup;
            int no;
            no = selectStudent(st, index_st);
            if (no > 0)
                isup = updateStudent(&st[no - 1]);
            else if (no == 0)
                continue;
            if (isup == 1)
                printf("\n=> 수정 성공\n");
            else
                printf("\n=> 수정 실패\n");
        }
        else if (menu == 5)
        {
            int isdel;
            int no, con;
            no = selectStudent(st, index_st);
            if (no > 0)
            {
                printf("정말로 삭제하시겠습니까? (삭제:1)");
                scanf("%d", &con);
                if (con == 1)
                {
                    isdel = deleteStudent(&st[no - 1]);
                    if (isdel == 1)
                    {
                        printf("\n=> 삭제 성공\n");
                        count_st--;
                    }
                    else
                        printf("\n=> 삭제 실패\n");
                }
                else
                {
                    printf("\n=> 삭제 취소\n");
                    continue;
                }
            }
        }
        else if (menu == 6) createGroup(st, index_st + 1);
        else if (menu == 8) readGroup(st, index_st + 1);
    
    }
}