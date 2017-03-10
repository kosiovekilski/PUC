# include <stdio.h>
# include <string.h>

int main () {
	
    FILE * fp = fopen ("1.mp3", "rb");
    if (fp == NULL) {
        printf ("error: file open\n");
        return 0;
    }
    fseek (fp, -128, SEEK_END);

    char tag [130];
    fread(tag, 1, 128, fp);
    
    if (strncmp (tag, "TAG", 3)) {
	    printf ("error: no tag\n");
	    return 0;
    }

    printf ("Title: %s\n", tag + 3);
    printf ("Arist: %s\n", tag + 33);
    printf ("Album: %s\n", tag + 63);
    printf ("Year : %.4s\n", tag + 93);
    
    if (fclose (fp)) {
        printf ("error: file close\n");
        return 0;
    }

    return 0;
}
