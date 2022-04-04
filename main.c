#include "ft_printf.h"
#include "test_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <limits.h>

#define SRCLINE strstr(src_code[__LINE__], "TEST")

#define TEST(fmt, ...) printf("%-40sOrig: {", SRCLINE);\
					   printf("}{%d}\n", printf(fmt, ##__VA_ARGS__));\
					   printf("%-40sYour: {", "");\
					   fflush(stdout);\
					   printf("}{%d}\n", ft_printf(fmt, ##__VA_ARGS__))

#define LABELS printf("\033[1m%-40s%13s\n\033[0m", "Format", "Output / Return")

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
	static char	*src_code[512];
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
		if (i == 512)
		{
			perror("Error: Source code array ran out of space.");
			fclose(file);
			exit(1);
		}
		line = NULL;
	}
	free(line);

	fclose(file);

	banner();

	printf(CYAN"\033[1mComplicated test\033[0m\n"RESET);
	LABELS;
	TEST("%c %i %c %d", 'c', 1, 'c', 2);

	printf(CYAN"\033[1mPercentage conversion\033[0m\n"RESET);
	LABELS;
	TEST("%%");
	TEST("%10%");
	TEST("%0.0%");

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
	TEST("%.4s", "Half not whole");

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
	TEST("%010d", 5);
	TEST("%010.2d", 6);
	TEST("%0.0d", 7);
	TEST("%hhd", (signed char) 42);
	TEST("%hhd", (signed char) -42);
	TEST("%hd", (short) 1000);
	TEST("%hd", (short) -1000);
	TEST("%ld", LONG_MAX);
	TEST("%ld", LONG_MIN);
	TEST("%lld", LLONG_MAX);
	TEST("%lld", LLONG_MIN);

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
	TEST("%010o", 5);
	TEST("%010.2o", 6);
	TEST("%0.0o", 7);
	TEST("%#o", 8);
	TEST("%hho", (unsigned char) 42);
	TEST("%ho", (unsigned short) 1000);
	TEST("%lo", ULONG_MAX);
	TEST("%lo", 0UL);
	TEST("%llo", ULLONG_MAX);
	TEST("%llo", 0ULL);

	printf(CYAN"\033[1mUnsigned conversion\033[0m\n"RESET);
	LABELS;
	TEST("%u", 0);
	TEST("%u", 1);
	TEST("%u", -1);
	TEST("%u %u %u %u", 6U, 7U, 8U, 9U);
	TEST("%10u", 1U);
	TEST("%-10u", 2U);
	TEST("%10.2u", 3U);
	TEST("%-10.2u", 4U);
	TEST("%010u", 5U);
	TEST("%010.2u", 6U);
	TEST("%0.0u", 7U);
	TEST("%0.0u", 0);
	TEST("%hhu", (unsigned char) 42);
	TEST("%hu", (unsigned short) 1000);
	TEST("%lu", ULONG_MAX);
	TEST("%lu", 0UL);
	TEST("%llu", ULLONG_MAX);
	TEST("%llu", 0ULL);

	printf(CYAN"\033[1mHex (lower) conversion\033[0m\n"RESET);
	LABELS;
	TEST("%x", 0);
	TEST("%x", 1);
	TEST("%x", -1);
	TEST("%x %x %x %x", 14, 15, 16, 17);
	TEST("%10x", 42);
	TEST("%-10x", 42);
	TEST("%10.2x", 21);
	TEST("%-10.2x", 21);
	TEST("%010x", 42);
	TEST("%010.2x", 21);
	TEST("%0.0o", 0);
	TEST("%#x", 8);
	TEST("%hhx", (unsigned char) 42);
	TEST("%hx", (unsigned short) 1000);
	TEST("%lx", ULONG_MAX);
	TEST("%lx", 0UL);
	TEST("%llx", ULLONG_MAX);
	TEST("%llx", 0ULL);

	printf(CYAN"\033[1mHeX (upper) conversion\033[0m\n"RESET);
	LABELS;
	TEST("%X", 0);
	TEST("%X", 1);
	TEST("%X", -1);
	TEST("%X %X %X %X", 14, 15, 16, 17);
	TEST("%10X", 42);
	TEST("%-10X", 42);
	TEST("%10.2X", 21);
	TEST("%-10.2X", 21);
	TEST("%010X", 42);
	TEST("%010.2X", 21);
	TEST("%#X", 8);
	TEST("%hhX", (unsigned char) 42);
	TEST("%hX", (unsigned short) 1000);
	TEST("%lX", ULONG_MAX);
	TEST("%lX", 0UL);
	TEST("%llX", ULLONG_MAX);
	TEST("%llX", 0ULL);

	printf(CYAN"\033[1mFloat conversion ☠️ \033[0m\n"RESET);
	LABELS;
	TEST("%f", FLT_MIN);
	//TEST("%f", FLT_MAX);
	TEST("%f", -0.0);
	TEST("%f", 0.0);
	TEST("%+f", -0.0);
	TEST("%+f", 0.0);
	TEST("%#+f", -0.0);
	TEST("%#+f", 0.0);

	printf(CYAN"\033[1mNan and inf\033[0m\n"RESET);
	LABELS;
	TEST("%f", 0.0 / 0.0);
	TEST("%f", -0.0 / 0.0);
	TEST("%.2f", 0.0 / 0.0);
	TEST("%.0f", 0.0 / 0.0);
	TEST("%010f", 0.0 / 0.0);
	TEST("%+#0f", 0.0 / 0.0);
	TEST("%10.1f", 0.0 / 0.0);
	TEST("% f", 0.0 / 0.0);
	TEST("%010f", 0.0 / 0.0);
	TEST("%f", 1.0 / 0.0);
	TEST("%010f", 1.0 / 0.0);
	TEST("%+#0f", 1.0 / 0.0);
	TEST("%10.1f", 1.0 / 0.0);
	TEST("% f", 1.0 / 0.0);
	TEST("%010f", 1.0 / 0.0);
	TEST("%f", -1.0 / 0.0);
	TEST("%010f", -1.0 / 0.0);
	TEST("%+#0f", -1.0 / 0.0);
	TEST("%10.1f", -1.0 / 0.0);
	TEST("% f", -1.0 / 0.0);
	TEST("%010f", -1.0 / 0.0);

	printf(CYAN"\033[1mFloat rounding\033[0m\n"RESET);
	LABELS;
	TEST("%f", 0.999999999);
	TEST("%.0f", 99.5);
	TEST("%.0f", 1.5);
	TEST("%.1f", 1.34);
	TEST("%.1f", 1.35);
	TEST("%.1f", 1.36);
	TEST("%.2f", 1.345);
	TEST("%.2f", 1.355);
	TEST("%.2f", 1.365);
	TEST("%10.1f", 0.05);
	TEST("%10.1f", -0.05);
	TEST("%10.1Lf", 0.05l);
	TEST("%10.1Lf", -0.05l);
	TEST("%10.2f", 0.005);
	TEST("%10.2f", -0.005);
	TEST("%10.1f", 0.04);
	TEST("%10.1f", -0.04);
	TEST("%10.1Lf", 0.04l);
	TEST("%10.1Lf", -0.04l);

	for (int k = 0; src_code[k]; k++)
		free(src_code[k]);
	return (0);
}
