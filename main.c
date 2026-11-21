#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char *argv[]){
	time_t now = time(NULL);
	char buffer[100];
	char bffer[100];
	struct tm *value = localtime(&now);
	if(argc == 2 && strcmp(argv[1], "time") == 0){
		strftime(buffer, sizeof(buffer), "%H:%M:%S", value);
		printf("%s\n",buffer);
		
	}
	if(argc == 1){
		strftime(bffer, sizeof(buffer), "%B %Y", value);
		printf("  %s\n", bffer);
		printf("SU MO TU WE TH FR SA\n\n");
	}
	return 0;
}