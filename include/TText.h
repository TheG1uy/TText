#pragma once
#define _CRT_SECURE_NO_WARNINGS  
#include <string>
#include "stack.h"
#include <fstream> 
using namespace std;
class TLink {
private: char str[80];
		 TLink *pNext, *pDown;
public: 
	TLink(char *s = nullptr, TLink *pn = nullptr, TLink *pd = nullptr) {
		pNext = pn;
		pDown = pd;
		if (!s) str[0] = '\0';
		else strcpy_s(str,s);
	}
	void setPNext(TLink *pn) { pNext = pn; }
	void setPDown(TLink *pd) { pDown = pd; }
	TLink* getPDown() { return pDown; }
	TLink* getPNext() { return pNext; }
	char* getStr() { return str; }
	friend std::ostream& operator<<(std::ostream &os,TLink &tl) {
		os << tl.str;
		return os;
	}
};

class TText {
private:
	int level;
	TLink *pFirst, *pCurr;
	TStack<TLink*> stack, delstack;
public:
	TText(TLink *_pFirst=nullptr) {
		if (!_pFirst) _pFirst = new TLink();
		pCurr=pFirst = _pFirst;
	}
	void reset() { pCurr = pFirst; }
	void goNextLink();
	void goPrevLink();
	void goDownLink();
	void addNextLine(char *);
	void addNextSection(char *);
	void delNextLink();
	void delDownLink();
	char* getLine();
	void setLine(char* tmp);
	TLink* recursionRead(ifstream& file);
	void Read(char *fn);
	void printText(TLink* tmp);
	void print();
	void saveText(TLink* tmp, ofstream& f);
	void save(char* fn);
	TLink* CopyRecursion(TLink *tmp);
	TLink* Copy();
	void Reset();
	bool IsEnd();
	void GoNext();
};