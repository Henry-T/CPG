

#include <stdio.h>

// ! this function has side effect: file seek pointer get changed!
long getFileLength(FILE *fp) {
	fseek(fp, 0L, SEEK_END);
	return ftell(fp);	
}

int main() {
	FILE *fp_cygwin, *fp_win;
	long fLen_cygwin, fLen_win;
	// EOF on windows is -1. use unsigned char will result in infinate loop when guard file ending character with EOF
	signed char ch;   
	int index = 0;

	fp_cygwin = fopen("cygwin.teext", "r");
	fp_win = fopen("win.teext", "r");

	// file length in text mode
	fLen_cygwin = getFileLength(fp_cygwin);
	fLen_win = getFileLength(fp_win);
	printf("cygwin text file length: %d\n", fLen_cygwin);
	printf("win text file length: %d\n", fLen_win);

	// --------------------------------
	printf("file char values - guard by file length:\n");
	rewind(fp_cygwin);
	rewind(fp_win);

	printf("cygwin:\t");
	for(int i=0; i<fLen_cygwin; i++) {
		printf("%d ", getc(fp_cygwin));
	}
	printf("\n");

	printf("win:\t");
	for(int i=0; i<fLen_win; i++) {
		printf("%d ", getc(fp_win));
	}
	printf("\n");


	// --------------------------------
	printf("file char values - guard by EOF(%d)\n", EOF);
	rewind(fp_cygwin);
	rewind(fp_win);

	printf("cygwin:\t");
	while((ch = getc(fp_cygwin))!=EOF) {
		printf("%d ", ch);
	}
	printf("\n");

	printf("win:\t");
	while((ch = getc(fp_win))!=EOF) {
		printf("%d ", ch);
	}

	// --------------------
	fclose(fp_cygwin);
	fclose(fp_win);
}