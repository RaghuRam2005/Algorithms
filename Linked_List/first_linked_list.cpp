/*The code is for creating a single linked list*/
#include <iostream>

/*Code for a node*/
struct Node{
    int data;
    struct Node * next;
};

/*Code to create a new node*/
Node *  createnode(int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

class insernode{
    public:
        /*Code to insert node at the beginning of the linked list*/
        void insertnodeatfirst(Node *& head, int data){
            Node * newNode = createnode(data);
            if (head == nullptr){
                head = newNode;
            }
            else{
                newNode->next = head;
                head = newNode;
            }
            std::cout <<newNode->data << "inserted" << std::endl;
        }
        /*Code to insert node at the end of the linked list*/
        void insertnodeatlast(Node *& head, int data){
            Node * newNode = createnode(data);
            if (head == nullptr){
                head = newNode;
            }
            else{
                Node * temp = head;
                while(temp->next!=nullptr){
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        /*Code to insert node at any valid position in the linked list*/
        void insertatposition(Node *& head, int data, int position){
            Node * newNode = createnode(data);
            Node * temp = head;
            for(int i=1; i<=position; i++){
                temp = temp->next;
            }
            if(temp->next==nullptr){
                temp->next=newNode;
            }
            else{
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
                std::cout<<"There are no nodes"<<std::endl;
            }
            else{
                Node * temp = head;
                Node * current = nullptr;
                current = temp->next;
                head = current;
                delete temp;
            }
        }
        /*Code to delete node from the end of the linked list*/
        void deletenodeatlast(Node *& head){
            if(head==nullptr){
                std::cout<<"There are no nodes"<<std::endl;
            }
            else{
                Node * temp = head;
                Node * current = nullptr;
                while(temp->next!=nullptr){
                    current = temp;
                    temp = temp->next;
                }
                current->next = nullptr;
                delete temp;
            }
        }
        /*Code to delete node from any valid position of the linked list*/
        void deletenodeatposition(Node *& head, int position){
            if(head==nullptr){
                std::cout<<"There are no nodes"<<std::endl;
            }
            else{
                Node * temp = head;
                Node * current = nullptr;
                for(int i=0;i<position;i++){
                    current = temp;
                    temp = temp->next;  
                }
                current ->next = temp->next;
                delete temp;
            }
        }
};

/*printing the node values of the linked list*/
void printlist(Node *head){
    Node * temp = head;
    while (temp != nullptr){
        std::cout<<temp->data<<"->";
        temp = temp->next;
    }
    std::cout<<"nullptr"<<std::endl;
}

int main(){
    Node * head = nullptr;
    /*This is just an example to check the code*/
    insernode myobj;
    myobj.insertnodeatfirst(head, 8);
    myobj.insertnodeatfirst(head, 7);
    myobj.insertnodeatlast(head, 6);
    myobj.insertnodeatlast(head, 5);
    myobj.insertatposition(head, 10, 2);
    myobj.insertatposition(head, 14, 1);
    deletenode myobj1;
    myobj1.deletenodeatfirst(head);
    myobj1.deletenodeatlast(head);
    myobj1.deletenodeatposition(head, 2);
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
}