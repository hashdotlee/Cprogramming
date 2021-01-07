#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio_ext.h>

struct date
{
    int day;
    int month;
    int year;
};

void frequency()
{
    int A[20];
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    int B[20];
    int count;
    for (int i = 0; i < n ; i++)
    {
        count = 1;
        for (int j = i+1; j < n; j++)
        {
            if (B[i]!= -1 && A[i] == A[j])
            {
                {
                    count ++;
                    B[j] = -1;
                }
            }
            B[i] = count;
        }
    }
    for(int i = 0; i<n; i++){
        if(B[i]!=-1){
            printf("%d %d\n", A[i], B[i]);
        }
    }
};
void fibonacy()
{ 
    // declare array of fibonacy, max 30 item
    int A[30] = {0, 1};
    // input n
    int n;
    scanf("%d", &n);
    for (int i = 2; i < n; i++)
    {
        A[i] = A[i - 1] + A[i - 2];
    }
    printf("%d\n", A[n - 1]);
};
void checkpass()
{
    // declare condition
    int length = 1, digit = 0, alpha = 0, upper = 0, lower = 0;
    // input password
    char pass[100];
    __fpurge(stdin);
    fgets(pass, 100, stdin);
    // checking password
    length = strlen(pass) > 10;
    for (int i = 0; i < strlen(pass); i++)
    {
        digit = isdigit(pass[i]) || digit;
        alpha = isalpha(pass[i]) || alpha;
        upper = isupper(pass[i]) || upper;
        lower = islower(pass[i]) || lower;
    }
    printf("%s", length && digit && alpha && upper && lower ? "True\n" : "False\n");
};
void nextdate(){
    // declare check
    struct date current;
    struct date next;
    scanf("%d/%d/%d", &current.day, &current.month, &current.year);
    int checkday, checkmonth, checkyear,isleapyear;
    int nonleapyear[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int leapyear[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
    checkyear = current.year > 0;
    checkmonth = current.month>=1 && current.month <= 12;
    if(current.year%400 == 0||(current.year%4==0&&current.year%100!=0)){
        checkday = current.day <= leapyear[current.month-1] && current.day >= 1;
        isleapyear = 1;
    }
    else{
        checkday = current.day <= nonleapyear[current.month-1] && current.day >= 1;
        isleapyear = 0;
    }
    if(checkday&&checkmonth&&checkyear){
        current.day++;
        if(isleapyear){current.day %= leapyear[current.month-1];}
        else{current.day %= nonleapyear[current.month-1];}
        if(current.day == 1){current.month++; current.month %= 12;}
        if(current.month == 1){current.year++;};
        printf("%d/%d/%d\n", current.day, current.month, current.year);
    }
    else{
        printf("INVALID\n");
    }
    

};
int main()
{
    int choice;
    while (choice != 5)
    {
        printf("************Menu**************\n");
        printf("------------choose 1-5 -------\n");
        printf("1. frequency\n");
        printf("2. fibonacy\n");
        printf("3. checkpass\n");
        printf("4. nextdate\n");
        printf("5. end\n");
        printf("------------------------------\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            frequency();
            break;
        case 2:
            fibonacy();
            break;
        case 3:
            checkpass();
            break;
        case 4:
            nextdate();
            break;
        case 5:
            printf("End!\n");
            break;
        default:
            break;
        }
    }
    return 0;
}