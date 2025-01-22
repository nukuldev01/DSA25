// DELETION IN LINKED LIST 
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }

    Node(int data1){
        data = data1;
        next = nullptr;
    }
};

Node* ConvertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void print(Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* removehead(Node* head){
    if(head == NULL) return head;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node * removeTail(Node* head){
    if(head == NULL || head->next == NULL) return NULL;
    Node* temp = head;
    
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;
    return head;

}

Node* removeK(Node* head, int k){
    if(head == NULL) return head;
    if(k == 1){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node* removeEl(Node* head, int el){
    if(head == NULL) return head;
    if(head->data == el){
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    
    Node* temp = head;
    Node* prev = NULL;

    while(temp != NULL){
        
        if(temp->data == el){
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> arr = {32,5,8,7,9};
    Node* head = ConvertArr2LL(arr);

    // head = removehead(head);
    // head = removeTail(head);
    // head = removeK(head, 5);
    head = removeEl(head, 11);
    print(head);    

    return 0;
}