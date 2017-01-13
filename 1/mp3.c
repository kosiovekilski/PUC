// not working well xD
#include <stdio.h>
#include <string.h>

int main() {
	char ** genre = {"Blues", "Classic Rock", "Country", "Dance", "Disco", "Funk", "Grunge", "Hip-Hop", "Jazz", "Metal", "New Age",
	"Oldies", "Other"};
	int pos = 0;
	
    FILE* fp = fopen("1.mp3", "rb");
    if (fp == NULL) {
        printf("error: file open\n");
    return 0;
    }
    fseek(fp, -128, SEEK_END);

    char tag[128+10];
    fread(tag, 1, 3, fp);
    pos = 3;
    
    if (strncmp(tag, "TAG", 3)) {
        printf("error: no tag\n");
	    return 0;
    }

    fread(tag, 1, 30, fp); // tit
    tag[30] = '\0';
    printf("  Title: %s\n", tag);
    
    fread(tag, 1, 30, fp); // art
    tag[30] = '\0';
    printf(" Artist: %s\n", tag);
    
    fread(tag, 1, 30, fp); // alb
    tag[30] = '\0';
    printf("  Album: %s\n", tag);
    
    fread(tag, 1, 4, fp); // year
    tag[4] = '\0';
    printf("   Year: %s\n", tag);
    
    
    fread(tag, 1, 30, fp); // com
    pos += 30;
    tag[30] = '\0';
    printf("Comment: %s\n", tag);

    fread(tag, 1, 1, fp); // tr num
    tag[1] = '\0';
    printf("  Track: %d\n", (int)*(tag)); // wrong track number

    fread(tag+pos, 1, 1, fp); // genre
    tag[1] = '\0';

    
    //if((int)tag[127+7] > 12) tag[127+7] = 12; // 
//	printf("  Genre: %s   \n", genre[(int)(tag[0])]); // 

    if(fclose(fp)) {
        printf("error: file close\n");
        return 0;
    }
	
    return 0;
}
