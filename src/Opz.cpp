#include "Opz.h"
#include "Stack.h"

using namespace std;

//if the character is a digit
bool Opz::isDigit(char c) {
    return (c>='0' && c<='9');
}

//the priopity of the operation
int Opz::priorOp(char c) {
    switch(c) {
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        default: return 0;
    }
}

char Opz::nextChar() {
    if(indInpStr < inputStr.length()) {
		return current = inputStr[indInpStr++];
    }
    else return current = '\0';
}

//полученная строка
string Opz::getOutputStr(){
	return outputStr;
}

//преобразование в ОПЗ
void Opz::convert(string str) {
    int op = 0, np = 0;    //флаги, показывающие наличие операторов и скобок

     indInpStr= 0;
    Stack<char> opStack;    //стек
    inputStr = str;
	outputStr.erase();

    if((!isDigit(inputStr[0])) && inputStr[0]!='(')
        cout<<"Ошибка: неправильно записано выражение!\n";

    while (nextChar() != '\0') {
       if(isDigit(current)) {
		   outputStr += current;
		   op = 0;
		   continue;
	   }
	   else outputStr += ' ';

       switch (current) {
           case '(':
			   opStack.push(current);
			   ++np;
			   op = 0;
			   break;
           case '*': case '/': case '+': case '-':
               if(indInpStr == inputStr.length())
			       cout<<"Ошибка: оператор не может стоять в конце!\n";

               if(!op) {
			       op = 1;
                   while(priorOp(current) <= priorOp(opStack.top())) {
			           outputStr += opStack.pop();
				   }
                   if(priorOp(current) > priorOp(opStack.top())){
				       opStack.push(current);
				   }
			       break;
			   }
               else cout<<"Ошибка приоритета операции!\n";

           case ')':
               if(op)
			       cout<<"Ошибка: неверно поставлена скобка!\n";
               else
			       while((current= opStack.pop())!= '(' && np>0) {
				       outputStr += current;
				   }
			   np--;
			   break;
           default: {
               cout<<"Error: неопознанный символ\n";
	       }
	   }
	}
    while(opStack.top() != -1)
	    outputStr += opStack.pop();
    if(np)
	    cout<<"Error: неравное кол-во скобок!\n";
}

int Opz::calculate(string str) {

    Stack<int> valStack; //стек
    int num1, num2, result =0;
    string num;

    for(int i = 0; i<str.length(); ++i) {
            if(outputStr[i] == ' ') continue;
        while(isDigit(outputStr[i]) && i<str.length()) {
      //    valStack.push(outputStr[i] - '0');
            num += outputStr[i++];
        }
        if(!num.empty()){
             valStack.push(atoi(num.c_str()));
        num.erase();
        if(i>=outputStr.length())
            break;

        if(outputStr[i] == ' ') continue;
        }
            num2 = valStack.pop();
            num1 = valStack.pop();
            switch(outputStr[i]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
                default: cout<<"Ошибка !\n";
            }
        valStack.push(result);
        }
    return valStack.pop();
}

