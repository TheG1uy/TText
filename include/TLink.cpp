#pragma once
#include "TText.h"
#include <cstring>
void* TLink::operator new(size_t s) {
	TLink *tmp = mem.pFree;
	if (mem.pFree != NULL) mem.pFree = mem.pFree->pNext;
	return tmp;
}
void TLink::operator delete(void* p) {
	TLink *tmp = (TLink*)p;
	tmp->pNext = mem.pFree;
	mem.pFree = tmp;
	
}
void TLink::InitMem(size_t s) {
	mem.pFirst = (TLink*) new char[sizeof(TLink)*s];
	mem.pFree = mem.pFirst;
	mem.pLast = mem.pFirst + (s - 1);
	TLink *tmp = mem.pFree;
	for (int i = 0; i < s - 1; i++) {
		tmp->pNext = tmp + 1;
		tmp++;
	}
	mem.pLast->pNext = NULL;
}
void TLink::MemClean(TText &txt) {
	for (txt.Reset(); !txt.IsEnd(); txt.GoNext())
		strcat(txt.getCurr()->str,"*");
	TLink *tmp = mem.pFree;
	while (tmp != NULL) {
		strcpy(tmp->str, "*");
		tmp = tmp->pNext;
	}
	tmp = mem.pFirst;
	while (tmp != mem.pLast) {
		if (strstr(tmp->str, "*") == NULL)
			tmp->str[strlen(tmp->str) - 1] = '\0';
		tmp++;
	}
}