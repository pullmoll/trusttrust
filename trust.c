#include <stdio.h>
#include <string.h>
int main(void)
{
	FILE* fp = fopen("trusttrust.c", "r");
	char line[256];
	fseek(fp, 0x66, SEEK_SET);
	while (!feof(fp)) {
		long pos = ftell(fp);
		if (!fgets(line, sizeof(line), fp))
			break;
		if (!strcmp(line, "\t0\n")) {
			fseek(fp, pos, SEEK_SET);
			break;
		}
	}
	while (!feof(fp)) {
		int c = fgetc(fp);
		if (-1 == c)
			break;
		switch (c) {
		case '\n': printf("\t'\\n',\n"); break;
		case '\t': printf("\t'\\t',\n"); break;
		case '\'': printf("\t'\\'',\n"); break;
		case '\\': printf("\t'\\\\',\n"); break;
		default:   printf("\t'%c',\n", c);
		}
	}
	printf("\t0\n");
	return 0;
}
