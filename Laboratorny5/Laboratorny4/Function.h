#pragma once
#include "Operator.h"
#include <iostream>
#include <stdio.h>
#include "sqlite3.h"
#include "MainForm.h"




void replace(List<Customer^>^& vect, int first_index, int second_index);
void bubbleSort(List<Customer^>^& line);

//int callback(void* NotUsed, int argc, char** argv, char** azColName);

static int selectData(const char* s);