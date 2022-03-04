#include "mystdio.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define PERMS 0666

FILE _iob[OPEN_MAX] = {{0, (char *) 0, (char *) 0, _READ, 0}, {0, (char *) 0, (char *) 0, _WRITE, 1}, {0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2}};

FILE *mfopen(char *name, char *mode)
{
	int   fd;
	FILE *fp;

	if (*mode != 'r' && *mode != 'w' && *mode != 'a')
		return NULL;
	for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
		if ((fp->flag & (_READ | _WRITE)) == 0)
			break;
	if (fp >= _iob + OPEN_MAX)
		return NULL;

	if (*mode == 'w')
		fd = creat(name, PERMS);
	else if (*mode == 'a')
	{
		if ((fd = open(name, O_WRONLY, 0)) == -1)
			fd = creat(name, PERMS);
		lseek(fd, 0, 2);
	}
	else
		fd = open(name, O_RDONLY, 0);
	if (fd == -1)
		return NULL;
	fp->fd = fd;
	fp->cnt = 0;
	fp->base = NULL;
	fp->flag = (*mode == 'r') ? _READ : _WRITE;

	return fp;
}

int _fillbuf(FILE *fp)
{
	int bufsize;

	if ((fp->flag & (_READ | _EOF | _ERR)) != _READ)
		return EOF;
	bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
			return EOF;
	fp->ptr = fp->base;
	fp->cnt = read(fp->fd, fp->ptr, bufsize);
	if (--fp->cnt < 0)
	{
		if (fp->cnt == -1)
			fp->flag |= _EOF;
		else
			fp->flag |= _ERR;
		fp->cnt = 0;
		return EOF;
	}
	return (unsigned char) *fp->ptr++;
}

int fflush(FILE *fp)
{
	if (fp == NULL)
	{
		int result = 0;
		for (int i = 0; i < OPEN_MAX; i++)
			if (((&_iob[i])->flag & _WRITE) == _WRITE && fflush(&_iob[i]) == EOF)
				result = EOF;
		return result;
	}
	else if (fp < _iob || fp >= _iob + OPEN_MAX)
		return EOF;
	else if ((fp->flag & (_WRITE | _ERR | _READ)) != _WRITE)
		return EOF;

	int bufsize = (fp->flag & _UNBUF) ? 1 : BUFSIZ;
	if (fp->base == NULL)
	{
		if ((fp->base = (char *) malloc(bufsize)) == NULL)
		{
			fp->flag |= _ERR;
			return EOF;
		}
	}
	else
	{
		int n = fp->ptr - fp->base;
		if (write(fp->fd, fp->base, n) != n)
		{
			fp->flag |= _ERR;
			return EOF;
		}
	}
	fp->ptr = fp->base;
	fp->cnt = bufsize;
	return 0;
}

int _flushbuf(int c, FILE *fp)
{
	if (fp == NULL)
		return EOF;
	else if (fflush(fp) == EOF)
		return EOF;
	*fp->ptr = (unsigned char) c;
	fp->cnt--;
	return *fp->ptr++;
}

int fseek(FILE *fp, long offset, int origin)
{
	long l;

	if ((l = lseek(fp->fd, offset, origin)) != -1)
		return 0;
	else
		return -1;
}
