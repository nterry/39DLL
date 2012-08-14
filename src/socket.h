#pragma once
#include "includes.h"
#include "buffer.h"

class CSocket
{
	bool udp;
	int format;
	char formatstr[30];
	static SOCKADDR_IN SenderAddr;
	int receivetext(char*buf, int max);
public:

	SOCKET sockid;
	CSocket(SOCKET sock);
	CSocket();
	~CSocket();
	bool tcpconnect(char*address, int port, int mode);
	bool tcplisten(int port, int max, int mode);
	CSocket* tcpaccept(int mode);
	char* tcpip();
	void setnagle(bool enabled);
	bool tcpconnected();
	int setsync(int mode);
	bool udpconnect(int port, int mode);
	int sendmessage(char*ip, int port, CBuffer* source);
	int receivemessage(int len, CBuffer*destination);
	int peekmessage(int size, CBuffer*destination);
	int lasterror();
	static char* GetIp(char*address);
	static int SockExit(void);
	static int SockStart(void);
	static char* lastinIP(void);
	static unsigned short lastinPort(void);
	static char* myhost();
	int SetFormat(int mode, char* sep);
};
