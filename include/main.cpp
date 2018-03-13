#include "TText.h"
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_CTYPE, "Russian");
	TText txt;
	FILE *f;
	int p;
	f = fopen("text.txt", "r");
	txt.Read("text.txt");
	txt.print();
	fclose(f);
	return 0;
}