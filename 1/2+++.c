#include <stdio.h>
#include <stdlib.h>

#define LINE_SIZE 128

int empty_lines = 0,
    operators   = 0,
    comments    = 0;

int  menu();		
void is_empty_line(char[]);
int is_in_comment(int);		
void operators_in_line(char[]);	
int  is_c_file(char[]);		

void read_from_file();		
void read_from_keyboard();	
void write_to_file();		
void write_on_screen();		


int main() {
	int option = menu();

	if(option == 1 || option == 2) read_from_file();
	else read_from_keyboard();
	if(option == 1 || option == 3) write_to_file();
	else write_on_screen();

	printf("> Thank you for using my program!\n\n");

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
	short i = 0,
	      flag = 0;
	if(line[0] == '#') return;
	for (i = 0; i < LINE_SIZE; i++) {
		switch(line[i]) {
			case '+': case '-':
				i++;
				if(!is_in_comment(flag)) operators++;
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
			case '%':
				if(!is_in_comment(flag)) {i++; operators++; }
				break;
			case '<': case '>': 
				if(((line[i+1] == '<') || (line[i+1] == '>')) && (line[i+2] == '=')) i++;
			case '=': case '!': case '^': case '~': case '|': case '&': case '.': 
				i++;
				if(!is_in_comment(flag))  operators++;
				break;
			case '\n':
				return;
			case '\0':
				return;
		}
	}

}

int is_c_file(char file_name[]) {
	int i;
	for(i = 1; file_name[i] != '\0'; i++);
	i -= 2;
	if((file_name[i] == '.') && ((file_name[i+1] == 'C') || (file_name[i+1] == 'c'))) return 1;
	else return 0;
}

void read_from_file() {
	char file_name[128],
	     line[LINE_SIZE+1];

	printf("> Read from file:\n"
	       "\t> WARNING: must be C file\n"
	       "\t> Enter file name: ");
	scanf(" %s", file_name);
	if(!is_c_file(file_name)) exit(0);

	FILE *fp = fopen(file_name, "r");
	if(fp == NULL) {
		printf("> No such file!\n");
		exit(0);
	}
	printf("\t> File opened\n");

	while (fgets(line, LINE_SIZE, fp) != NULL)	{
		is_empty_line(line);
		operators_in_line(line);
	}

	if(!fclose(fp)) printf("\t> File closed\n\n");
}

void read_from_keyboard() {
	char line[LINE_SIZE+1];
	printf("> TIPS:\n"
	       "\t- For linux   use CTRL+D for end\n"
	       "\t- For windows use CTRL+Z for end\n"
	       "> Read from keyboard:\n");
	while (fgets(line, LINE_SIZE, stdin) != NULL)	{ 
		is_empty_line(line);
		operators_in_line(line);
	}
	printf("\n");
}

void write_to_file() {
	char file_name[128],
	     rewritefile = 'n';

	printf("> Write to file:\n");
	printf("\t> Enter file name: ");
	scanf(" %s", file_name);
	printf("\t> WARNING: \"%s\" will be rewritten!\n"                                  
	       "\t> Are you sure you want to continue? (y/n): ", file_name);

	scanf(" %c", &rewritefile);
	if(rewritefile != 'y') {
		write_on_screen();
		return;
	}

	FILE *fp = fopen(file_name, "w");
	if(fp == NULL) {
		printf("> error: with file \n");
    write_on_screen();
		return;
	}
	printf("\t> File opened\n");

	fprintf(fp, "Empty lines: %d\nOperators: %d\n",empty_lines,operators);

	if(!fclose(fp)) printf("\t> File closed\n\n");
}

void write_on_screen() {
	printf( "\n> RESULTS:\n"
		"\t Empty lines found: \t%d\n"
		"\t   Operators found: \t%d\n\n", empty_lines, operators);
}

/*

+  -  *  /  %
+= -= *= /= %=
++ --

< <= > >= == != && || !

&  |  ^ ~
&= |= ^=
<< >>
<<= >>=

= . ->

no () [] , ?:
*/

