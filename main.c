#include <stdio.h>
#include <time.h>
#include <string.h>
// Check leap year
int is_leap_year(int year) {
    if ((year % 4 == 0 && year % 100 != 0) ||
        (year % 400 == 0)) {
        return 1;
    }

    return 0;
}
// Get days of a month of a year
void get_month_days(int month, int year){
	struct tm data = {0};
	data.tm_year = year - 1990; // time.h has date stored from 1900
	data.tm_mon = month;
	data.tm_mday = 0;
	mktime(&data);
	printf("%d\n", data.tm_mday);
}

// Get First week day of the month
void get_first_weekday(int month, int year){
	struct tm data = {0};
	data.tm_mon = month - 1;
	data.tm_year = year - 1900;
	data.tm_mday = 1;
	mktime(&data);
	printf("%d\n", data.tm_mday);

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
	int x = 0;
	char buffer[100];
	int month_days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	char *months[13] = {"JANUARY", "FEBRUARY","MARCH","APRIL", "MAY", "JUNE", "JULY",
						"AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    // For Year        
	if(argc == 2 && strcmp(argv[1],"2026") == 0){
		printf("%s\n", argv[1]);
	}
		
	get_month_days(2,2025);
	// for(int i =0;i<12;i++){
	// 	printf("Month : %s Day: %d\n", months[i], month_days[i]);
	// }		
	get_first_weekday(1, 2026);			
	return 0;
}