/*
Author: Naveen 
Date:   17th Jan 2015
Descritpion: Stack implementation using templates. Uses the STL implemented vector 
*/
#ifndef __STACK__GENERIC__STL
#define __STACK__GENERIC__STL
#include<vector>

template<typename T>
class Stack
{
  private:
  	std::vector<T> elem;
  public:
  	void push(const T&);
	const T& top() const;
	T pop();
};
//push member function
template<typename T>
void Stack<T>::push(const T& element)
{
  elem.push_back(element);
}
//pop member function
template<typename T>
T Stack<T>::pop()
{
  T ret_element;
    ret_element = elem.back();
	elem.pop_back();
	return ret_element;
}
//top member function
template<typename T>
const T& Stack<T>::top() const
{
  elem.back();
}

#endif
