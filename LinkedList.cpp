#include<iostream>
using namespace std;

class LinkedList{

private:
    struct Node
    {
        int value;
        Node *Next = NULL;
    };
    
    
public:
    Node *Head = NULL;
    Node *Tail = NULL;

    void push_back(int val){

        Node *newNode = new Node();
        newNode->value = val;

        if(Head == NULL){
            Head = newNode;
            Tail = newNode;
            newNode = NULL;
        }
        else{
            Tail->Next = newNode;
            Tail = newNode;
        }
        
    }

    void pop_back(){
        
        Node *temp = Head;

        while(temp->Next->Next != NULL){
            temp = temp->Next;
        }

        delete temp->Next->Next;
        temp->Next = NULL;
    }

    void push_front(int val){

        Node *newNode = new Node();
        newNode->value = val;

        if(Head == NULL){
            Head = newNode;
            Tail = newNode;
            newNode = NULL;
        }
        else{
            newNode->Next = Head;
            Head = newNode;
        }
    }

    Node* mergeTwoLists(Node* l1, Node* l2) {
        Node *Head = nullptr;
        Node *Tail = nullptr;

        if(l1->val < l2->val){
            Head = l1;
            Tail = l1;
            l1 = l1->Next;
        }

        else{
            Head = l2;
            Tail = l2;
            l2 = l2->Next;
        }

        while(l1 != nullptr && l2 != nullptr){

            if(l1->val < l2->val){
                Tail->Next = l1;
                Tail = l1;
                l1 = l1->Next;
            }

            else{
                Tail->Next = l2;
                Tail = l2;
                l2 = l2->Next;
            }
        }
        if(l1==nullptr){
            Tail->Next=l2;
        }
        
        else{
            Tail->Next=l1;
        }
        
        return Head;
    }

    void PrintList(){
        Node *temp = Head;

        while(temp!= 0){
            cout << temp->value << endl;
            temp = temp->Next;
        }
    }


};

int main(){

    LinkedList myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    
    // myList.pop_back();
    // myList.PrintList();
    cout << myList.Head->value << endl;
    myList.push_front(5);
    cout << myList.Head->value << endl;

    return 0;
}




