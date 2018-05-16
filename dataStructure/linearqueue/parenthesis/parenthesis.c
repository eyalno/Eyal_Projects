#include <stdio.h>
#include "stack.h"
#include <string.h>

int checkParenthesis(char *_str){

Stack* stack=stackCreate(8,8);

int length=strlen(_str);
int i;
int ptr=0;

	for(i=0;i<length;i++){
		if (_str[i] == '{' ||_str[i] == '[' || _str[i] == '('){
			stackPush(stack,_str[i]);
			continue;
		}
		if (_str[i] == '}' ||_str[i] == ']' || _str[i] == ')'){
			stackPop(stack,&ptr);
			
			if(ptr != _str[i]-2 && ptr != _str[i]-1){
				return i;
			}
		}
	}

	return stackIsEmpty(stack)? -1:i;

}

