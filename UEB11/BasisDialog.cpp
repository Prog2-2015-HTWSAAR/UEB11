#include "BasisDialog.h"
const int BasisDialog::STD_ANSWER_VALUE = -1;
const int BasisDialog::ZERO_VALUE = 0;
const int BasisDialog::INPUT_ONE = 1;
const int BasisDialog::HIGH_VALUE = 1000;
const string BasisDialog::SEPERATOR = "-------------------------------";
const string BasisDialog::OPTION_DIALOG = "(1) Dialogtest";
const string BasisDialog::OPTION_AUTO_TEST = "(2) AutoTest";
const string BasisDialog::OPTION_EXIT = "(0) EXIT";
const string BasisDialog::STANDARD_CHOICE_PHRASE = "Waehlen sie eine Option : ";

BasisDialog::BasisDialog()
{
}
void BasisDialog::runBasisDialog(){
	int answer = -1;
	AutoTest autoT;
	ProjektDialog projektDialog;
	do {
		cout << SEPERATOR << endl << OPTION_DIALOG << endl << OPTION_AUTO_TEST << endl << OPTION_EXIT << endl << SEPERATOR  << endl << STANDARD_CHOICE_PHRASE;
		answer = readIntegerInput();
		switch (answer){
		case DIALOG:
			projektDialog.startTestDialog();
			break;
		case AUTOTEST:
			autoT.automaticTest();
			break;
		case EXIT:
			break;
		}
	} while (answer != 0);

}


int BasisDialog::readIntegerInput(){
	double number = readDoubleInput();
	if (!(fmod(number, INPUT_ONE) == ZERO_VALUE)){
		number = STD_ANSWER_VALUE;
	}
	return (int)number;
}
double BasisDialog::readDoubleInput(){
	double number;
	if (cin >> number){
	}
	else {
		number = STD_ANSWER_VALUE;
	}
	clearInput();
	return number;
}

void BasisDialog::clearInput(){
	cin.clear();
	cin.ignore(HIGH_VALUE, '\n');
}
