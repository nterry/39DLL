#pragma once
#include "includes.h"
class CBuffer
{
	static char retval[20001];
public:
	char* data;
	int BuffSize;
	int readpos;
	int writepos;
	void StreamWrite(void *in, int size);
	void StreamRead(void* out, int size);
	int count;
	CBuffer();
	~CBuffer();
	int writebyte(unsigned char a);
	int writeshort(short a);
	int writeushort(unsigned short a);
	int writeint(int a);
	int writeuint(unsigned int a);
	int writefloat(float a);
	int writedouble(double a);
	int writechars(char*str);
	int writestring(char*str);
	unsigned char readbyte();
	short readshort();
	unsigned short readushort();
	int readint();
	unsigned int readuint();
	float readfloat();
	double readdouble();
	char*readchars(int len);
	char*readstring();
	int bytesleft();
	char* readsep(char* sep);
	void StreamSet(int pos);
	void clear();
	int addBuffer(char*, int);
	int addBuffer(CBuffer*);
	char operator[](int index);
};
