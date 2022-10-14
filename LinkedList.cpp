#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string _data) : data(_data), next(nullptr) {}
}; 

struct OneLinkedList {
    Node* head, * tail;
    OneLinkedList() : head(nullptr), tail(nullptr) { }

    bool is_empty() {
        return head == nullptr;
    }   

    void addHead(string _data) {
        Node* element = new Node(_data);
        if (is_empty()) {
            head = element;
            tail = element;
            return;
        }
        head->next = element;
        head = element;
    }

    void addTail(string _data) {
        Node* element = new Node(_data);
        if (is_empty()) {
            head = element;
            tail = element;
            return;
        }
        tail->next = element;
        tail = element;
    }

    void Insert(string _data, int id)
    {
        Node* element = new Node(_data);       
        int k = 0;
        for (Node* anime = head; anime; anime = anime->next, k++)
        {
            if (id == 0) {
                element->next = head;
                head = element;
                return;
            }
            if (k == id - 1) {
                element->next = anime->next;
                anime->next = element;
                break;
            }
        }
    }  

    Node* FindData(string _data) {
        Node* element = head; 
        while (element != NULL) {
            if (element->data == _data) return element;
            element = element->next;
        }
        return NULL;
    }

    Node* FindPos(int id) {
        Node* element = head;      
        while (element != NULL && id > 1)
        {
            element = element->next;
            id--;
        }
        return element;
    }

    void Retrieve(int id) {
        int k = 0;
        for (Node* i = head; i; i = i->next, k++)
        {
            if (k == id)
            cout << i->data;
        }
    }

    void RemoveHead() {
        if (is_empty()) return;
        Node* element = head;
        head = element->next;
        delete element;
    }
    
    void RemoveTail() {
        if (is_empty()) return;
        if (head == tail) {
            RemoveHead();
            return;
        }
        Node* element = head;
        while (element->next != tail) element = element->next;
        element->next = nullptr;
        delete tail;
        tail = element;
    }

    void Remove(string _data) {
        if (is_empty()) return;
        if (head->data == _data) {
            RemoveHead();
            return;
        }
        else if (tail->data == _data) {
            RemoveTail();
            return;
        }
        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->data != _data) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast)
        {
            cout << "This element does not exist " << endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }

    void RemoveAllList() {
        while (head)
        {
            Node* element = head->next;
            free(head);
            head = element;
        }
    }

    void MoveNodeInEnd() {
        if (is_empty()) return;
        Node* first = head;
        Node* last = head;
        while (last->next != NULL) {
            last = last->next;
        }
        head = first->next;
        first->next = NULL;
        last->next = first;
    }

    void MoveNodeInFront() {
        if (is_empty()) return;
        Node* secLast = NULL;
        Node* last = head;
        while (last->next != NULL) {
            secLast = last;
            last = last->next;
        }
        secLast->next = NULL;
        last->next = head;
        head = last;
    }
    
    void PrintList() {
        if (is_empty()) return;
        Node* element = head;
        while (element) {
            cout << element->data << " ";
            element = element->next;
        }
        cout << endl;
    }
};

int main()
{
    OneLinkedList linkedlist;
    cout << linkedlist.is_empty() << endl;
    linkedlist.addHead("7");
    linkedlist.addTail("3");
    linkedlist.addTail("123");      
    linkedlist.addTail("8");
    linkedlist.Insert("check", 3);
    linkedlist.PrintList();
    cout << linkedlist.is_empty() << endl;
    /*linkedlist.MoveNodeInFront();
    linkedlist.PrintList();*/
    linkedlist.MoveNodeInEnd();
    linkedlist.PrintList();

    //linkedlist.FindPos(1);
    //linkedlist.FindData("123");
    //linkedlist.Retrieve(3);
    //linkedlist.RemoveAllList();
    //linkedlist.Remove("123");
    //linkedlist.RemoveTail();
    //linkedlist.PrintList();

    return 0;
}
