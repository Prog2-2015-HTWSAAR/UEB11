/**
 * compile: g++ -c -Wall -pedantic *.cpp
 * compile: g++ -o ueb11 *.o
 * @file Basisdialog.h
 * @date 13.07.2015
 * @author Simon Bastian & Andreas Schreiner
 */
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
	/**
	* @brief runBasisDialog
	* @details basis dialog
	*/
	void runBasisDialog();
	/**
	* @brief readIntegerInput
	* @details fkt zum lesen eines integers
	*/
	int readIntegerInput();
	/**
	* @brief readDoubleInput
	* @details fkt zum lesen eines double
	*/
	double readDoubleInput();
	/**
	* @brief readStringInput
	* @details fkt zum leeren der eingabe
	*/
	void clearInput();
	/**
	* @brief BasisDialog
	* @details Konstruktor
	*/
	BasisDialog();
};
#endif
