#include <string.h>
#include "Common_Function.h"

/*
 * fileOpen 
 */
int fileOpen(exercise_info* exer, FILE** pptr)
{
	if (exer->file_name == NULL) {
		printf("[Info] No need to open input file!\n");
		return SUCCESS;
	}

	printf("Opening file %s\n", exer->file_name);
	*pptr = fopen(exer->file_name, "r");

	if (*pptr != NULL) {
		printf("[Info] Opening file success!\n");
		return SUCCESS;
	} else {
		printf("[ERR] Opening file fail!\n");
		return FAIL;
	}
}

int IsOverflow(int val) {
	int ret = INVALID;

	if (INT_MIN <= val <= INT_MAX)
		ret = VALID;

	return ret;
}

/*******************************************************************************************************************************************************
	/* Is_Digits
		@Description:
			Check if s is 0~9 char
		@return:
			TRUE  : yes
			FALSE : no
*******************************************************************************************************************************************************/
int Is_Digits(int s) {
	if (s >= '0' && s <= '9')
		return TRUE;
	else
		return FALSE;
}

/*******************************************************************************************************************************************************
	/* Is_Letters
		@Description:
			Check if s is letter or not.
		@return:
			TRUE  : yes
			FALSE : no
*******************************************************************************************************************************************************/
int Is_Letters(int s) {
	if ((s >= 'A' && s <= 'Z') || (s >= 'a' && s <= 'z'))
		return TRUE;
	else
		return FALSE;
}

/*******************************************************************************************************************************************************
	/* Is_WhiteSpace
		@Description:
			Check if s is letter or not.
		@return:
			TRUE  : yes
			FALSE : no
*******************************************************************************************************************************************************/
int Is_WhiteSpace(int s) {
	if(s == SPACE)
		return TRUE;
	else
		return FALSE;
}


/******************************************************************/
/*     Input     */
/******************************************************************/

int User_Array_Input(int* s) {
	printf("Plz Enter the length of an array\n");
	int data;
	int length;
	scanf("%d", &length);
	if (length < 0 || length > INT_MAX)
		return FALSE;

	int i = length;
	while (i > 0) {
		printf("Plz enter a num\n");
		scanf("%d", &data);
		if (INT_MAX >= data >= INT_MIN) {
			*s = data;
			s++;
			i--;
		}
		else {
			printf("The num you enter is invalid.\n");
			return -1;
		}
	}

	return length;
}

/*******************************************************************************************************************************************************
	/* getline
		@Description:
			Get each line from a txt.
		@return:
			Length of cur line.
*******************************************************************************************************************************************************/
int getline_from_txt(FILE** pptr, char* input)
{
	int idx = 0;
	int c;

	if (*pptr == NULL) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "[%s] NULL Pointer!\n", __FUNCTION__);
		return;
	}

	memset(input, 0, sizeof(sizeof(input[0]) * LINE_MAX_LENGTH));
	while ((c = fgetc(*pptr)) != EOF && c != '\n')
		input[idx++] = c;

	input[idx] = '\0';

	return idx;
}


/*******************************************************************************************************************************************************
	/* getline_from_txt_v1
		@Description:
			* Get each line from a txt
			* Can determine whether to incldue new line ('\n') or not.
		@return:
			Length of cur line.
*******************************************************************************************************************************************************/
int getline_from_txt_v1(FILE* ptr, char* input, const int of_mode)
{
	if (ptr == NULL) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "[%s] NULL Pointer!\n", __FUNCTION__);
		return;
	}
	int c;
	int idx = 0;
	memset(input, 0, sizeof(sizeof(input[0]) * LINE_MAX_LENGTH));
	while ((c = fgetc(ptr)) != EOF)
	{
		if (c == '\n') {
			if (of_mode & _CAP_INCLUDE_NEWLINE) {
				input[idx++] = c;
			}
			break;
		}
		input[idx++] = c;
	}
	input[idx] = '\0';
	return idx;
}

/*******************************************************************************************************************************************************
	/* getchar
		@Description:
			Get each char from a txt.
		@return:
			OK or Fail
*******************************************************************************************************************************************************/
int getchar_from_txt(FILE** pptr, char* ch)
{
	int ret = FALSE;
	int c;

	if (*pptr == NULL) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "[%s] NULL Pointer!\n", __FUNCTION__);
		return;
	}

	//if ((c = fgetc(*pptr)) != EOF && c != '\n')
	if ((c = fgetc(*pptr)) != EOF)
	{
		*ch = c;
		ret = TRUE;
	}

	return ret;
}

