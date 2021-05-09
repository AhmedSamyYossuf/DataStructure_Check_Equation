#include <iostream>
#include <stdio.h>
//#include <cstring>
using namespace std;


#define Max_Stack   30

template <class Stact_type>
class Stack
{
    private :
             int Top = -1 ;
             Stact_type  My_Stack[Max_Stack];
             int size_of_Eqution;

    public  :
             void Push_Element(Stact_type);
             void Push_String(Stact_type String[]);
             Stact_type Pop();
             void Mack_Empty();
             bool is_Empty();
             bool is_Full();
             void Cheack_Equation(Stact_type String[]);
};


int main()
{
    Stack<char> stack_A;

    char Element , String[Max_Stack] , test[1] ;
    int  choice , number_of_Element ;
    while(choice != 7)
    {
        cout << "\n1. to PUSH one Character\n2. to POP Character\n3. to PUSH String\n" ;
        cout << "4. to POP Number of Element\n5. to Mack Empty\n6. to Checked Brackets Of Equation\n7. to EXIT\nEnter your Choice : ";
        cin >> choice;
        cout << "\n\n";
        if(choice == 1)
        {
            cout << "Please enter one Element : ";
            cin >> Element;
            stack_A.Push_Element(Element);
        }
        else if (choice == 2)
        {
            char temp;
            temp = stack_A.Pop();
            if(temp != '\0')
            {
                cout << "Value = " << temp << endl;
            }
        }
        else if (choice == 3)
        {
            gets(String);
            cout << "Please enter your String with Max Element "<<Max_Stack <<" : ";
            //cin >> String;
            gets(String);
            stack_A.Push_String(String);
        }
        else if (choice == 4)
        {
            char temp;
            cout << "Please enter number of Element you want to POP it : ";
            cin >> number_of_Element;
            for (int i = 0 ; i < number_of_Element ; i++)
            {
               temp = stack_A.Pop();
               if(temp != '\0')
               {
                    cout << "Value = " << temp << endl;
               }
            }
        }
        else if (choice == 5)
        {
            stack_A.Mack_Empty();
        }
        else if (choice == 6)
        {
            gets(test);
            cout << "please enter equation that you want to check its brackets : ";
            gets(String);
            stack_A.Cheack_Equation(String);
        }
        else
        {
            if (choice == 7){}
            else
            {
                cout << " wrong choice Please try again\n\n";
            }
        }
    }
    cout << "\n\nGoodbye\n\n";
    return 0;
}


template <class Stact_type>
void Stack<Stact_type>::Mack_Empty()
{
    Top = -1 ;
}

template <class Stact_type>
bool Stack<Stact_type>::is_Empty()
{
    return (Top == -1);
}

template <class Stact_type>
bool Stack<Stact_type>::is_Full()
{
    return (Top == (Max_Stack -1));
}

template <class Stact_type>
void Stack<Stact_type>::Push_Element(Stact_type element)
{
    if (is_Full())
    {
        cout << "Stack is Full \n";
    }
    else
    {
        Top++;
        My_Stack[Top] = element;
    }
}

template <class Stact_type>
void Stack<Stact_type>::Push_String(Stact_type String[])
{
    int i = 0;
    while(String[i] != '\0')
    {
        Push_Element(String[i]);
        i++;
    }
    size_of_Eqution = (i+1);
}

template <class Stact_type>
void Stack<Stact_type>::Cheack_Equation(Stact_type String[])
{
    int counter=0,numOfCurly=0,numOfSquare=0,numOfBrackets=0;
    Stact_type temp ;
    Push_String(String);
    for (int i = 0 ; i < String[i] != '\0'; i++)
    {
       temp = Pop();
       if (temp != '\0')
       {
           if (temp == '{')     { numOfCurly++    ; }
           else if (temp == '}'){ numOfCurly--    ; }
           else if (temp == '['){ numOfSquare++   ; }
           else if (temp == ']'){ numOfSquare--   ; }
           else if (temp == '('){ numOfBrackets++ ; }
           else if (temp == ')'){ numOfBrackets-- ; }
           if (numOfCurly == 1){cout << "\nOpen Curly Brackets without Closed it at element of number "<<(size_of_Eqution-(i+1))<<"\n"         ; return; }
           else if(numOfSquare == 1 ){cout << "\nOpen Square Brackets without Closed it at element of number "<<(size_of_Eqution-(i+1))<<"\n"  ; return; }
           else if(numOfBrackets == 1) {cout << "\nOpen Brackets without Closed it at element of number "<<(size_of_Eqution-(i+1))<<"\n"       ; return; }

       }
    }
    if (numOfCurly == 0 && numOfSquare == 0 && numOfBrackets == 0)
    {
        cout << "your Equation is correct" ;
    }
    else
    {
        if(numOfCurly    < 0){cout << "\nnumber of Open Curly Brackets \'{\' < number of Close Curly Brackets \'}\' \n"   ; }
        if(numOfSquare   < 0){cout << "\nnumber of Open Square Brackets \'[\' < number of Close Square Brackets \']\' \n" ; }
        if(numOfBrackets < 0){cout << "\nnumber of Open Brackets \'(\' < number of Close Brackets \')\' \n"               ; }
    }
}

template <class Stact_type>
Stact_type Stack<Stact_type>::Pop()
{
    if (is_Empty())
    {
        cout << "Stack is Empty \n";
        return '\0';
    }
    else
    {
       Stact_type temp =  My_Stack[Top];
       Top--;
       return temp;
    }
}

