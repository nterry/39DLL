#pragma once
#include "includes.h"
class CList
{
	void**items;
	int buffsize;
public:
	int count;
	CList(int buffsize);
	CList();
	~CList();
	int Add(void*item);
	void Remove(void*item);
	void Remove(int index);
	void Clear();
	void* operator[](int index);
	void* item(int index);
	void* find(void*item);
	void set(int pos, void*item);
};