/*******************************************************************************************************************************************************
	/* getword_from_txt
		@Description:
			Get a word from text with skipping some special char and comments
		@return:
			Current char c gets from fgetc
*******************************************************************************************************************************************************/
int getword_from_txt(FILE** pptr, char* word)
{
	if (*pptr == NULL) {
		C_PRINTF(CUR_LEVEL, C_ERROR, "[%s] NULL Pointer!\n", __FUNCTION__);
		return;
	}
	int c, i;
	memset(word, 0, sizeof(sizeof(word[0]) * LINE_MAX_LENGTH));

	while (Is_WhiteSpace(c = fgetc(*pptr)))
		;
	if (c != EOF)
		*word++ = c;

	if ((Is_Digits(c) || Is_Letters(c)) || c == '_' || c == '#') {
		for (i = 0; i < IDX_MAX_LENGTH; i++) {
			c = fgetc(*pptr);
			if ((Is_Digits(c) || Is_Letters(c)) || c == '_')
				*word++ = c;
			else
				break;
		}
	} else if (c == '\'') {
		while ((c = fgetc(*pptr)) != '\'')
			;
	} 
	 else if (c == '\"') {
		while ((c = fgetc(*pptr)) != '\"')
			;
	} else if (c == '/' && (c = fgetc(*pptr)) == '*') {
		while ((c = fgetc(*pptr)) != EOF) {
			if (c == '*' && (c = fgetc(*pptr)) == '/')
				break;
		}
	}

	*word++ = '\0';
	return c;
}


/******************************************************************/
/*     Show     */
/******************************************************************/

void printf_array(char* array)
{
	int len = 0;
	while (*array != '\0')
	{
		printf("%c", *array);
		array++;
		len++;
	}
	printf("\n");
}

void Show_int_array(int s[], int n)
{
	if (n < 0) return;
	int i = n;
	printf("[");
	for (i = 0; i < n; i++) {
		printf("%d ", s[i]);
	}
	printf("]\n");
}

/*******************************************************************************************************************************************************
	/* str_reverse
		@Description:
			Reverse a string.
*******************************************************************************************************************************************************/
void str_reverse(char s[])
{
	int c, i, j;
	j = strlen(s) - 1;
	if (INT_MIN <= j <= INT_MAX) {
		for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
			c = s[i];
			s[i] = s[j];
			s[j] = c;
		}
	}
}

/*******************************************************************************************************************************************************
	/* str_Cmp
		@Description:
			Compare whether the s1, s2 string is same or not.
		@return:
			0 : not the same
			1 : same
*******************************************************************************************************************************************************/
int str_Cmp(char* s, char* t) {
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}


/*******************************************************************************************************************************************************
	/* swap
		@Description:
			Change the char between a,b;
*******************************************************************************************************************************************************/
void str_swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

/*******************************************************************************************************************************************************
	/* IsWhiteSpace
		@Description:
			Check whether it is white space or not.
		@return:
			TRUE :     " "
			FALSE: not " "
*******************************************************************************************************************************************************/
int str_IsWhiteSpace(char* s, int idx) {
	if (s[idx] == SPACE)
		return TRUE;
	else
		return FALSE;
}

/*******************************************************************************************************************************************************
	/* GetSign
		@Description:
			Check the sign of char is positive or negative.
		@return:
			POSITIVE : +
			NEGATIVE : -
*******************************************************************************************************************************************************/
int str_GetSign(char* s, int idx) {
	if (s[idx] == '+')
		return POSITIVE_PLUS;
	else if (s[idx] == ' ')
		return POSITIVE_EMPTY;
	else if (s[idx] == '-')
		return NEGATIVE;
	else
		return INVALID;
}


/*******************************************************************************************************************************************************
	/* str_Cat
		@Description:
			connect t to s
		@return:
*******************************************************************************************************************************************************/
void str_Cat(char* s, char* t) {
	while (*s != '\0') {
		s++;
	}
	while ((*s = *t) != '\0') {
		s++;
		t++;
	}
}


/*******************************************************************************************************************************************************
	/* str_EndCompare
		@Description:
			compare whether t exists in the end of s.
		@return:
			1 : yes
			0 : no
*******************************************************************************************************************************************************/
int str_EndCompare(char* s, char* t) {
	int s_len = strlen(s);
	int t_len = strlen(t);
	int ret = FALSE;
	if (s_len < t_len)
		return ret;
	s += (s_len - t_len);

	if (0 == str_Cmp(s, t))
	{
		ret = TRUE;
	}
	return ret;
}

