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
		printf("    %s\n", bffer);
		printf("SU MO TU WE TH FR SA\n");
		for(int i =1; i<31; i++){
			while(i<8){
				printf("%d  ", i);
				i++;
			};
			if(i==8){
				printf("\n%d  ", i);
				i++;
			}
			while(i<15){
				printf("%d ", i);
				i++;
			}
			if(i==15){
				printf("\n%2d ", i);
				i++;
			}
			while(i<22){
				printf("%d ", i);
				i++;
			}
			if(i==22){
				printf("\n%d ", i);
				i++;
			}
			while(i<29){
				printf("%d ", i);
				i++;
			}
			if(i==29){
				printf("\n%d ", i);
				i++;
				printf("%d ", i);
				i++;
				printf("%d \n\n", i);
			}

		}

	}

	return 0;
}