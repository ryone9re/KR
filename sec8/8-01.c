#include <fcntl.h>
#include <unistd.h>

#define BUFSIZ 8192
#define PERMS 0666

int error(void);

int main(int argc, char *argv[])
{
	int  f1, f2, n, m, o, error_code;
	char buf[BUFSIZ];

	if (argc == 3)
	{
		if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		{
			error_code = error();
			return error_code;
		}
		if ((f2 = open(argv[2], O_RDONLY, 0)) == -1)
		{
			error_code = error();
			return error_code;
		}
		while ((n = read(f1, buf, BUFSIZ)) > 0)
		{
			if ((o = write(1, buf, n)) == -1 || o != n)
			{
				error_code = error();
				return error_code;
			}
		}
		while ((m = read(f2, buf, BUFSIZ)) > 0)
		{
			if ((o = write(1, buf, m)) == -1 || o != m)
			{
				error_code = error();
				return error_code;
			}
		}
		if (n == -1 || m == -1)
		{
			error_code = error();
			return error_code;
		}
		close(f1);
		close(f2);

		return 0;
	}
	else if (argc == 2)
	{
		if ((f1 = open(argv[1], O_RDONLY, 0)) == -1)
		{
			error_code = error();
			return error_code;
		}
		while ((n = read(f1, buf, BUFSIZ)) > 0)
		{
			if ((o = write(1, buf, n)) == -1 || o != n)
			{
				error_code = error();
				return error_code;
			}
		}
		if (n == -1)
		{
			error_code = error();
			return error_code;
		}
		close(f1);

		return 0;
	}
	else
	{
		error_code = error();
		return error_code;
	}
}

int error(void)
{
	write(2, "error\n", 6);
	return 1;
}
