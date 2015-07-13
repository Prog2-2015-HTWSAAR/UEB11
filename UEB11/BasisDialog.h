#ifndef BASISDIALOG_H_
#define BASISDIALOG_H_
#include "AutoTest.h"
#include "ProjektDialog.h"
#include <math.h>

class BasisDialog
{
public:
	enum BDialog{ EXIT, DIALOG, AUTOTEST};
	static const int STD_ANSWER_VALUE;
	static const int ZERO_VALUE;
	static const int INPUT_ONE;
	static const int HIGH_VALUE;
	static const string SEPERATOR;
	static const string OPTION_DIALOG;
	static const string OPTION_AUTO_TEST;
	static const string OPTION_EXIT;
	static const string STANDARD_CHOICE_PHRASE;
	void runBasisDialog();
	int readIntegerInput();
	double readDoubleInput();
	void clearInput();
	BasisDialog();
};
#endif
