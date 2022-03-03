#include <stdarg.h>
#include <stdio.h>

#define MAXSIZE 100

void minprintf(char *, ...);

int main(void)
{
	char   s[100] = "Hello";
	int    i = 10;
	double d = 3.14;

	minprintf("%s\n", s);
	minprintf("%d\n", i);
	minprintf("%f\n", d);
	minprintf("%p\n", &i);

	return 0;
}

void minprintf(char *fmt, ...)
{
	va_list      ap;
	char        *p;
	int          ival;
	int          oval;
	int          xval;
	unsigned int uival;
	char         cval;
	char        *sval;
	double       dval;
	int         *pval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++)
	{
		if (*p != '%')
		{
			putchar(*p);
			continue;
		}
		switch (*++p)
		{
		case 'd':
		case 'i':
			ival = va_arg(ap, int);
			printf("%d", ival);
			break;
		case 'o':
			oval = va_arg(ap, int);
			printf("%o", oval);
			break;
		case 'x':
		case 'X':
			xval = va_arg(ap, int);
			printf("%x", xval);
			break;
		case 'u':
			uival = va_arg(ap, unsigned int);
			printf("%u", uival);
			break;
		case 'c':
			cval = va_arg(ap, int);
			putchar(cval);
			break;
		case 's':
			for (sval = va_arg(ap, char *); *sval; sval++)
				putchar(*sval);
			break;
		case 'f':
			dval = va_arg(ap, double);
			printf("%f", dval);
			break;
		case 'e':
		case 'E':
			dval = va_arg(ap, double);
			printf("%e", dval);
			break;
		case 'g':
		case 'G':
			dval = va_arg(ap, double);
			printf("%g", dval);
			break;
		case 'p':
			pval = va_arg(ap, int *);
			printf("%p", pval);
			break;
		default:
			putchar(*p);
			break;
		}
	}
	va_end(ap);
}
