#include <iostream>

#define LMAX 10
#define TSIZE 45

 struct movie
{
    char title[TSIZE];
    float rating;
};
int main()
{
    movie movie_list[LMAX];

    char file_name[TSIZE] = { 0, };
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

    int num;
    if (fscanf(fp, "%d%*c", &num) != 1)
    {
        printf("Error: Wrong file format.");
        exit(1);
    }

    printf("%d items have been read from the file.\n", num);


    for (int n = 0; n < num; ++n)
    {
        // 해당 코드 정규표현식과 rating에 &이 왜 들어가는지 확인해보기
        if (fscanf(fp, "%[^\n]%*c", movie_list[n].title) != 1 ||
            fscanf(fp, "%f%*c", &movie_list[n].rating) != 1)
        //if (fscanf(fp, "%[^\n]%*c", movie_list[n].title) != 1 ||
        //    fscanf(fp, "%f%*c", &movie_list[n].rating) != 1)
        {
            printf("ERROR: Wrong file format.\n");
            exit(1);
        }
    }


    printf("Please select an option and press endter\n");
    printf("1. Print all items \t 2. Print an item\n");
    printf("3. Edit an items \t 4. Add an item\n");
    printf("5. Insert an item \t 6. Delete an item\n");
    printf("7. Delete all items \t 8. Save file\n");
    printf("9. Search by name \t 10. Quit\n>>");

    char str[TSIZE];
    int select;

    movie test[1];
    int index;
    scanf("%d", &select);
   
    while (select != 10)
    {
        if (select == 1)
        {
            for (int i = 0; i < num; i++)
            {
                printf("%d: \"%s\", %.1f\n", i, movie_list[i].title, movie_list[i].rating);
                //fgets(str, sizeof(str), fp);
                //str[strlen(str) - 1] = '\0';
                //printf("%d: \"%s\", ", i, str);

                //fgets(str, sizeof(str), fp);
                //printf("%s", str);
            }
        }
        else if (select == 2)
        {
            printf("input the index of item to print\n>> ");
            scanf("%d", &index);

            if (index > num)
                printf("invalid item\n");
            else
                printf("%d: \"%s\, %.1f\n", index, movie_list[index].title, movie_list[index].rating);
        }
        else if (select == 3)
        {
            printf("input the index of item to edit\n>> ");
            scanf("%d", &index);
            printf("input new title and press enter\n>> ");
            //예외처리
            scanf("%s", &movie_list[index].title);
            printf("input new rating and press enter\n>> ");
            scanf("%f", &movie_list[index].rating);
            printf("%d: \"%s\", %.1f\n", index, movie_list[index].title, movie_list[index].rating);
        }
        else if (select == 4)
        {
            num += 1;
            printf("input the title and press enter\n >> ");
            scanf("%s", &movie_list[num - 1].title);
            printf("input the rating and press enter\n >> ");
            scanf("%f", &movie_list[num - 1].rating);
            printf("%d: \"%s\", %.1f\n", num - 1, movie_list[num - 1].title, movie_list[num - 1].rating);
        }
        else if (select == 5)
        {
            printf("input the index of item to insert.\n>> ");
            scanf("%d", &index);
            movie new_movie;

            printf("input title and press enter.\n>> ");
            scanf("%s", new_movie.title);
            printf("input rating and press enter.\n>> ");
            scanf("%f", &new_movie.rating);

            printf("%s, %.1f\n", new_movie.title, new_movie.rating);

            movie tmp = movie_list[index];
            strcpy(movie_list[index].title, new_movie.title);
            movie_list[index].rating = new_movie.rating;

            num += 1;
            for (int i = index; i < num; ++i)
            {
                movie tmp2 = movie_list[i+1];
                strcpy(movie_list[i + 1].title, tmp.title);
                movie_list[i+1].rating = tmp.rating;
                tmp = tmp2;
            }

        }
        else if (select == 6)
        {
            printf("input the index of item to delete\n>> ");
            scanf("%d", &index);
            //delete movie_list[index];
            for (int i = index; i < num; i++)
            {
                if (i == num - 1)
                {
                    strcpy(movie_list[i].title, NULL);
                    movie_list[i].rating = NULL;
                }

                strcpy(movie_list[i].title, movie_list[i + 1].title);
                movie_list[i].rating = movie_list[i + 1].rating;
            }
            num -= 1;
        }
        else if (select == 7)
        {
            //for (int i = 0; i < num; ++i)
            //{
            //    strcpy(movie_list[i].title, NULL);
            //    movie_list[i].rating = NULL;
            //}
            num = 0;
        }
        else if (select == 8)
        {
            FILE* ofp = fopen("edit_movie.txt", "w+");
            fprintf(ofp, "%d\n", num);
            //fputs((char*)&num, ofp);
            for (int i = 0; i < num; i++)
            {
                //fputs(movie_list[i].title,ofp);
                fprintf(ofp, "%s\n", movie_list[i].title);
                fprintf(ofp, "%.1f\n", movie_list[i].rating);

            }
            fclose(ofp);
        }
        else if (select == 9)
        {
            char searchTxt[TSIZE];
            printf("input title to search and pressenter\n>> ");
            scanf(searchTxt, sizeof(searchTxt));
            int i = 0;
            

            std::cout << "searchTxt: " << searchTxt << std::endl;
            while (strcmp(searchTxt, movie_list[i].title) != 0)
            {
                std::cout << "tset: " << strcmp(searchTxt, movie_list[i].title) << std::endl;
                if ((num-1) == i)
                {
                    std::cout << "movie_list[i].title: " << movie_list[i].title << std::endl;
                    printf("No movie Found: %s\n", searchTxt);
                    break;
                }
                ++i;
            }

            printf("%d: \"%s\", %.1f\n", i, movie_list[i].title, movie_list[i].rating);

        }
        else if (select == 10)
        {
            exit(1);

        }
        else 
        {
            printf("pass");
        }

        printf("Please select an option and press endter\n>>");
        scanf("%d", &select);
    }


    //while (fscanf(fp, "%s", &num) == 1)
    //{
    //    fprintf(fp, "%s\n", num);
    //    //std::cout << "fp num is" << num << std::endl;
    //}



    std::cout << "Hello World!\n";
}
