#include<iostream>

using namespace std;

class Node{
    public:
    int key;
    int data;
    Node* next;

    Node(){
        key=0;
        data=0;
        next=NULL;
    }

    Node(int k, int d){
        key = k;
        data =d;
    }
};

class SingleLinkedList{
    public:
        Node* head;

    SingleLinkedList(){
        head=NULL;
    }

    SingleLinkedList(Node *n){
        head = n;
    }
    
    Node* nodeExist(int k){
        
        Node* exist = NULL;
        Node* ptr = head;

        while(ptr != NULL){
            
            if(ptr -> key==k){
                exist = ptr;
            }
            ptr = ptr -> next; /* swapping address of current pointer to next address */
        }
        return exist;

    }

    void appendNode(Node* n){

        if(nodeExist(n -> key) != NULL){
            cout << "Node already exists with the same key value :"<< n-> key<< endl;
        }
        else{
            /* checks for first node */
            if(head==NULL){
               head = n;
               cout << "Node appended successfully"<< endl;
            }
            else{
                Node* ptr = head;
                while(ptr->next != NULL){
                    ptr = ptr -> next;
                }
                ptr -> next = n;
                cout << "Node appended successfully" << endl;
            }
        }
    }

    void prependNode(Node* n){

        if(nodeExist(n -> key) != NULL){
            cout << "Node already exists with the same key value :"<< n-> key<< endl;
        }
        else{
            n->next = head;
            head = n;
            cout << "Node prepended successfully"<< endl;           
        }

    }

    void insertNodeAfter(int k, Node* n){
        
        Node* ptr = nodeExist(k);
        if(ptr==NULL){
            cout<<"No node exists with key value: "<< k << endl;
        }
        else{
            if(nodeExist(n -> key) != NULL){
                cout << "Node already exists with the same key value :"<< n-> key<< endl;
            }
            else{
                n -> next = ptr -> next;
                ptr -> next = n;
                cout << "Node inserted successfully";
            }
        }
    }

    void deleteNode(int k){

        if(head == NULL){
            cout<<"List is empty. Nothing here to delete !"<< endl;
        }
        else if(head != NULL){
            
            if(head->key==k){
                head = head -> next;
                cout<<"Node Unlinked with key value : "<< k << endl;
            }
            else{
                Node* temp = NULL;
                Node* prevptr = head;
                Node* currentptr = head -> next;
                while(currentptr != NULL){
                    if(currentptr -> key == k){
                        temp = currentptr;
                        currentptr = NULL; /* match found, break loop*/
                    }
                    else{
                        prevptr = prevptr -> next;
                        currentptr = currentptr -> next;

                    }
                }
                if(temp!=NULL){
                    prevptr -> next = temp -> next;
                    cout<<"Node Unlinked with key value : "<< k << endl;
                }
                else{
                    cout<<"Node doesn't exists with key value : "<< k << endl;
                }
            }
        }

    }

    void updateNodeData(int k, int d){
        Node* ptr = nodeExist(k);
        if(ptr==NULL){
            cout<<"No node exists with key value: "<< k << endl;
        }
        else{
            ptr -> data = d;
            cout<<"Node data updated successfully"<< endl;
        }        
    }

    void displayLinkedList(){
        
        if(head == NULL){
            cout<<"List is empty. Nothing here to display !"<< endl;
        }
        else{
            cout<<endl;
            Node* temp = head;

            while(temp != NULL){
                cout<< "( " << temp->key << "," << temp->data << " )";
                if(temp->next != NULL){
                    cout<<" --> ";
                }
                temp = temp->next;
            }
            cout<<endl;
        }
    }

};


int main(){
    SingleLinkedList s;
    int option;
    int key1,k1,data1;

    system("clear");

    do{
        cout << "\n what operations do you want to perform ? (Press 0 to exit)" << endl;
        cout << "1. Append Node" << endl;
        cout << "2. Prepend Node" << endl;
        cout << "3. Insert Node After" << endl;
        cout << "4. Delete Node" << endl;
        cout << "5. Update Node" << endl;
        cout << "6. Display" << endl;
        cout << "7. Clear Screen" << endl;
        cout << "Enter your option : ";
        cin >> option;
        system("clear");
        Node* n1 = new Node(); /*Dynamic memory allocation (uses heap instead of stack)*/

        switch (option)
        {
        case 1:
            cout << "Enter key & data of the node to appened : ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.appendNode(n1);
            s.displayLinkedList();
            break;
        case 2:
            cout << "Enter key & data of the node to prepend : ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.prependNode(n1);
            s.displayLinkedList();
            break;
        case 3:
            cout << "Enter key of the existing node after which you want to insert : ";
            cin >> k1;
            cout << "Enter key & data of the new node : ";
            cin >> key1;
            cin >> data1;
            n1->key = key1;
            n1->data = data1;
            s.insertNodeAfter(k1,n1);
            s.displayLinkedList();
            break;                  
        case 4:
            cout << "Enter key of the node which you want to delete : ";
            cin >> k1;
            s.deleteNode(k1);
            s.displayLinkedList();
            break; 
        case 5:
            cout << "Enter key & data of the node which you want to update : ";
            cin >> k1;
            cin >> data1;
            s.updateNodeData(k1, data1);
            s.displayLinkedList();
            break; 
        case 6:
            s.displayLinkedList();
            break;
        case 7:
            system("clear");
            break;                                                             
        default:
            cout << "Enter a valid number ! ";
            break;
        }

    }while(option!=0);

    return 0;
}
