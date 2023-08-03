// movie_rating_management.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#define TSIZE 45

int main()
{
    char file_name[TSIZE] = {0,};
    printf("Please intput filename to read and press Enter\n>>");

    //if (scanf("%[^\n]%*c", file_name) != 1)
    //{
    //    printf("Wrong Input. Terminating.\n");
    //    exit(1);
    //}

    FILE* fp = fopen("movies.txt", "r");

    if (fp == NULL)
    {
        printf("file is null\n");
    }

    printf("Please select an option and press endter\n");
    printf("1. Print all items \t 2. Print an item\n");
    printf("3. Edit an items \t 4. Add an item\n");
    printf("5. Insert an item \t 6. Delete an item\n");
    printf("7. Delete all items \t 8. Save file\n");
    printf("9. Search by name \t 10. Quit\n>>");

    char num[10];
    while (fscanf(fp, "%s", &num) == 1)
    {
        fprintf(fp, "%s\n", num);
        //std::cout << "fp num is" << num << std::endl;
    }



    std::cout << "Hello World!\n";
}
