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

int fflush(FILE *f)
{
	int   retval;
	int   i;
	FILE *fp;

	retval = 0;

	if (f == NULL)
	{
		for (fp = _iob; fp < _iob + OPEN_MAX; fp++)
			if ((fp->flag & _WRITE) == 0 && fflush(fp) == -1)
				retval = -1;
	}
	else
	{
		if ((f->flag & _WRITE) == 0)
			return -1;
		_flushbuf(EOF, f);
		if (f->flag & _ERR)
			retval = -1;
	}
	return retval;
}

int _flushbuf(int c, FILE *f)
{
	int           num_written, bufsize;
	unsigned char uc = c;

	if ((f->flag & (_WRITE | _EOF | _ERR)) != _WRITE)
	{
		return EOF;
	}

	if (f->base == NULL && ((f->flag & _UNBUF) == 0))
	{
		if ((f->base = malloc(BUFSIZ)) == NULL)
			f->flag |= _UNBUF;
		else
		{
			f->ptr = f->base;
			f->cnt = BUFSIZ - 1;
		}
	}

	if (f->flag & _UNBUF)
	{
		f->ptr = f->base = NULL;
		f->cnt = 0;
		if (c == EOF)
		{
			return EOF;
		}
		num_written = write(f->fd, &uc, 1);
		bufsize = 1;
	}
	else
	{
		bufsize = (int) (f->ptr - f->base);
		num_written = write(f->fd, f->base, bufsize);
		f->ptr = f->base;
		f->cnt = BUFSIZ - 1;
	}

	if (num_written == bufsize)
		return c;
	else
	{
		f->flag |= _ERR;
		return EOF;
	}
}

int fseek(FILE *fp, long offset, int origin)
{
	long l;

	if ((l = lseek(fp->fd, offset, origin)) != -1)
		return 0;
	else
		return -1;
}

int mfclose(FILE *fp) // success 0, error EOF
{
	int i;

	fp->ptr = fp->base = NULL;
	fp->cnt = 0;
	fp->flag = 00;
	i = close(fp->fd);
	if (i == 0)
		return 0;
	else
		return EOF;
}