/*******************************************************************************************************************************************************
	/* str_ncpy
		@Description:
			copy length of t to s.
		@return:
			1 : yes
			0 : no
*******************************************************************************************************************************************************/
void str_ncpy(char* s, char* t, int n) {
	while (n>0) {
		if (*s != '\0') {
			*t = *s;
			t++;
			s++;
		}
		n--;
	}
}


/*******************************************************************************************************************************************************
	/* str_nCat
		@Description:
			copy t to the end of s.
		@return:
			1 : yes
			0 : no
*******************************************************************************************************************************************************/
void str_nCat(char* s, char* t, int n) {
	while (*s != '\0') {
		s++;
	}

	int i = 0;
	while (i < n) {
		if ((*s = *t) != '\0') {
			s++;
			t++;
		}
		i++;
	}
}



/*******************************************************************************************************************************************************
	/* str_nCmp
		@Description:
			Compare whether the first n elements in s, t string is same or not.
		@return:
			0 : not the same
			1 : same
*******************************************************************************************************************************************************/
int str_nCmp(char* s, char* t, int n) {
	int ret = TRUE;
	int i = 0;

	while ((i < n) && *s!='\0' && *t!='\0') {
		if (*s != *t) {
			ret = FALSE;
			break;
		}
		s++;
		t++;
		i++;
	}
	return ret;
}

/*******************************************************************************************************************************************************
	/* IsDigits
		@Description:
			Check whether the char is '0'~'9'.
		@return:
			TRUE : yes
			FALSE : not 0~9
*******************************************************************************************************************************************************/
int str_IsDigits(char* s, int i) {
	if (s[i] >= '0' && s[i] <= '9')
		return TRUE;
	else
		return FALSE;
}

/*******************************************************************************************************************************************************
	/* GetLineLength
		@Description:
			Get the string length
		@return:
			string length
*******************************************************************************************************************************************************/
int GetLineLength(char* pArray)
{
	return strlen(pArray);
}

/*******************************************************************************************************************************************************
	/* str_swap_element
		@Description:
			Swap two elements in a array
*******************************************************************************************************************************************************/
void str_swap_element(char* s, int i, int j) {
	printf("swap [%c, %c]\n", s[i], s[j]);
	char* tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}


/*******************************************************************************************************************************************************
	/* Decimal2Binary
		@Description:
			Change Decimal value to binary string
		@return:
			A string that represents the binary of a decimal val.
*******************************************************************************************************************************************************/
char* Decimal2Binary(int decimal)
{
	char binary[256];
	int idx = 0;
	if (decimal < 0)
		printf("Decimal must be a positive num\n");
	do {
		if ((decimal % 2) == 0)
			binary[idx] = '0';
		else
			binary[idx] = '1';
		decimal = decimal / 2;
		idx++;
	} while (decimal != 0);
	binary[idx] = '\0';

	return binary;
}

/*******************************************************************************************************************************************************
	/* Stack
		@Description:
			The followings are the implementation about stack using C programming.

*******************************************************************************************************************************************************/
void Stack_push(int data) {
	if ((data > INT_MAX || data < INT_MIN) &&
		data != EOF)
		return;
	if (Stack_idx < IDX_MAX_LENGTH)
		Stack[++Stack_idx] = data;
	else
		C_PRINTF(CUR_LEVEL, C_WARNING, "[%s] Stack Full!!!\n", __FUNCTION__);
}

int Stack_pop(void) {
	if (Stack_idx != -1) {
		int tmp = Stack[Stack_idx];
		Stack_idx--;
		return tmp;
	}
	else {
		printf("\n");
		C_PRINTF(CUR_LEVEL, C_WARNING, "[%s] Stack Empty!!!\n", __FUNCTION__);
		return INVALID;
	}
}

int Stack_top(void) {
	if (Stack_idx >= 0) {
		int ret = Stack[Stack_idx];
		Stack_idx--;
		return ret;
	}
	else {
		C_PRINTF(CUR_LEVEL, C_ERROR, "[%s] Stack is empty\n", __FUNCTION__);
		return INVALID;
	}
}

