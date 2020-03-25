
#ifndef _NODE
#define _NODE
template < class T>
class Node
{
private :
T item; // A data item
Node<T>* next; // Pointer to next node
public :
Node();
Node( const T& anItem);
Node( const T& anItem, Node<T>* nextNodePtr);
void setItem( const T& anItem);
void setNext(Node<T>* nextNodePtr);
T getItem() const ;
Node<T>* getNext() const ;
}; // end Node


template < class T>
Node<T>::Node() : next( nullptr )
{
} 

template < class T>
Node<T>::Node( const T& anItem) : item(anItem), next( nullptr )
{
} 

template < class T>
Node<T>::Node( const T& anItem, Node<T>* nextNodePtr) :item(anItem), next(nextNodePtr)
{
}
template < class T>
void Node<T>::setItem( const T& anItem)
{
	item = anItem;
} 

template < class T>
void Node<T>::setNext(Node<T>* nextNodePtr)
{
	next = nextNodePtr;
} 

template < class T>
T Node<T>::getItem() const
{
	return item;
} 

template < class T>
Node<T>* Node<T>::getNext() const
{
	return next;
} 

#endif