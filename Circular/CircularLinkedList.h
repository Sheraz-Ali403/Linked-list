#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *next = nullptr;
};

template <typename T>
class CircularLinkedList {
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

    void deleteAll() noexcept {
        if(!head) return;
        tail->next = nullptr; 
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }

public:
    CircularLinkedList() { }
    ~CircularLinkedList() { deleteAll() }

    void pushBack(T data){
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        if(!head) {
            newNode = head = tail;
            head->next = head;
            tail->next = head;
        }else {
            tail->next= newNode;
            tail = newNode;
            tail->next = head;
        }
    }
    void pushFront(T data){
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        if(!head) {
            newNode = head = tail;
            head->next = head;
            tail->next = head;
        } else {
            newNode->next = head;
            head = newNode;
            tail->next = head;
        }
    }
    void pushAt(T data, int pos){
        if(pos<0 || pos>size()) {
            throw std::out_of_range("Insert position is outside the list");
        }
        if(pos==0){
            pushFront(data);
            return;
        }
        if(pos==size()){
            pushBack(data);
            return;
        }
        if(!head) throw std::out_of_range("Cannot insert into an empty list at a non-zero position");
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;

        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        for(int i=0; i<pos; i++){
            prev = temp;
            temp = temp->next;
        }
        newNode->next = temp;
        prev->next = newNode;
    }

    void popBack(){
        if(!head){
            throw std::out_of_range("Cannot remove from an empty list");
        }
        if(head==tail){
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *temp = head;
            while(temp->next != tail){
                temp = temp->next;
            }
           tail = temp;
           delete tail->next;
           tail->next = head;
        }
    }
    void popFront(){
        if(!head) {
            throw std::out_of_range("Cannot remove from an empty list")
        }
        if(head==tail){
            delete head;
            head = tail = nullptr;
        } else {
            Node<T> *temp = head;
            head = head->next;
            delete temp;
            tail->next = head;
        }
    }
    void popData(T data){
        if(!head){
            throw std::out_of_range("Cannot remove from an empty list")
        }
        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        while(temp!=nullptr && temp->data!=data){
            prev = temp;
            temp= temp->next;
        }
        if(temp==nullptr){
            throw std::out_of_range("Data not found in the list");
        }
        if(temp==head){
            popFront();
        } else if(temp==tail){
            popBack();
        } else {
            prev->next = temp->next;
            delete temp;
        }  
    }
    

    // display 
    void display() const {
        if(!head) {
            throw std::out_of_range("Cannot display an empty list");
        }
        Node<T> *temp = head;
        while(temp->next!=head){
            cout << "Data :" << temp->data << endl;
            temp = temp->next;
        }
    }
    
};

