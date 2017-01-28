#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 128

int empty_lines = 0,
    operators   = 0,
    comments    = 0;

int  menu();		
void is_empty_line(char[]);
int  is_in_comment(int);		
void operators_in_line(char[]);	
int  is_c_file(char[]);			
void read_from(int);
void write_to(int);

int main() {
	int option = menu();

	read_from(option);
	write_to(option);

	return 0;
}


int menu() {
	short option;

	system("clear"); // system("cls"); //for Windows
	printf( "> Choose an option:\n"
	        "\t1. Read from file      &&  Write to file;\n"
	        "\t2. Read from file      &&  Write on Screen;\n"
	        "\t3. Read from Keyboard  &&  Write to file;\n"
	        "\t4. Read from Keyboard  &&  Write on Screen;\n"
	        "> Your option: "
	);

	scanf("%c", &option);

	option -= '0';
	if((1 <= option) && (option <= 4)) {
		return option;
	}

	exit(0);
}

void is_empty_line(char line[]) {
	int i;

	for (i = 0; line[i] != '\0' ; i++) {
		switch(line[i]) {
			case ' ': case '\t': case '\r': case '\n': case '\0': break;
			default: return;
		}
	}

	empty_lines++;
}

int is_in_comment(int flag) {
	if(comments || (flag % 2 != 0)) return 1;
	return 0;
}

void operators_in_line(char line[]) {
    short i,
          flag = 0;
    
	if(line[0] == '#') return;
    for(i = 0; line[i] != '\0'; i++) {
        switch(line[i]) {
            case '+': case '-': case '%': case '=': 
            case '!': case '^': case '~': case '|': 
            case '&': case '<': case '>': 
                if(!is_in_comment(flag)) operators++;
                i++;
                break;
            case '/':
				if(line[++i] == '/') return;
				if(line[i] == '*') { comments++; break;}
				operators++;
				break;
			case '"':
        			if((i > 0) && (line[i-1] == '\\')) break;
				flag++;
				break;
			case '*':
				if((i < LINE_SIZE) && (line[++i] == '/')) { comments = 0; break;}
				if((!is_in_comment(flag))) operators++;
				break;
			case '\n': case '\0':
                return; 
        }
    }
}

int is_c_file(char file_name[]) {
	int i;
	for(i = 3; file_name[i] != '\0'; i++);
	if((file_name[i-2] == '.') && ((file_name[i-1] == 'C') || (file_name[i-1] == 'c'))) return 1;
	return 0;
}

void read_from(int mode) {
    FILE* fp;
    char  line[LINE_SIZE+1];

    if((mode == 1) || (mode == 2)) {
        char fileName[30];

        printf("Read from file\n"
               "NOTE: File must be *.C\n"
               "Enter file name: ");
        scanf("%s", fileName);

	    if(!is_c_file(fileName)) exit(0);
        fp = fopen(fileName, "r");
        if(!fp) {
            printf("Error with opening the file\n");
            exit(0);
        }

        printf("Reading from file ...");
    } else {
        fp = stdin;
        printf("Read from Keyboard:\n");
    }

    while (fgets(line, LINE_SIZE, fp) != NULL)	{
		is_empty_line(line);
		operators_in_line(line);
	}

    if((mode == 1) || (mode == 2))
        if(fclose(fp)) {
            printf("Error with closing the file\n");
            exit(0);
        }
}

void write_to(int mode) {
    FILE* fp;

    if((mode == 1) || (mode == 3)) {
        char fileName[30];

        printf("Write to file\n"
               "NOTE: file will be rewritten!"
               "Enter file name: ");
        scanf("%s", fileName);

        fp = fopen(fileName, "w");
        if(!fp) {
            printf("Error with opening the file\n");
            exit(0);
        }

        printf("Writting from file ...");
    } else 
        fp = stdout;

	fprintf(fp, "Empty lines: %d\nOperators: %d\n",empty_lines,operators);

    if((mode == 1) || (mode == 3)) 
        if(fclose(fp)) printf("Error with closing file\n");
}
