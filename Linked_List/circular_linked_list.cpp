#include <iostream>

struct Node{
    int data;
    struct Node * next;
};

/*Code to create a node*/
Node * createnode(int data){
    Node * newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

class insertnode{
    public:
        /*Code to insert node at beginning of the linked list*/
        void insertnodeatfirst(Node *& head, int data){
            Node * newNode = createnode(data);
            if(head==nullptr){
                head = newNode;
                newNode->next = head;
            }
            else{
                Node * temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                temp->next = newNode;
                newNode->next = head;
                head = newNode;
            }
        }
        /*Code to insert node at the end of the linked list*/
        void insertnodeatlast(Node *& head, int data){
            Node *  newNode = createnode(data);
            if(head==nullptr){
                head=newNode;
                newNode->next = head;
            }
            else{
                Node * temp = head;
                while(temp->next != head){
                    temp = temp->next;
                }
                newNode->next = head;
                temp->next = newNode;
            }
        }
        /*Code to insert node at given position*/
        void insertnodeatposition(Node*& head, int data, int position){
            if (position <= 0) {
                std::cout << "Error: Invalid position. Position should be greater than 0.\n";
                return;
            }
            if (position == 1 || head == nullptr) { 
                insertnodeatfirst(head, data); 
                return;
            }
            Node * newNode = createnode(data);
            Node* current = head;
            int count = 1;
            while (count < position - 1 && current->next != head) {
                current = current->next;
                count++;
            }
            if (current->next == head && count < position - 1) {
                std::cout << "Position is greater than the number of nodes. Inserting at the end.\n";
                insertnodeatlast(head, data); 
                return;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
};

class deletenode{
    public:
        /*Code to delete node at the beginning of linked list*/
        void deletenodeatfirst(Node *& head){
            if(head==nullptr){
                std::cout<<"There are no nodes to delete"<<std::endl;
                return;
            }
            if(head->next==head){
                delete head;
                head = nullptr;
                return;
            }
            else{
                Node * temp = head;
                while(temp->next!=head){
                    temp = temp->next;
                }
                Node * todelete = head;
                head = head->next;
                temp->next = head;
                delete todelete;
                return;
            }
        }
        /*Code to delete node at the end of linked list*/
        void deletenodeatlast(Node *& head){
            if(head==nullptr){
                std::cout<<"There are no nodes to delete"<<std::endl;
                return;
            }
            if(head->next==head){
                delete head;
                head = nullptr;
                return;
            }
            else{
                Node * temp = head;
                Node * temp1 = nullptr;
                while(temp->next!=head){
                    temp1 = temp;
                    temp = temp->next;
                }
                temp1->next = head;
                delete temp;
            }
        }
        /*code to delete node at given position*/
        void deletenodeatposition(Node *& head, int position){
            if(head==nullptr||position<=0){
                std::cout<<"There are no nodes to delete"<<std::endl;
            }
            if(position==1){
                deletenodeatfirst(head);
                return;
            }
            Node * temp = head;
            Node * previous = nullptr;
            int count = 1;
            while (count < position && temp->next != head) {
                previous = temp;
                temp = temp->next;
                count++;
            }
            if (temp->next == head && count < position) { 
                std::cout << "Error: No node at the given position.\n";
                return;
            }
            previous->next = temp->next;
            delete temp;
        }
};

/*Code to print all the nodes in the linked list*/
void printList(Node* head) {
    if (head == nullptr) {
        std::cout << "The list is empty.\n";
        return;
    }
    Node* current = head;
    do {
        std::cout << current->data << "->";
        current = current->next;
    } while (current != head);
    std::cout << "(head)\n"; 
}

int main(){
    Node * head = nullptr;
    /*This is just an example to check if the code is running*/
    insertnode myobj;
    myobj.insertnodeatfirst(head, 1);
    myobj.insertnodeatfirst(head, 12);
    myobj.insertnodeatposition(head, 13, 1);
    myobj.insertnodeatfirst(head, 2);
    myobj.insertnodeatlast(head, 4);
    myobj.insertnodeatposition(head, 6, 2);
    printList(head);
    deletenode myobj1;
    myobj1.deletenodeatfirst(head);
    myobj1.deletenodeatlast(head);
    myobj1.deletenodeatposition(head, 2);
    printList(head);
    return 0;
}
