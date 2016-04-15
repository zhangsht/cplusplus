template<typename E>
void Stack<E>::push(E element) {
	elements.push_back(element);
}

// pop an element from the stack
template<typename E>
void Stack<E>::pop() {
	elements.pop_back();
}

// peek an element from the stack, and you should not pop it
template<typename E>
E Stack<E>::peek() {
	return elements[elements.size() - 1];
}