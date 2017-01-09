#include <stdio.h>
#include <string.h>

int main() {
	FILE* fp = fopen("11.mp3", "rb");
	if (fp == NULL) {
    printf("error: file open\n");
	  return 0;
	}
	fseek(fp, -128, SEEK_END);

	char tag[128+1];
	fread(tag, 1, 129, fp);

	if (!strncmp(tag, "TAG", 3)) {
		printf("error: no tag\n");
		return 0;
	}

	printf("  Title: %.30s\n", tag+3);
	printf(" Artist: %.30s\n", tag+30+3);
	printf("  Album: %.30s\n", tag+30+30+3);
	printf("   Year: %.4s \n", tag+30+30+30+3);
	printf("Comment: %.30s\n", tag+30+30+30+3+4);
	
	if(fclose(fp)) {
        printf("error: file close\n");
        return 0;
    }
	
	return 0;
}
