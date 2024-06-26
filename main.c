#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#ifdef _WIN32
	#include <conio.h>
	#include <windows.h>
#else
	#include <unistd.h>
#endif
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
				printf("%d:%d:%d\n", tim->tm_hour, tim->tm_min, tim->tm_sec);
				break;
			case 12:
				if(tim->tm_hour >= 12) {
					strcpy(am_pm, "pm");
					if(tim->tm_hour != 12) {
						tim->tm_hour -= 12;
					}
				}
				else {
					strcpy(am_pm, "am");
				}
				printf("%d:%d:%d %s\n", tim->tm_hour, tim->tm_min, tim->tm_sec, am_pm);
				break;
		}
		#ifdef _WIN32
			Sleep(1000);
		#else
			sleep(1);
		#endif
		#ifdef _WIN32
			system("clear");
		#elif __linux__
			system("clear");
		#elif __APPLE__
			system("clear");
		#endif
		free(t);
		t = malloc(sizeof(time_t));
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
