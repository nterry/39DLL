#pragma once
#include "includes.h"
#include "buffer.h"
#include <Iphlpapi.h>
#include <Wininet.h>
void CalculateMD5(char *, int, char *);
class CTools
{
public:
	static char* getmacaddress();
	static char* md5buffer(CBuffer*buff);
	static char* md5string(char*str);
	static unsigned int ip2uint(char*ip);
	static char* uint2ip(unsigned int ip);
	static bool netconnected();
	static void encryptedbuffer(CBuffer*buff, char*key);
	static bool comparematch(char*string, char*wild);
	static unsigned int adler32(CBuffer*buff);
	static HANDLE BinOpen(char*filename, int mode);
	static bool BinClose(HANDLE hwnd);
	static int BinWrite(HANDLE hwnd, CBuffer*in);
	static int BinRead(HANDLE hwnd, int size, CBuffer*out);
	static int BinGetPos(HANDLE hwnd);
	static int BinSetPos(HANDLE hwnd, int offset);
	static int BinFileSize(HANDLE hwnd);

};
