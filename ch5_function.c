#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../Common_function.h"
#include "ch5_function.h"

int OPTION;

int EX5_1_main(char* input, int* val)
{
	int sign = POSITIVE;
	int sum = 0;
	int c, i;

	printf("Start getting int from char...\n");
	for (i = 0; input[i] != '\0'; i++) {
		c = input[i];

		if (Is_WhiteSpace(c))
			continue;
		
		if (c == '+' || c == '-') {
			sign = (c == '-') ? NEGATIVE : POSITIVE;
			continue;
		}

		if (!Is_Digits(c))
			return -EINVCHARIN;

		sum = sum * 10 + (c - '0');
	}

	if (sign == NEGATIVE)
		sum *= -1;

	*val = sum;

	return 0;
}

int EX5_2_main(char* s, double* f)
{
	int has_fraction = FALSE;
	int fraction_idx = 1;
	int sign = POSITIVE;
	double sum = 0;
	double frac;
	int i, c;
	int ret;

	printf("Start getting float from char...\n");
	for (i = 0; s[i] != '\0'; i++) {
		c = s[i];

		if (Is_WhiteSpace(c))
			continue;

		if (c == '+' || c == '-') {
			sign = (c == '-') ? NEGATIVE : POSITIVE;
			continue;
		}
		if (c == '.') {
			has_fraction = TRUE;
			continue;
		}

		if (!Is_Digits(c))
			return -EINVCHARIN;

		if (!has_fraction)
			sum = sum * 10 + (c - '0');
		else {
			frac = pow(10, fraction_idx++);
			sum = sum + ((c - '0') / frac);
		}
	}

	if (sign == NEGATIVE)
		sum *= -1;

	*f = sum;

	return 0;
}

void EX5_3_main(char* s, char* t)
{
	str_cat(s, t);
	return;
}

int Text_readlines_EX_5_7(FILE** pptr, char** lineptr, char* ls, int* linelen) {
	int nlines, len;
	char* p_ls;
	char tmp[LINE_MAX_LENGTH];
	nlines = 0;
	int i = 0;
	//find the first empty place in ls
	p_ls = ls + strlen(ls);
	while ((len = getline_from_txt(pptr, tmp)) > 0) {
		if (nlines > LINE_MAX_LENGTH || (strlen(ls) + len) > LINE_MAX_LENGTH) {
			C_PRINTF(CUR_LEVEL, C_ERROR, "Too much lines!!\n", __FUNCTION__);
			return;
		}
		else{
			//copy input line to ls by strcpy(pointer)
			strcpy(p_ls, tmp);
			lineptr[nlines++] = p_ls;
			linelen[i++] = len;
			p_ls += len;
		}
	}
	*p_ls = '\0';
	return nlines;
}

void writelines_EX_5_7(char** lineptr, int nlines, int* linelen) {
	int i = 0;
	int j = 0;
	while (nlines--) {
		int idx = linelen[i++];
		j = 0;
		for (; j < idx; j++) {
			printf("%c", *((*lineptr)+j));
		}
		lineptr++;
		printf("\n");
	}
}


int Day_of_year_EX5_8(int year, int month, int day) {
	if (year == 0 || month < 1 || month>12 || day < 1 || day>365) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "Invalid Input!!\n", __FUNCTION__);
		return FALSE;
	}
	int leap = 0;
	if ((year % 4) == 0 && (year % 100) == 0 || (year % 400) == 0) {
		leap = 1;
	}
	for (int i = 1; i < month; i++) {
		day += DAY_TABLE[leap][i];
	}
	return day;
}

void Month_day_EX5_8(int y_day, int year, int* p_month, int* p_day) {
	int leap = 0;
	if ((year % 4) == 0 && (year % 100) == 0 || (year % 400) == 0) {
		leap = 1;
	}
	int i = 1;
	for (; y_day > DAY_TABLE[leap][i]; i++) {
		y_day -= DAY_TABLE[leap][i];
	}
	*p_month = i;
	*p_day = y_day;
}



int Day_of_year_EX5_9(int year, int month, int day) {
	if (year == 0 || month < 1 || month>12 || day < 1 || day>365) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "Invalid Input!!\n", __FUNCTION__);
		return FALSE;
	}
	int leap = 0;
	if ((year % 4) == 0 && (year % 100) == 0 || (year % 400) == 0) {
		leap = 1;
	}
	char* p = &DAY_TABLE[leap][1];
	for (int i = 1; i < month; i++) {
		day += *p;
		p++;
	}
	return day;
}

void Month_day_EX5_9(int y_day, int year, int* p_month, int* p_day) {
	int leap = 0;
	if ((year % 4) == 0 && (year % 100) == 0 || (year % 400) == 0) {
		leap = 1;
	}
	char* p = &DAY_TABLE[leap][1];
	int i = 1;
	for (; y_day > DAY_TABLE[leap][i]; i++) {
		y_day -= *p;
		p++;
	}
	*p_month = i;
	*p_day = y_day;
}


int EX5_10(int argc, char* argv[]) {
	Stack_init();
	while (--argc >= 1) {
		char c = *(++argv)[0];
		if (Is_Digits(&c)) {
			Stack_push(c - '0');
		}
		switch(c) {
			case '+' :
			{
				Stack_push((Stack_pop() + Stack_pop()));
				break;
			}
			case '*' :
			{
				Stack_push((Stack_pop() * Stack_pop()));
				break;
			}
			case '-' :
			{
				int tmp = Stack_pop();
				int tmp1 = Stack_pop();
				Stack_push(tmp1 - tmp);
				break;
			}
			case '/':
			{
				int tmp = Stack_pop();
				int tmp1 = Stack_pop();
				Stack_push(tmp1/tmp);
				break;
			}
			default:
				break;
		}

	}
	int ret;
	if (ret = Stack_pop()) {
		return ret;
	}
	else {
		C_PRINTF(CUR_LEVEL, C_ERROR, "Invalid ret!!\n", __FUNCTION__);
		return FALSE;
	}
}


