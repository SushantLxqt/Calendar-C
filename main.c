// Unfinished Work -> Time Taking
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <strings.h>

// Enum that assings each month to numbers
enum Month_Num {
    JAN = 1,
    FEB,
    MAR,
    APR,
    MAY,
    JUN,
    JUL,
    AUG,
    SEP,
    OCT,
    NOV,
    DEC,
};

// Check leap year
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 400 == 0)) {
        return 1;
    }

    return 0;
}

// Converting the number or month name into the enum created
void parse_month(const char *name, enum Month_Num *month){
    char *end;
    long number = strtol(name, &end, 10);

    if(*name != '\0' && *end == '\0'){
        if(number >= 1 && number <= 12){
            *month = number;
            return;
        }
        printf("INVALID MONTH\n");
        *month = 0;
        return;
    }

    const char *months[]= {
        "JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG",
        "SEP", "OCT", "NOV", "DEC"
    };

    const char *full_months[] = {
        "JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE",
        "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"
    };

    for(int i = 0; i < 12; ++i){
        if(strcasecmp(name, months[i]) == 0 ||
           strcasecmp(name, full_months[i]) == 0){
            *month = i + 1;
            return;
        }
    }

    printf("INVALID MONTH\n");
    *month = 0;
}

// Get days of a month of a year
void get_month_days(int month, int year, int today){
    struct tm data = {0};
    data.tm_year = year - 1900;
    data.tm_mon = month - 1;
    data.tm_mday = 0;
    mktime(&data);

    int days = data.tm_mday;

    // Get the first weekday of the month
    data.tm_mday = 1;
    mktime(&data);
    int first_day = data.tm_wday;

    // Print the days
    for(int k = 0; k < first_day; k++){
        printf("   ");
    }

    for(int k = 1; k <= days; k++){
        if(k == today){
            printf("\033[7m%2d\033[0m ", k);
        } else {
            printf("%2d ", k);
        }

        if((k + first_day) % 7 == 0){
            printf("\n");
        }
    }

    printf("\n");
}

// Get First week day of the month
void get_first_weekday(int month, int year){
    struct tm data = {0};
    data.tm_mon = month - 1;
    data.tm_year = year - 1900;
    data.tm_mday = 1;
    mktime(&data);
    printf("%d\n", data.tm_wday);

}

// To print all the Months and days of a year ( argv[1] )
int get_everything_year(int year){
    

    return 0;
}

int calendar(char *month){
    char buffer[100];
    time_t now = time(NULL);
    struct tm* date = localtime(&now);
    strftime(buffer, sizeof(buffer), "%B %Y", date);
    printf("   %s\n", buffer);
    return 0;
}

int main(int argc, char *argv[]){
    time_t now = time(NULL);
    struct tm* date = localtime(&now);
    int x = 0;
    char buffer[100];
    int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31};
    char *months[13] = {"JANUARY", "FEBRUARY","MARCH","APRIL", "MAY", "JUNE", "JULY",
                        "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};

    
    // To print the Current Month and its Days 
    if(argc == 1){
        int year = date->tm_year + 1900;
        int day = date->tm_mday;
        int month_rn = date->tm_mon + 1;

        char month_pl[20];
        strftime(buffer, sizeof(buffer), "    %B %Y", date);
        strftime(month_pl, sizeof(month_pl), "%B", date);
        printf("%s\n", buffer);
        printf("SU MO TU WE TH FR SA\n");

        enum Month_Num months;
        parse_month(month_pl, &months);
        get_month_days(months, year, day);
    }
    // Test the argument pass
    if(argc == 2 && strcmp(argv[1],"2026") != 0){
        printf("%s\n", argv[1]);
        enum Month_Num month = 0;

        parse_month(argv[1], &month);

        if(month == 0){
            return 1;
        }
        // The strucuture to print the DAYS
        printf("SU MO TU WE TH FR SA\n");
        // printf("Month: %d\n", month);
        // printf("Days: ");
        get_month_days(month, 2026, 0);

        // printf("First weekday: ");
        //get_first_weekday(month, 2026);
    }
    
    // for(int i =0;i<12;i++){
    //     printf("Month : %s Day: %d\n", months[i], month_days[i]);
    // }

    return 0;
}
