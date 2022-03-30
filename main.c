#include "ft_printf.h"
#include "test_printf.h"
#include <stdio.h>
#include <stdlib.h>

#define SRCLINE strstr(src_code[__LINE__], "TEST")

#define TEST(fmt, ...) printf("%-30sOrig: {", SRCLINE);\
					   printf("}{%d}\n", printf(fmt, ##__VA_ARGS__));\
					   printf("%-30sYour: {", "");\
					   fflush(stdout);\
					   printf("}{%d}\n", ft_printf(fmt, ##__VA_ARGS__))

#define LABELS printf("\033[1m%-30s%13s\n\033[0m", "Format", "Output / Return")

static const char	filename[] = "main.c";

static void	banner(void)
{
	printf(MAG"********************************************************************************\n"RESET);
	printf("%45s\n", "\033[1mtest_printf\033[0m\tcnysten");
	printf(MAG"********************************************************************************\n"RESET);
	fflush(NULL);
}

int	main(void)
{
	FILE	*file = fopen(filename, "r");
	char	*src_code[256];
	char	*line = NULL;
	size_t	linecap = 0;
	int		i = 1;

	if (!file)
	{
		perror("ERROR: Couldn't open file.");
		exit(1);
	}

	while (getline(&line, &linecap, file) > 0)
	{
		char	*semicolon;
		src_code[i] = line;

		semicolon = strrchr(src_code[i], ';');
		if (semicolon)
			*semicolon = '\0';
		i++;
		if (i == 256)
		{
			perror("Error: Source code array ran out of space.");
			fclose(file);
			exit(1);
		}
		line = NULL;
	}

	fclose(file);

	banner();

	printf(CYAN"\033[1mCharacter conversion\033[0m\n"RESET);
	LABELS;
	TEST("%c%c", 'O', 'K');
	TEST("%20c", 'R');
	TEST("%-20c", 'L');
	TEST("%1c", 'R');
	TEST("%-1c", 'L');

	printf(CYAN"\033[1mString conversion\033[0m\n"RESET);
	LABELS;
	TEST("%s %s", "Hello", "world");
	TEST("%s", "%s");
	TEST("%20s", "Right");
	TEST("%-20s", "Left");
	TEST("%1s", "Right");
	TEST("%-1s", "Left");
	TEST("%s", "");

	printf(CYAN"\033[1mPointer conversion\033[0m\n"RESET);
	LABELS;
	TEST("%p", NULL);
	TEST("%10p", NULL);
	TEST("%1p", NULL);
	TEST("%10p", "String");
	TEST("%-10p", "String");

	printf(CYAN"\033[1mDecimal conversion\033[0m\n"RESET);
	LABELS;
	TEST("%d", 0);
	TEST("%d", 1);
	TEST("%d", -1);
	TEST("%d%d%d%d", 1, 2, 3, 4);
	TEST("%10d", 1);
	TEST("%-10d", 2);
	TEST("%10.2d", 3);
	TEST("%-10.2d", 4);
	TEST("%hhd", (signed char) 42);
	TEST("%hhd", (signed char) -42);
	TEST("%hd", (short) 1000);
	TEST("%hd", (short) -1000);

	printf(CYAN"\033[1mOctal conversion\033[0m\n"RESET);
	LABELS;
	TEST("%o", 0);
	TEST("%o", 1);
	TEST("%o", -1);
	TEST("%o %o %o %o", 6, 7, 8, 9);
	TEST("%10o", 1);
	TEST("%-10o", 2);
	TEST("%10.2o", 3);
	TEST("%-10.2o", 4);
	TEST("%hho", (unsigned char) 42);
	TEST("%ho", (short) 1000);

	printf(CYAN"\033[1mFloat conversion ☠️ \033[0m\n"RESET);
	LABELS;
	TEST("%f", -0.0);
	TEST("%f", 0.0);
	TEST("%+f", -0.0);
	TEST("%+f", 0.0);
	TEST("%#+f", -0.0);
	TEST("%#+f", 0.0);
	TEST("%f", 0.0 / 0.0);
	TEST("%010f", 0.0 / 0.0);
	TEST("%+#0f", 0.0 / 0.0);
	TEST("%10.1f", 0.0 / 0.0);
	TEST("% f", 0.0 / 0.0);
	TEST("%010f", 0.0 / 0.0);

	printf(CYAN"\033[1mFloat rounding\033[0m\n"RESET);
	LABELS;
	TEST("%.0f", 99.5);
	TEST("%.0f", 1.5);
	TEST("%.1f", 1.34);
	TEST("%.1f", 1.35);
	TEST("%.1f", 1.36);
	TEST("%.2f", 1.345);
	TEST("%.2f", 1.355);
	TEST("%.2f", 1.365);
	return (0);
}