int EX5_13_readlines(FILE** pptr, char** lineptr, char* line, int* linelen) {
	/*
		- lineptr	: Store the start pointer in linestore for each input line
		- line :	  Store all the text input line in an char array
						applebananaorange!!!
						^    ^     ^
		- linelen   : Store the length of each input line
	*/
	char tmp[LINE_MAX_LENGTH];
	int len = 0;
	int i = 0;
	char* p_line;
	p_line = line + strlen(line);
	int line_num = 0;
	while ((len = getline_from_txt(pptr, tmp)) > 0) {
		if (line_num > LINE_MAX_LENGTH || (strlen(line) + len) > LINE_MAX_LENGTH) {
			C_PRINTF(CUR_LEVEL, C_ERROR, "Too much lines!!\n", __FUNCTION__);
			return;
		}
		else {
			strcpy(p_line, tmp);
			lineptr[line_num] = p_line;
			linelen[line_num] = len;
			p_line += len;
			line_num++;
		}
	}
	*p_line = '\0';
	return line_num;
}

void EX_5_13_writelines(char** lineptr, int nlines, int* linelen, int argc, char** argv) {
	if (argc <= 1) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "No argument input!!\n", __FUNCTION__);
	}
	int c;
	int line_idx;
	while (--argc > 0 && (*++argv)[0] == '-') {
		c = (*argv)[1];
		switch (c) {
			case 'n':
			{
				if ((*++argv) != NULL) {
					line_idx = (*argv)[0] - '0';
					argc--;
				}
				else {
					C_PRINTF(CUR_LEVEL, C_ERROR, "Invalid argument input!!\n", __FUNCTION__);
				}
				break;
			}
			default: {
				C_PRINTF(CUR_LEVEL, C_ERROR, "Invalid argument input!!\n", __FUNCTION__);
				return;
			}
		}
	}

	printf("[-n] = [%d]\n", line_idx);
	int i = 0;
	int j = 0;
	while (i < (nlines - line_idx)) {
		i++;
		lineptr++;
	}
	while (i<nlines) {
		int idx = linelen[i++];
		j = 0;
		for (; j < idx; j++) {
			printf("%c", *((*lineptr) + j));
		}
		lineptr++;
		printf("\n");
	}
}



void EX_5_14_Quick_Sort(int* s, int low, int high) {
	if (low >= high) {
		return;
	}
	printf("------------------------------\n");
	printf("pivot = %d\n", s[high]);
	int i = low;
	for (int j = low; j < high; j++) {
		if (s[j] <= s[high]) {
			int_swap(s, i, j);
			i++;
		}
	}
	int_swap(s, i, high);
	printf("------------------------------\n");
	EX_5_14_Quick_Sort(s, low, i - 1);
	EX_5_14_Quick_Sort(s, i+1, high);
}

int EX5_14_Check_valid(char* s) {
	if (!Is_Letters(s))
		return FALSE;
	if (!(s == SPACE))
		return FALSE;
	if (!Is_Digits(s))
		return FALSE;
	return TRUE;
}

int Check_swap(char* s, int j, int high) {
	char s_j = s[j];
	char s_high = s[high];

	if (OPTION & _BIT_DIRECTORY_ORDER_) {
		if (!EX5_14_Check_valid(s_j)) {
			C_PRINTF(CUR_LEVEL, C_ERROR, "Input Invalid!!\n", __FUNCTION__);
			return FALSE;
		}
		if (!EX5_14_Check_valid(s_high)) {
			C_PRINTF(CUR_LEVEL, C_ERROR, "Input Invalid!!\n", __FUNCTION__);
			return FALSE;
		}
	}
	
	if (OPTION & _BIT_FOLD_) {
		s_j = tolower(s_j);
		s_high = tolower(s_high);
	}

	if (OPTION & _BIT_REVERSE_)
		return (s_j >= s_high) ? TRUE : FALSE;
	else
		return (s_j <= s_high) ? TRUE : FALSE;
}

void EX_5_14_QuickSort_char(char* s, int low, int high) {
	if (low >= high) {
		return;
	}
	int i = low;
	for (int j = low; j < high; j++) {
		if (Check_swap(s, j, high)) {
			swap_array_char(s, i, j);
			i++;
		}
	}
	swap_array_char(s, i, high);
	EX_5_14_QuickSort_char(s, low, i - 1);
	EX_5_14_QuickSort_char(s, i + 1, high);
}

void EX_5_14_QuickSort_Main(char* s, int low, int high, int argc, char** argv) {
	int c;
	while ((--argc > 0) && (*++argv)[0] == '-') {
		c = (*argv)[1];
		switch (c) {
			case 'r':
			{
				C_PRINTF(CUR_LEVEL, C_INFO, "QT Reverse Enabled!!\n", __FUNCTION__);
				OPTION |= _BIT_REVERSE_;
				break;
			}
			case 'f':
			{
				C_PRINTF(CUR_LEVEL, C_INFO, "QT Fold Enabled!!\n", __FUNCTION__);
				OPTION |= _BIT_FOLD_;
				break;
			}
			case 'd':
			{
				C_PRINTF(CUR_LEVEL, C_INFO, "QT Directory order Enabled!!\n", __FUNCTION__);
				OPTION |= _BIT_DIRECTORY_ORDER_;
				break;
			}
			default:
			{
				break;
			}
		}
	}
	EX_5_14_QuickSort_char(s, low, high);

	return;
}