void Stack_print(void) {
	int i = 0;
	printf("---------------------\n");
	printf("|");
	for (; i <= Stack_idx; i++) {
		printf("%d ", Stack[i]);
	}
	printf("\n");
	printf("---------------------\n");
}

void Stack_show_top(void) {
	if (Stack_idx >= 0) {
		printf("Stack top = %d\n", Stack[Stack_idx]);
	}
	else {
		printf("Stack is empty\n");
	}
	return;
}

void Stack_init(void) {
	memset(Stack, 0, sizeof(sizeof(Stack[0]) * IDX_MAX_LENGTH));
	Stack_idx = -1;
	printf("Stack init!\n");
	return;
}

void Stack_duplicate(void) {
	int a = Stack_pop();
	Stack_push(a);
	Stack_push(a);
	printf("Duplicate complete!\n");
	return;
}

void Stack_clear(void) {
	memset(Stack, 0, sizeof(sizeof(Stack[0]) * IDX_MAX_LENGTH));
	Stack_idx = -1;
	printf("Stack clear!\n");
	return;
}

int Stack_isEmpty(void) {
	return (Stack_idx >= 0) ? FALSE : TRUE;
}

int Stack_getLength(void) {
	return (Stack_idx >= 0) ? (Stack_idx + 1) : 0;
}

void Stack_swap_top_two_ele(void) {
	if (Stack_idx >= 1) {
		int a = Stack_pop();
		int b = Stack_pop();
		Stack_push(a);
		Stack_push(b);
	}
	else //stack is too small
	{
		printf("Stack swap the top two ele fail!\n");
	}
	return;
}


/*******************************************************************************************************************************************************
	/* Char_IsDigits
		@Description:
			Check if the char is between 0~9
		@return:
			FALSE : not 0~9
			TRUE  :		0~9 
*******************************************************************************************************************************************************/
int Char_IsDigits(char* c) {
	int ret = FALSE;
	//printf("[common]%c\n", *c);
	if ((*c >= '0') && (*c <= '9'))
		ret = TRUE;
	return ret;
}

/*******************************************************************************************************************************************************
	/* Char_IsWhiteSpace
		@Description:
			Check if the char is white space
		@return:
			FALSE : not a whitespace
			TRUE  : it's a whitespace
*******************************************************************************************************************************************************/
int Char_IsWhiteSpace(char* c) {
	int ret = FALSE;
	if (c == SPACE)
		ret = TRUE;
	return ret;
}

int atoi_pointer_ver(char* s) {
	int n;
	int sign;
	int sum = 0;

	n = strlen(s);
	int i = 0;
	while (*s != '\0') {
		if (Char_IsWhiteSpace(*s)) {
			s++;
			continue;
		}
		if (*s == '+' || *s == '-') {
			sign = (*s == '-') ? -1 : 1;
			s++;
			continue;
		}

		if (Char_IsDigits(*s)) {
			sum = sum * 10 + ((*s) - '0');
		}
		s++;
	}
	return sum;
}

void itoa_pointer_ver(int x, char* s){
	//tmp is used to record the start address of s, otherwise, str_reverse(s) will send the end address of s to str_reverse
	//and will reverser nothing!!!!!!!!!!!
	char* tmp = s;
	
	/*
	    You cannot read null pointer!!
		char* si = "";
		*si = 0;
	*/
	int sign;
	sign = x;

	do{
		*s = abs(x % 10) + '0';
		s++;
	} while (x /= 10);

	if (sign < 0) {
		*s = '-';
		s++;
	}
	*s = '\0';
	str_reverse(tmp);
}

void str_reverse_pointer_ver(char* s) {
	Stack_init();
	const len = strlen(s);
	while (*s != '\0') {
		Stack_push((*s - '0'));
		s++;
	}
	s -= len;
	int i = 0;
	int tmp;
	while (i<len) {
		tmp = Stack_pop();
		*s = tmp + '0';
		s++;
		i++;
	}
}

int str_find_index(char* s, char* tar) {
	int ret = -1;
	int i = 0;

	for (; (*s!='\0'); i++, s++) {
		printf("[%c, %c]\n", *s, tar);
		if ((*s) == tar) {
			ret = i;
			break;
		}
	}
	return ret;

}


void int_swap(int* s, int i, int j) {
	void* tmp;
	tmp = s[i];
	s[i] = s[j];
	s[j] = tmp;
}


void swap_array_char(char* v, int i, int j)
{
	/* Exchange two pointers */
	void* temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}