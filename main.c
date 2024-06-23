#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
int main() {
	time_t *t = malloc(sizeof(time_t));
	*t = time(0);
 	struct tm* tim = (struct tm*) malloc(sizeof(struct tm));
	*tim = *localtime(t);

	int* TimeFormat = (int*) malloc(sizeof(int));
	char* am_pm = (char*) malloc(sizeof(char) * 3);
	
	do {
		printf("Enter time format(24/12): ");
		scanf("%d", TimeFormat);
	}while(!(*TimeFormat == 24 || *TimeFormat == 12));

	while (1) {
		switch(*TimeFormat) {
			case 24:
				printf("%d:%d:%d\n Press Q to exit\n", tim->tm_hour, tim->tm_min, tim->tm_sec);
				break;
			case 12:
				if(tim->tm_hour >= 12) {
					strcpy(am_pm, "pm");
					if(!tim->tm_hour == 12) {
						tim->tm_hour -= 12;
					}
				}
				else {
					strcpy(am_pm, "am");
				}
				printf("%d:%d:%d %s", tim->tm_hour, tim->tm_min, tim->tm_sec, am_pm);
				break;
		}
		sleep(1);
		system("clear");
		free(t);
		t = (time_t*) malloc(sizeof(time_t));
		*t = time(0);
		free(tim);
		tim = (struct tm*) malloc(sizeof(struct tm*));
		*tim = *localtime(t);
	}

	free(t);
	free(tim);
	free(TimeFormat);
	free(am_pm);

	return 0;
} 
