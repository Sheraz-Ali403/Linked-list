#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node<T> *pre = nullptr;
    Node<T> *next = nullptr;
};

template <typename T>
class DoublyLinkedList {
    Node<T> *head = nullptr;
    Node<T> *tail = nullptr;

    void deleteAll() noexcept {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }
public:
    DoublyLinkedList() { }
    ~DoublyLinkedList() { deleteAll() }

    
    void displayForward() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << "Data: " << temp->data << endl;
            temp = temp->next;
        }
    }
    void displayBackward() const {
        Node<T>* temp = tail;
        while (temp != nullptr) {
            cout << "Data: " << temp->data << endl;
            temp = temp->pre;
        }
    }
    
    void pushBack(T data){
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->pre = nullptr;
        if(!head) {
            newNode = head = tail;
            head->pre = nullptr;
            tail->next = nullptr;
        }else {
            tail->next= newNode;
            newNode->pre = tail;
            tail = newNode;
        }
    }
    void pushFront(T data){
        Node<T> *newNode = new Node<T>;
        newNode->data = data;
        newNode->next = nullptr;
        newNode->pre = nullptr;
        if(!head) {
            newNode = head = tail;
            head->pre = nullptr;
            tail->next = nullptr;
        } else {
            head->pre newNode;
            newNode->next = head;
            head = newNode;
        }
    }
    void pushAt(T data, int pos){
        if(pos<0 || pos>size()) {
            cout << "Invalid Position\n";
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
        newNode->pre = nullptr;

        Node<T> *temp = head;
        Node<T> *prev = nullptr;
        for(int i=0; i<pos; i++){
            prev = temp;
            temp = temp->next;
        }
        prev->next = newNode;
        newNode->pre = prev;
        newNode->next = temp;
        temp->pre = newNode;
    }
    void popBack(){
        if(!head){
            throw std::out_of_range("Cannot remove from an empty list");
        }
        if(head==tail){
            delete head;
            head = tail = nullptr;
        } else {
            tail = tail->pre;
            delete tail->next;
            tail->next = nullptr;
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
            head = head->next;
            delete head->pre;
            head->pre = nullptr;
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
            temp->next->pre = prev;
            delete temp;
        }  
    }
    void reverse(){
        if(!head || !tail) {
            throw std::out_of_range("Cannot reverse an empty list");
        }
        Node<T> *temp = head;
        Node<T> *pre = nullptr;
        while(temp!=nullptr){
            pre=temp->pre;
            temp->pre = temp->next;
            temp->next = pre;
            temp=temp->pre;
        }
        head= pre->pre;
    }

    // display 
    void display() const {
        if(!head) {
            throw std::out_of_range("Cannot display an empty list");
        }
        Node<T> *temp = head;
        while(temp!=nullptr){
            cout << "Data :" << temp->data << endl;
            temp = temp->next;
        }
    }
    
};

