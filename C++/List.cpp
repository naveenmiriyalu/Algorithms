#ifndef  __LIST__H_NAVEEN__
#define  __LIST__H_NAVEEN__
#include<iostream>
#include<stdio.h>
template<typename Object>
class List {
   
   private:
    struct Node {
	  Object data;
	  Node *next;
	  Node *prev;
	  Node(const Object& d = Object(),Node *p = NULL,Node *q=NULL):data(d),prev(p),next(q){}
	};
   	int theSize;
	Node *head;
	Node *tail;

	void init(){
	   theSize = 0;
	   head = new Node;
	   tail = new Node;
	   head->next = tail;
	   tail->prev = head;
	}

	public:
	class const_iterator{
	 protected:
	   Node *current;
	   const_iterator(Node *p):current(p) {} 
	   friend class List<Object>;
       Object& retrieve(){
	     return current->data;
	   }

	 public:
	   //Default constructor
	   const_iterator():current(NULL){}
	   //Operator overloading
	   const Object & operator*() {
	      return current->data;
	   }
	   //Prefix operator overload
	   const_iterator operator++(){
	     current = current->next;
		 return *this;
	   }
	   //Postfix operator overload
	   const_iterator operator++(int){
	     const_iterator old = *this;
		 ++(*this);
		 return old;
	   }
	   //== operator overload
	   bool operator==(const const_iterator & rhs) const{
	     return current == rhs.current;
	   }
	   //!= operator overload
	   bool operator!=(const const_iterator & rhs) const{
	     return !(*this == rhs);
	   }

	};

	class iterator:public const_iterator{
	   protected: 
	    iterator(Node* p):const_iterator(p) {
	   }
	    friend class List<Object>;
	   public:
	    iterator() {}

		Object& operator*(){
		   return const_iterator::retrieve();
		}
	   //Prefix operator overload
	   iterator operator++(){
	     const_iterator::operator++;
		 return *this;
	   }
	   //Postfix operator overload
	   iterator operator++(int){
	     iterator old = *this;
		 ++(*this);
		 return old;
	   }

	};

	public:
	//List Public functions
	List(){
	 init();
	}

	bool isEmpty() const {
	  return theSize == 0;
	}

	const_iterator begin() const{
	  return const_iterator(head->next);
	}
	const_iterator end() const{
	  return const_iterator(tail);
	}
	iterator begin(){
	  return iterator(head->next);
	}
	iterator end(){
	  return iterator(tail);
	}

	iterator push_back(const Object& x){
	   insert(begin(),x);
	}

	Object& front(){
	  return *begin(); 
	}
	const Object& front() const{
	  return *begin(); 
	}

    iterator  insert(iterator itr,const Object& x){
	  Node *p = itr.current;
	  Node *newNode = new Node(x,p->prev,p);
	  p->prev->next = newNode;
	  p->prev = newNode;
	  return iterator(newNode);
	}

	class reverse_iterator {
	  private:
	  Node *current;
      public:
	  reverse_iterator ():current(NULL){}
	}


};
#endif

//Main Function

//Print List


int main()
{
   List<int> L1;	
     L1.push_back(10);
     L1.push_back(20);
     L1.push_back(30);
	std::cout << "PRINTING LIST" << std::endl;
	for(List<int>::const_iterator iter = L1.begin();iter != L1.end(); iter++)
	   std::cout << *iter << std::endl;
	std::cout << " FRONT OF THE LIST = " << L1.front() << std::endl;
}
