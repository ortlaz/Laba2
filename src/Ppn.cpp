#include "Ppn.h"
#include "List.h"

using namespace std;

//if the character is a digit
bool Ppn::isDigit(char c) {
    return (c>='0' && c<='9');
}

//the priopity of the operation
int Ppn::priorOp(char c) {
    switch(c) {
        case '(': return 1;
        case '+': case '-': return 2;
        case '*': case '/': return 3;
        default: return 0;
    }
}

char Ppn::nextChar() {
    if(indInpStr < inputStr.length()) {
		return current = inputStr[indInpStr++];
    }
    else return current = '\0';
}

//полученная строка
string Ppn::getOutputStr(){
	return outputStr;
}

//преобразование в ОПЗ
void Ppn::convert(string str) {
    int op = 0, np = 0;    //флаги, показывающие наличие операторов и скобок

    indInpStr= 0;
    List <char> opStack;    //стек
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
                        outputStr += opStack.top();
                        if(opStack.top() != -1)
                        opStack.pop();
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
			       while(opStack.top() != '(' && np>0) {
                        current = opStack.top();
                        opStack.pop();
                        outputStr += current;
                    }
			   --np;
			   opStack.pop();
			   break;
           default: {
               cout<<"Error: неопознанный символ\n";
	       }
	   }
	}
    while(opStack.top() != -1){
	    outputStr += opStack.top();
	    opStack.pop();
    }
    if(np)
	    cout<<"Error: неравное кол-во скобок!\n";
}

int Ppn::calculate(string str) {

    List<int> valStack; //стек
    int num1, num2, result;

    for(int i = 0; i<str.length(); ++i) {
        if(isDigit(outputStr[i])) {
            valStack.push(outputStr[i] - '0');
        }
        else {
            if(outputStr[i] == ' '){
                continue;
            }
            num2 = valStack.top();
            valStack.pop();
            num1 = valStack.top();
            valStack.pop();

            switch(outputStr[i]) {
                case '+': result = num1 + num2; break;
                case '-': result = num1 - num2; break;
                case '*': result = num1 * num2; break;
                case '/': result = num1 / num2; break;
                default: cout<<"Ошибка !\n";
        }
        valStack.push(result);
        }
    }
    return valStack.top();
}

