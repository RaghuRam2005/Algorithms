#include <iostream>
#include <stack>

int main(){
    std::stack<int> stack;
    std::stack<int> stack2;
    /*push is used to insert element at top of stack*/
    stack.push(2);
    stack.push(9);
    stack.push(3);
    stack.emplace(4);/*This also adds the element to the top of the stack*/
    int n = 3;
        stack.push(n);
    /*pop is used to remove element from the top of the stack*/
    stack.pop();
        stack.pop();
    std::cout<<"The size of stack is: "<<stack.size()<<std::endl;//size will return the size of the stack
    stack2.push(3);
    stack2.push(4);
    stack2.push(5);
    stack2.swap(stack);/*This swaps the stack with stack 2*/
    /*The below code will print the original stack2 which is swapped as stack*/
    std::cout<<"stack:"<<std::endl;
    while(!stack.empty()){/*empty checks if the stack is empty or not*/
        std::cout<<stack.top()<<" ";/*top return the first element without removing it*/
        stack.pop();
    }
    std::cout<<std::endl;
    std::cout<<"stack2:"<<std::endl;
    while(!stack2.empty()){
        std::cout<<stack2.top()<<" ";
        stack2.pop();
    }
}
