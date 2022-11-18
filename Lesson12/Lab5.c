#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NAMSIZ 100


struct header
{
	char name[NAMSIZ];
	char size[12];
};

int main(int argc, char **argv)
{
    FILE* readfp;
    FILE* writefp2;

	writefp2 = fopen("Result.tar", "w");
	
	// declare struct
	char name[NAMSIZ];
	char size[12];
	
	for (int i = 1; i < argc; i++)
	{
		memset(name, "\0", sizeof(name));
		readfp = fopen(argv[i], "r");
		if (readfp == NULL)
		{
			printf("The file %s have error\n", argv[i]);
			return 0;
		}
		// get file size
		fseek(readfp, 0, SEEK_END);
		int lsize = ftell(readfp);
		rewind(readfp);
		snprintf(size, 12, "%d", lsize);
		printf("%s", size);
		snprintf(name, NAMSIZ, "%s", argv[i]);
		fwrite(name, 1, sizeof(name), writefp2);
		fputs(size, writefp2);
		while (!feof(readfp))
		{
			char buffer[512];
			int n = fread(buffer, 1, 512, readfp);
			fwrite(buffer, 1, n, writefp2);
		}
		fclose(readfp);
	}
	
	fclose(writefp2);
	
    return 0;
}
