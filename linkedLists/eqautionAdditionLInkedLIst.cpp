#include <iostream>
using namespace std;

class Node {
public:
    int coeff;
    int pow;
    Node *link;

    Node(int coeff, int pow) {
        this->coeff = coeff;
        this->pow = pow;
        this->link = nullptr;
    }
};

class LinkedList {
private:
    Node *head;

public:
    LinkedList() {
        this->head = nullptr;
    }
    ~LinkedList() {
    Node *current = head;
    while (current != nullptr) {
        Node *next = current->link;
        delete current;
        current = next;
        }
    }

    void addAtEnd(int coeff, int pow) {
        Node *newNode = new Node(coeff, pow);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            while (temp->link != nullptr) {
                temp = temp->link;
            }
            temp->link = newNode;
        }
    }

    void displayList() {
        Node *temp = head;
        while (temp != nullptr) {
            std::cout << temp->coeff << "x^" << temp->pow << " + ";
            temp = temp->link;
        }
        cout << "0\n";
    }

private:
    void removeExtra() {
        Node *temp1 = head;
        Node *temp2, *temp3;
        while (temp1 != nullptr) {
            temp2 = temp1->link;
            temp3 = temp1;
            while (temp2 != nullptr) {
                if (temp2->pow == temp1->pow) {
                    temp1->coeff += temp2->coeff;
                    temp3->link = temp2->link;
                }
                temp3 = temp2;
                temp2 = temp2->link;
            }
            temp1 = temp1->link;
        }
    };

public:
    LinkedList* add(LinkedList *one, LinkedList *two) {
        if (one == nullptr && two == nullptr) {
            return new LinkedList();
        }

        one->removeExtra();
        two->removeExtra();

        LinkedList *result = new LinkedList();

        if (one != nullptr) {
            Node *temp1 = one->head;
            while (temp1 != nullptr) {
                result->addAtEnd(temp1->coeff, temp1->pow);
                temp1 = temp1->link;
            }
        }

        if (two != nullptr) {
            Node *temp2 = two->head;
            while (temp2 != nullptr) {
                result->addAtEnd(temp2->coeff, temp2->pow);
                temp2 = temp2->link;
            }
        }

        result->removeExtra();
        return result;
    }

    void sort(){
       Node *temp1 = head;
        while (temp1 != nullptr) {
            Node *temp2 = temp1->link;
            while (temp2 != nullptr) {
                if (temp1->pow < temp2->pow) {
                    swap(temp1->coeff, temp2->coeff);
                    swap(temp1->pow, temp2->pow);
                }
                temp2 = temp2->link;
            }
            temp1 = temp1->link;
        }
    }
};

int main() {
    LinkedList *eq1 = new LinkedList();
    LinkedList *eq2 = new LinkedList();

    eq1->addAtEnd(3, 4);
    eq1->addAtEnd(2, 3);
    eq1->addAtEnd(-9, 2);
    eq1->addAtEnd(8, 2);
    eq1->addAtEnd(4, 1);
    eq1->addAtEnd(-5, 0);

    eq2->addAtEnd(5, 5);
    eq2->addAtEnd(-3, 3);
    eq2->addAtEnd(8, 1);
    cout << "EQUATION 1:\n";
    eq1->displayList();
    cout << "EQUATION 2: \n";
    eq2->displayList();

    LinkedList *result = eq1->add(eq1, eq2);
    result->sort();
    cout << "\nRESULT:\n";
    result->displayList();

    delete eq1;
    delete eq2;
    delete result;

    return 0;
}
