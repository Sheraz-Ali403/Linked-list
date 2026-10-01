#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next = nullptr;
};

template <typename T>
class SinglyLinkedList {
    Node<T> *head = nullptr;

    void deleteAll() noexcept {
        while (head != nullptr) {
            CorrectedNode<T>* temp = head;
            head = head->next;
            delete node;
        }
    }
public:
    SinglyLinkedList() { }
    ~SinglyLinkedList() { deleteAll() }
    
    // add at end
    void pushBack(T data){
        Node<T> *newNode =  new Node;
        newNode->data = data;
        newNode->next = nullptr;

        if(!head)  head = newNode;
        else {
            Node<T> *temp = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // add at front/begin
    void pushFront(T data){
        Node<T> *newNode =  new Node;
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    // rm last one
    void popBack(){

        if(head==nullptr) {
            throw std::out_of_range("Cannot remove from an empty list");
        }
        
        if(head->next==nullptr){
            delete head;
            head = nullptr;
            return;
        }
        Node<T> *temp, pre;
        temp=head;
        while(temp->next!=nullptr){
            pre = temp;
            temp = temp->next;
        }
        pre->next = nullptr;
        delete temp;
        
    }

    //rm first one
    void popFront(){
        if(head==nullptr) {
            throw std::out_of_range("Cannot remove from an empty list");
        }
        Node<T> *temp;
        temp = head;
        head = temp->next;
 
        delete temp;
    }

    //Insert at any position
    void insert(T data, int pos){
        if (position == 0) {
            pushFront(data);
            return;
        }
    
        Node<T>* pre, temp;
        temp = head;

        for(int i=0; i<pos; i++){
            if(temp==nullptr) {
                throw std::out_of_range("Insert position is outside the list");
            }
            pre = temp;
            temp = temp->next;
        }

        Node<T>* newNode = new Node;
        newNode->data = data;
        newNode->next = temp;

        pre->next = newNode;
    }

    // remove at any position
    void remove(T data, int pos){
        if(head==nullptr) {
            throw std::out_of_range("Cannot remove from an empty list");
        }
        if (position == 0) {
            popFront();
            return;
        }
        Node<T>* pre, temp;
        temp = head;

        for(int i=0; i<pos; i++){
            if(temp==nullptr) {
                throw std::out_of_range("Cannot remove from an empty list");
            }
            pre = temp;
            temp = temp->next;
        }
        pre->next = temp->next;

        delete temp;
    }

    // display 
    void display(){
        if(head==nullptr) {
            throw std::out_of_range("Cannot display an empty list");
        }
        Node<T> *temp = head;
        while(temp->next!=nullptr){
            cout << "Data :" << temp->data << endl;
        }
    }

};