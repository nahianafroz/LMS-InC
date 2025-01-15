#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include<conio.h>

#include <windows.h>


struct User
{
    char id[10] ;
    char name[20] ;
    char department[10] ;
    char gender[2] ;
    int phoneNumber ;
    char date[12];
} a ;

//FILE *usersFile; // Global file pointer for users data

struct books
{
    int id;
    char bookName[50];
    char authorName[50];
    char date[12];
} b ;

struct Issue
{
    int bookId;
    char userId[10];
    char userName[20] ;
    char bookName[50];
    char date[12];
    char returnDate[12] ;
} issued ;


FILE *fp;
FILE *fp2;
FILE *fp3 ;
// Function prototypes
void addBook();
void booksList();
void removeBook();
void borrowBook();
void borrowBookList();
void userPanel();
void viewBorrowedBooks();
void returnBook();
void showGuidelines();
void adminPanel() ;
void manageUser() ;
void addUser();
void listUsers();
void removeUser();
void password() ;
void endScreen() ;


#define CONSOLE_WIDTH 100
int padding = (CONSOLE_WIDTH - 30) / 2;
int menuPadding = (CONSOLE_WIDTH - 50) / 2;


int main()
{
    int ch;
    // Calculate padding to center align menu
    // int padding = (CONSOLE_WIDTH - 30) / 2;
    // int menuPadding = (CONSOLE_WIDTH - 50) / 2;

    while (1)
    {
        system("cls");

        printf ("\n\n")  ;

        // Print title with date and time
        for (int i = 0; i < padding; i++)
        {
            printf(" ");
        }
        printf("\033[3;1;4;31mLibrary Management System\033[0m\n");

        time_t t = time(NULL);
        struct tm tm = *localtime(&t);

        printf("Date: %02d/%02d/%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
        printf("Time: %02d:%02d:%02d\n", (tm.tm_hour % 12 == 0) ? 12 : tm.tm_hour % 12, tm.tm_min, tm.tm_sec);

        // Boxed menu options
        printf("\n\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("+--------------------------------------------------+\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("|\033[1;34m                  Menu Options                    \033[0m|\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("+--------------------------------------------------+\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("| 1. Admin                                         |\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("| 2. User                                          |\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("| 3. Guidelines                                    |\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("| 4. Exit                                          |\n");
        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("+--------------------------------------------------+\n\n");


        printf("\n\n\033[1;3;37mEnter your choice: \033[0m");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            // Admin panel
            password() ;
            break ;
        case 2:
            // User panel
            userPanel();
            break;
        case 3:
            // Guidelines
            showGuidelines();
            break;
        case 4:
            // Exit
            endScreen() ;


        default:
            printf("\n\t\033[33;3m Invalid Choice...\033[0m\n\n");
            Sleep(700) ;
        }


    }

    return 0;
}


void password()
{
    char ch ;
    char pass[20] ;
    char savedPass[20] = "TMF" ;


start :
    system("cls") ;

    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\033[1;31m>>> LOGIN FIRST <<<\033[0m\n");
    printf("-------------------------------------------------------------------------------------------------------------\n\n");

    printf ("\n\n") ;
    printf ("\t\t\t\t\033[1;3;37mEnter Your Password: \033[0m")  ;
    int i = 0 ;
    while (1)
    {
        ch = getch() ;
        if ( ch==13 )
        {
            pass[i] = '\0' ;
            break ;
        }
        else
        {
            pass[i++] = ch ;
            printf ("*") ;

        }

    }

    int l = strcmp(pass, savedPass ) ;
    if (l == 0)
    {
        printf ("\n\n\n\t\t\t\t\033[33;3m     Login Successfully!\033[0m\n") ;
        Sleep(700) ;
        adminPanel() ;
    }
    else
    {
        printf ("\n\n\n\t\t\t\t\033[33;3m     Invaild Password!\033[0m") ;
        Sleep(700) ;
        goto start ;
    }

}



void adminPanel()
{
    // Admin panel
    while (1)
    {
        system("cls");
        int ch ;

        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }

        printf("\n\n\t\t\t\033[3;1;4;31mLibrary Management System - Admin Panel\033[0m\n");
        printf("\n");
        printf("\t\t1. Add Book\n");
        printf("\t\t2. Books List\n");
        printf("\t\t3. Remove Book\n");
        printf("\t\t4. Add User\n") ;
        printf("\t\t5. User List\n") ;
        printf("\t\t6. Remove User\n") ;
        printf("\t\t7. Back to Main Menu\n");
        printf("\t\t8. Exit\n") ;

        printf("\n\033[1;3;37mEnter your choice: \033[0m");
        scanf("%d", &ch);

        switch (ch)
        {

        case 1:
            addBook();
            break;
        case 2:
            booksList();
            break;
        case 3:
            removeBook();
            break;

        case 4 :
            addUser();
            break ;
        case 5 :
            listUsers();
            break ;
        case 6 :
            removeUser();
            break ;
        case 7:
            main() ;
        //break;
        case 8:
            //Exit
            endScreen() ;


        default:

            printf("\n\t\033[1;34m Invalid Choice...\033[0m\n\n");
            Sleep(700) ;

        }

        if (ch == 0)
        {
            break; // Break out of admin panel loop
        }

        printf("\n");

    }

}



void addUser()
{

    system("cls");
    fflush(stdin);
    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }

    printf("\n\n\t\t\t\t\033[3;1;4;31mAdmin Panel -> Add user\033[0m\n");
    printf ("\n\n") ;
    // Get the current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(a.date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    fp2 = fopen("user.txt", "ab");


    printf("\tEnter the ID: ");
    fflush(stdin) ;
    gets(a.id);

    printf("\tEnter the Name: ");
    fflush(stdin) ;
    gets(a.name);

    printf("\tEnter the Department: ");
    fflush(stdin) ;
    gets(a.department);

    printf("\tEnter Gender [M/F]: ");
    fflush(stdin) ;
    scanf("%s", a.gender);

    fflush(stdin); // To clear the newline character from input buffer

    printf("\tEnter Phone Number: ");
    fflush(stdin) ;
    scanf("%d", &a.phoneNumber);


    printf("\n\t\t\033[33;3mUser Record Added Successfully \033[0m\n");



    fwrite(&a, sizeof(a), 1, fp2);
    fclose(fp2);

    fflush(stdin);

    // Retry screen

    char input;

    printf("\n\t\t\t\033[1;3;37mDo you want to enter more records [y/N]: \033[0m");
    scanf("%c", &input);
    fflush(stdin); // To clear the newline character from input buffer

    if (input == 'y' || input == 'Y')
    {
        addUser() ;
    }
    else if (input == 'n' || input == 'N')
    {
        printf("\n\t\t\t\t\033[1;36mRedirecting to User Panel.\033[0m");
        Sleep(700);
        adminPanel();
    }
    else
    {
        printf("\n\t\t\t\t\033[1;36mInvalid input. Redirecting to User Panel.\033[0m");
        Sleep(700);
        adminPanel() ;
    }
}



void listUsers()
{
    system("cls");
    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }

    printf("\n\n\t\t\t\t\033[3;1;4;31mAdmin Panel -> User List\033[0m\n");

    printf ("\n\n") ;
    printf("%-10s %-30s %-20s %-10s %-20s %s\n", "User Id", "Name", "Department", "Gender", "Phone Number", "Date");

    fp2 = fopen("user.txt", "rb");

    while (fread (&a, sizeof(a), 1, fp2) == 1)
    {
        printf("%-10s %-30s %-20s %-10s %-20d %s\n", a.id, a.name, a.department,a.gender, a.phoneNumber, a.date);
    }

    fclose(fp2);
    fflush(stdin) ;

    printf("\n\n\t\t\033[1;36mPress any key to return to the Admin Panel...\033[0m");
    getchar();
    adminPanel();
}



void borrowBook()
{
    system("cls");

    char userId[10];
    int bookId;
    int userFound = 0, bookFound = 0;

    printf ("\n\n") ;

    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\033[3;1;4;31mLibrary Management System - Borrow Book\033[0m\n");
    printf ("\n\n") ;
    printf("\t\tEnter User ID: ");
    scanf("%s", userId);

    printf("\t\tEnter Book ID: ");
    scanf("%d", &bookId);

    // Check if the user exists
    fp2 = fopen("user.txt", "rb");
    while (fread(&a, sizeof(a), 1, fp2) == 1)
    {
        if (strcmp(a.id, userId) == 0)
        {
            userFound = 1;
            break;
        }
    }
    fclose(fp2);

    // Check if the book exists
    fp = fopen("books.txt", "rb");
    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if (b.id == bookId)
        {
            bookFound = 1;
            break;
        }
    }
    fclose(fp);

    if (userFound && bookFound)
    {
        // Issue the book
        strcpy(issued.userId, a.id);
        strcpy(issued.userName, a.name);
        issued.bookId = b.id;
        strcpy(issued.bookName, b.bookName);

        // Get the current date
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        sprintf(issued.date, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

        // Calculate return date (7 days from today)
        struct tm *return_time = localtime(&t);
        return_time->tm_mday += 7;
        mktime(return_time); // Normalize the time
        strftime(issued.returnDate, sizeof(issued.returnDate), "%d/%m/%Y", return_time);


        fp3 = fopen("issuedBooks.txt", "ab");
        fwrite(&issued, sizeof(issued), 1, fp3);
        fclose(fp3);

        printf("\n>>> Book Issued Successfully <<<\n");
    }
    else
    {
        printf("\n\t\t\t\033[33;3m User or Book Not Found!....\n");
    }

    printf("\n\t\t\t\t\033[1;36mPress ENTER to return to the User Panel...\033[0m");
    fflush(stdin);
    getchar();
    userPanel();
}



void returnBook()
{
    system("cls");
    fflush(stdin);


    int bookId;
    int found = 0;
    printf ("\n\n") ;
    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\033[3;1;4;31mLibrary Management System - Return Book\033[0m\n");

    printf("\n\n\t\tEnter Book ID to return: ");
    scanf("%d", &bookId);

    // Temporary file to store remaining issued books
    FILE *tempFile;
    tempFile = fopen("temp.txt", "wb");
    if (tempFile == NULL)
    {
        printf("\t\t\t\t\033[33;3mError creating temporary file...\033[0m\n");
        return;
    }

    fp3 = fopen("issuedBooks.txt", "rb");
    if (fp3 == NULL)
    {
        printf("\t\t\t\t\033[33;3mError opening issued books file...\033[0m\n");
        fclose(tempFile);
        return;
    }

    while (fread(&issued, sizeof(issued), 1, fp3) == 1)
    {
        if (issued.bookId == bookId)
        {
            found = 1;
        }
        else
        {
            fwrite(&issued, sizeof(issued), 1, tempFile);
        }
    }

    fclose(fp3);
    fclose(tempFile);

    if (found)
    {
        remove("issuedBooks.txt");
        rename("temp.txt", "issuedBooks.txt");
        printf("\n\033[33;3m Book Returned Successfully \033[0m\n");
    }
    else
    {
        remove("temp.txt");
        printf("\n\t\t\t\033[33;3m Book ID Not Found in Issued Books\033[0m\n");
    }

    printf("\n\t\t\t\t\033[1;36mPress any key to return to the User Panel...\033[0m");
    fflush(stdin);
    getchar();
    userPanel();
}



void borrowBookList()
{
    system("cls");
    printf ("\n\n") ;
    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\033[3;1;4;31mLibrary Management System - Borrowed Book List\033[0m");
    printf ("\n\n\n") ;
    printf("%-10s %-20s %-10s %-30s %-12s %s\n", "User ID", "User Name", "Book ID", "Book Name", "Issue Date" , "Expected Return Date");

    fp3 = fopen("issuedBooks.txt", "rb");
    while (fread(&issued, sizeof(issued), 1, fp3) == 1)
    {
        printf("%-10s %-20s %-10d %-30s %-12s %s\n", issued.userId, issued.userName, issued.bookId, issued.bookName, issued.date , issued.returnDate );
    }
    fclose(fp3);

    printf("\n\n\n\t\t\033[1;36mPress ENTER to return to the User Panel...\033[0m");
    fflush(stdin);
    getchar();
    userPanel();
}



void removeUser()
{
    system("cls");
    fflush(stdin);

    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\n\t\t\t\t\033[3;1;4;31mAdmin Panel -> Remove User\033[0m\n\n");

    char id[10];
    printf("\n\n\t\033[1;3;37mEnter the ID of the user to be removed: \033[0m");
    fflush(stdin);
    gets(id);

    FILE *fp2, *ft;
    fp2 = fopen("user.txt", "rb");
    if (fp2 == NULL)
    {
        printf("Error opening user file...\n");
        return;
    }
    ft = fopen("temp.txt", "wb");
    if (ft == NULL)
    {
        printf("Error creating temporary file...\n");
        fclose(fp2);
        return;
    }

    int found = 0;
    while (fread(&a, sizeof(a), 1, fp2) == 1)
    {
        if (strcmp(id, a.id) != 0)
        {
            fwrite(&a, sizeof(a), 1, ft);
        }
        else
        {
            found = 1;
        }
    }

    fclose(fp2);
    fclose(ft);

    if (found == 1)
    {
        remove("user.txt");
        rename("temp.txt", "user.txt");
        printf("\n\n\t\t\t\033[33;3m User Record Deleted Successfully!....\033[0m \n");
    }
    else
    {
        remove("temp.txt");
        printf("\n\n\t\t\t\033[33;3m User ID Not Found!....\033[0m \n");
    }

    printf("\n\t\t\t\t\033[1;36mPress any key to return to the Admin Panel...\033[0m");
    fflush(stdin);
    getchar();
    adminPanel();
}


void addBook()
{

    system("cls") ;


    int d, count = 0 ;

    printf ("\n\n") ;

    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\t\t\033[3;1;4;31mAdmin Panel -> Add Book\033[0m\n") ;

    char myDate[12];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(myDate, "%02d/%02d/%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
    strcpy(b.date, myDate);

    fp = fopen("books.txt", "ab+") ;

    printf("\n\n\033[3;37mEnter book id: \033[0m");
    scanf("%d", &d) ;

    rewind(fp) ;


    while (fread (&b, sizeof(b), 1, fp ) == 1)
    {
        if (d == b.id)
        {
            printf ("\n\n\t\033[33mBook is already in the Library!.....\033[0m") ;

            count = 1 ;
            Sleep(700) ;
            addBook() ;

        }
    }
    if (count == 1 )
    {

        adminPanel() ;
    }
    b.id = d ;

    printf("\033[3;37mEnter book name: \033[0m");
    fflush(stdin);
    gets(b.bookName);

    printf("\033[3;37mEnter author name: \033[0m");
    fflush(stdin);
    gets(b.authorName);

    fseek (fp, 0, SEEK_END ) ;
    fwrite(&b, sizeof(b), 1, fp );
    fclose(fp);

    printf ("\n\n\t\033[33mBook Added Successfully!......\033[0m") ;

    //  fflush(stdin) ;
    // getchar() ;

    fwrite(&b, sizeof(b), 1, fp);
    fclose(fp);


    char input;

    printf("\n\n\t\033[1;3;37mDo you wanna enter more records [Y/N]: \033[0m");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        addBook() ;
    }
    else if(input=='n' || input=='N')
    {
        printf("\n\t\t\033[1;36mRedirecting to Book Panel.\033[0m");
        Sleep(800);
        adminPanel();
    }
    else
    {
        printf("\n\033[1;36mInvaild input. Redirecting to Book Panel.\033[0m");
        Sleep(700);
        adminPanel();
    }
}



void booksList()
{
    system("cls");
    printf ("\n\n") ;

    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\033[3;1;4;31mAdmin Panel -> Available Books \033[0m\n\n");
    printf("%-10s %-30s %-20s %s\n\n", "Book id", "Book Name", "Author", "Date");

    fp = fopen("books.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file...\n");
        return;
    }

    struct books b;

    while (fread  (&b, sizeof(b), 1, fp) == 1)
    {
        printf("%-10d %-30s %-20s %s\n", b.id, b.bookName, b.authorName, b.date);
    }

    fclose(fp);

    printf("\n");
    //fflush(stdin) ;
    printf("\n\t\033[1;36m press ENTER to go back...\033[0m");
    //getchar(); // to capture newline after the scanf
    fflush(stdin) ;
    getchar() ;
}



void removeBook()
{
    int id, f = 0;
    system("cls");
    printf ("\n\n") ;
    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\033[3;1;4;31mAdmin Panel -> Remove Books\033[0m\n\n");
    printf("\n\033[1;3;37mEnter Book id to remove: \033[0m");
    scanf("%d", &id);

    FILE *ft;

    fp = fopen("books.txt", "rb");
    if (fp == NULL)
    {
        printf("Error opening file...\n");
        return;
    }
    ft = fopen("temp.txt", "wb");
    if (ft == NULL)
    {
        printf("Error opening file...\n");
        fclose(fp);
        return;
    }

    struct books b;
    while (fread(&b, sizeof(b), 1, fp) == 1)
    {
        if (id == b.id)
        {
            f = 1;
        }
        else
        {
            fwrite(&b, sizeof(b), 1, ft);
        }
    }

    if (f == 1)
    {
        printf("\n\nDeleted Successfully.\n");
    }
    else
    {
        printf("\n\nRecord Not Found !\n");
    }

    fclose(fp);
    fclose(ft);

    remove("books.txt");
    rename("temp.txt", "books.txt");

    printf("\n");
    printf("      \033[1;36mPress ENTER To Continue...\033[0m");
    getchar(); // to capture newline after the scanf
    getchar(); // wait for user to press a key
}



void userPanel()
{
    int userChoice;

    while (1)
    {
        system("cls");

        printf ("\n\n") ;

        for (int i = 0; i < menuPadding; i++)
        {
            printf(" ");
        }
        printf("\t\t\033[3;1;4;31mLibrary Management System - User Panel\033[0m\n");
        printf("\n\n");
        printf("\t\t1. Borrow Book\n") ;
        printf("\t\t2. Book List\n") ;
        printf("\t\t3. Borrowed Book List\n") ;
        printf("\t\t4. Return a Book\n");
        printf("\t\t5. Back to Main Menu\n") ;
        printf("\t\t0. Exit\n") ;
        printf("\n\n");
        printf("\t\t\t\t\033[1;3;37mEnter your choice: \033[0m") ;
        scanf("%d", &userChoice);

        switch (userChoice)
        {
        case 1:
            borrowBook();
            break;
        case 2:
            booksList();
            break;

        case 3:
            borrowBookList();
            break;
        case 4:
            returnBook();
            break;
        case 5:
            main() ;
        case 0:
            endScreen() ;
        default:
            printf("\n\t\033[1;34m Invalid Choice...\033[0m\n\n");
            Sleep(700) ;
        }

        printf("\n");
        // printf("\t\033[1;36mPress ENTER To return to the User Panel...\033[0m");
        Sleep(700) ;
        // getchar(); // to capture newline after the scanf
        getchar(); // wait for user to press a key
    }

}



void showGuidelines()
{
    system("cls");
    printf ("\n\n") ;

    for (int i = 0; i < menuPadding; i++)
    {
        printf(" ");
    }
    printf("\033[3;1;4;31mLibrary Management System - Guidelines\033[0m\n");
    printf("\n\n");
    printf("\t1. Use the admin credentials to log in and manage the library.\n");
    printf("\t2. With the help of admin, first add yourself as user of this management system.\n" );
    printf("\t3. Access the user panel to borrow and return books. \n") ;
    printf("\t4. Return borrowed books on or before the due date.\n");
    printf("\t5. Please handle books with care.\n");
    printf("\t6. Respect the library's quiet atmosphere.\n");
    printf("\t7. Contact the librarian for any assistance.\n");
    printf("\n");
    printf("\n\t\t\t\t\033[1;36mPress ENTER To Continue....\033[0m");
    // getchar(); // to capture newline after the scanf
    fflush(stdin) ;
    getchar(); // wait for user to press a key
}



void endScreen ()
{
    system("cls");
    printf("\n\n") ;
    printf("-------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t\033[1;31m>>> ENDSCREEN <<<\033[0m\n");
    printf("-------------------------------------------------------------------------------------------------------------\n\n");

    printf("  \033[4;1;32m\n\t\t\t\t\tCREATED BY:\033[0m");
    printf("\033[1;37m\n\t\t\t\t        Nahian Afroz \033[0m");

    printf("\033[1;35m\n\n\n\t\t     Thank you for using the Library Management System.\033[0m\n\n\n\n\n\n\n\n");
    //Sleep(500) ;
    ExitProcess(0) ;
}
