#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#include "stack.h"
#include "TText.h"
using namespace std;
class TLink;
class TText;
struct TMem {
	TLink *pFirst, *pLast, *pFree;
};
class TLink {
private: static TMem mem;
	     char str[80];
		 TLink *pNext, *pDown;
		 
public:
	TLink(char *s = nullptr, TLink *pn = nullptr, TLink *pd = nullptr) {
		pNext = pn;
		pDown = pd;
		if (!s) str[0] = '\0';
		else strcpy_s(str, s);
	}
	void setPNext(TLink *pn) { pNext = pn; }
	void setPDown(TLink *pd) { pDown = pd; }
	TLink* getPDown() { return pDown; }
	TLink* getPNext() { return pNext; }
	char* getStr() { return str; }
	friend std::ostream& operator<<(std::ostream &os, TLink &tl) {
		os << tl.str;
		return os;
	}
    void* operator new(size_t s) {
		TLink *tmp = mem.pFree;
		if (!mem.pFree) mem.pFree = mem.pFree ->pNext ;
		return tmp;
	}
	void operator delete(void* p) {
		TLink *tmp = (TLink*)p;
		tmp->pNext = mem.pFree;
		mem.pFree = tmp;
	}
	static void InitMem(size_t s) {
		mem.pFirst = (TLink*) new char[sizeof(TLink)*s];
		mem.pFree = mem.pFirst;
		mem.pLast = mem.pFirst + (s - 1);
		for (int i = 0; i < s - 1; i++) {
			(mem.pFree + i)->pNext = (mem.pFirst+i+1);
		}
		mem.pLast->pNext = NULL;
	}
}; 
