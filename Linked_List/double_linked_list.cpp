/*This is code for creating a double linked list*/
#include <iostream>

/*Code for a node*/
struct Node{
    int data;
    struct Node * previous;
    struct Node * next;
};

/*Code to create a node*/
Node * createnode(int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->previous = nullptr;
    return newNode;
}

/*Code to insert a node*/
class insertnode{
    public:
        /*Code to insert Node at beginning of the linked list*/
        void insertnodeatfirst(Node *& head, int data){
            Node * newNode = createnode(data);
            if(head == nullptr){
                head = newNode;
            }
            else{
                newNode->next = head;
                head->previous = newNode;
                head = newNode;
            }
        }
        /*Code to insert Node at the end of the linked list*/
        void insertnodeatlast(Node *& head, int data){
            Node * newNode = createnode(data);
            if(head == nullptr){
                head = newNode;
            }
            else{
                Node * temp = head;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                newNode->previous = temp;
                temp->next = newNode;
            }
        }
        /*Code to insert node at a specified index*/
        void insertnodeatposition(Node *& head, int data, int position){
            Node * newNode = createnode(data);
            Node * temp = head;
            for(int i=0;i<position-1;i++){
                temp = temp->next;
            }
            if(temp->next==nullptr){
                newNode->previous = temp;
                temp->next = newNode;
            }
            else{
                newNode->previous = temp;
                temp->next->previous = newNode;
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }
};

class deletenode{
    public:
        /*Code to delete node from the beginning of the linked list*/
        void deletenodeatfirst(Node *& head){
            if(head==nullptr){
                std::cout<<"There is no Node"<<std::endl;
            }
            else{
                Node * temp = head;
                head = head->next;
                head->previous=nullptr;
                delete temp;
            }
        }
        /*Code to delete node from the tail of the linked list*/
        void deletenodeatlast(Node *& head){
            if(head==nullptr){
                std::cout<<"There is no Node"<<std::endl;
            }
            else{
                Node * temp = head;
                Node * temp1 = nullptr;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                temp->previous->next = nullptr;
                delete temp;
            }
        }
        /*Code to delete node at the specified index*/
        void deletenodeatposition(Node *& head, int position){
             if (head == nullptr || position < 0) {
                std::cout << "Error: No node at given position" << std::endl;
            }
            Node *temp = head;
            for (int i = 0; temp != nullptr && i < position; i++) {
                temp = temp->next;
            }
            if (temp == nullptr) {
                std::cout << "Error: No node at given position" << std::endl;
            }
            if (temp == head) {
                head = temp->next;
            }
            if (temp->next != nullptr) {
                temp->next->previous = temp->previous;
            }
            if (temp->previous != nullptr) {
                temp->previous->next = temp->next;
            }
            delete temp;
        }
};

/*Code to print the entire linked list*/
void printlist(Node * head){
    Node * temp = head;
    while(temp!=nullptr){
        std::cout<<temp->data<<"->";
        temp = temp->next;
    }
    std::cout<<"nullptr"<<std::endl;
}

int main(){
    Node *head = nullptr;
    /*This is just an example to check if the code is correctly working*/
    insertnode myobj;
    myobj.insertnodeatfirst(head, 1);
    myobj.insertnodeatfirst(head, 2);
    myobj.insertnodeatlast(head, 3);
    myobj.insertnodeatposition(head, 4, 2);
    deletenode myobj1;
    myobj1.deletenodeatfirst(head);
    myobj1.deletenodeatlast(head);
    myobj1.deletenodeatposition(head, 1);
    printlist(head);
    Node * current = head;
    /*deleting the entire linked list from the memory*/
    /*This code is just optional*/
    while (current!=nullptr){
        Node * next = current->next;
        delete current;
        current = next;
    }
    return 0;
    return 0;
}

