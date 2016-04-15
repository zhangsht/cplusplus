#include<iostream>
#include <vector>
using namespace std; 
//template<typename E>
//
//class Stack
//
//{
//
//private:
//
//  vector<E> elements;
//
// 
//
//public:
//
//         // push element into the stack
//
//         void push(E element);
//
//         // pop an element from the stack
//
//         void pop();
//
//         // peek an element from the stack, and you should not pop it
//
//         E peek();
//
//};
template<typename E>
void Stack<E>::push(E element) {
	elements.push_back(element);
}

// pop an element from the stack
template<typename E>
void Stack<E>::pop() {
	if (!elements.empty())
	elements.pop_back();
}

// peek an element from the stack, and you should not pop it
template<typename E>
E Stack<E>::peek() {
	return elements.back();
}

//int main() {
//	Stack<int> s;
//	for (int i  = 0; i < 5; i++) {
//		s.push(i);
//		cout << s.peek() << ' ';
//	}
//	cout << "\n"; 
//	for (int i  = 0; i < 4; i++) {
//		s.pop();
//		cout << s.peek() << ' ';
//	}
//}
