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
private: char str[80];
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
}; 