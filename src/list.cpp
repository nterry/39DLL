#include "list.h"
CList::CList()
{
	items = (void**)malloc(5*sizeof(void*));
	buffsize = 5;
	count = 0;
}

CList::CList(int buffsize)
{
	buffsize = max(buffsize, 1);
	this->buffsize = buffsize;
	items = (void**)malloc(buffsize*sizeof(void*));
	count = 0;
}
CList::~CList()
{
	free(items);
}
int CList::Add(void*item)
{
	if(count >= buffsize)
	{
		buffsize += 5;
		items = (void**)realloc(items, buffsize*sizeof(void**));
	}
	items[count] = item;
	count++;
	return count;
}

void CList::Remove(void*item)
{
	for(int i = 0; i < count; i++)
	{
		if(items[i] == item)
		{
			memmove(items+i, items+i+1, (count-i-1)*sizeof(void**));
			count--;
			break;
		}
	}
}

void CList::Remove(int i)
{
	if(i < 0 || i >= count)return;
	if(count > 1)
	{
		memmove(items+i, items+i+1, (count-i-1)*sizeof(void**));
		count--;
	} else Clear();
}
void CList::set(int pos, void*item)
{
	if(pos < 0 || pos >= count)return;
	items[pos] = item;
}
void CList::Clear()
{
	free(items);
	items = (void**)malloc(5*sizeof(void*));
	buffsize = 5;
	count = 0;
}
void* CList::find(void*item)
{
	for(int i = 0; i < count; i++)
		if(items[i] == item)return items[i];
	return NULL;
}
void* CList::operator [](int i)
{
	if(i < 0 || i >= count)return NULL;
	return items[i];
}

void* CList::item(int i)
{
	if(i < 0 || i >= count)return NULL;
	return items[i];
}
