#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Lookup table adapted from LowLevelLearning stream
typedef struct {
    char* str;
    int num;
} lookup_t;

lookup_t gTable[10] = {
	{"zero", 0},
	{"one", 1},
        {"two", 2},
	{"three", 3}, 
	{"four", 4},
	{"five", 5},
	{"six", 6},
	{"seven", 7},
	{"eight", 8},
	{"nine", 9},
};

int match(char *str) {
	for (int i=0; i<10; i++) {
	    if(!strncmp(gTable[i].str, str, strlen(gTable[i].str))) {
				    printf("Matched %s!\n", gTable[i].str);
				    return gTable[i].num;
	    }
		
	    //printf("res: %d\n", res);
	}
	return -1;

}

int main(int argc, char* argv[]) {
	if (argc<2) {
	    printf("[-] Missing arguments...\n");
	    exit(1);
	}

	FILE *input = fopen(argv[1], "r");

	if (!input) {
	    printf("[-] Invalid file\n");
	    exit(1); 
	}

	int result = 0;
	char line[256];
	
        // Loop through lines of the file 
	while(fgets(line, sizeof(line), input)) {
		printf("[*] Line: %s", line);
		int length = strlen(line)-1;
		printf("[*] Length: %d\n", length);

                // Stores resulting integers
		char value[3];

		for (int i=0; i<strlen(line)-1; i++) {
			//printf("[*] Count: %d\n", i);
			//printf("[*] Line[i]: %c\n", line[i]);
			if(isdigit(line[i])) {
				printf("[-] First int is: %c\n", line[i]);
				value[0] = line[i];
				break;
			} else {
				int matchnum = match(&line[i]);
				if (matchnum != -1) {
					value[0] = matchnum+0x30;
					printf("[-] First int is (str): %c\n", (matchnum+0x30));
				        break;
				}
				//break;
			}
		}

		// Second integer in the string
		for (int index = length-1; index >= 0; --index) {
			//printf("[*] Count: %d\n", index);
			//printf("[*] line[index]: %c\n", line[index]);
			if(isdigit(line[index])) {
				printf("[-] Last int is: %c\n", line[index]);
				value[1] = line[index];
				break;
			} else {
				int matchnum2 = match(&line[index]);
				if (matchnum2 != -1) {
					value[1] = matchnum2+0x30;
					printf("[-] Last int is (str): %c\n", (matchnum2+0x30));
				        break;
				}
				//break;
			}
		}

		// Null terminate the string
                value[3] = "\0";
		printf("[*] Value: %s\n", value);
		
		result = result + atoi(value);
		printf("[***] Result: %d\n\n", result);
	}



	fclose(input);


	return 0;
}
