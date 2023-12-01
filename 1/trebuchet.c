#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>

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

		// First integer in the string
		for (int i=0; i<strlen(line)-1; i++) {
			//printf("[*] Count: %d\n", i);
			//printf("[*] Line[i]: %c\n", line[i]);
			if(isdigit(line[i])) {
				printf("[-] First int is: %c\n", line[i]);
				value[0] = line[i];
				break;
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
