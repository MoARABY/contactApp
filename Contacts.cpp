#include <iostream>

using namespace std;

struct Node {

    Node* next;
    string name, phone;
    
};

class Contacts {

private:

    int sz;
    Node *firstContact, *lastContact;
    
public:
    
    Contacts() {

        sz = 0;
        firstContact = lastContact = nullptr;

    }

    int size() {
        return sz;
    }

    void insertFirst(string name, string phone) {

        string existingNo = getName(phone);

        if(firstContact != nullptr and existingNo != "Phone number is not found") {

            cout << "Phone number already exists with name: " + existingNo;
            return; 

        }

        Node *newContact = new Node;
        ++sz;

        newContact -> name = name;
        newContact -> phone = phone;

        newContact -> next = firstContact;
        firstContact = newContact;

    }

    void insertLast(string name, string phone) {

        string existingNo = getName(phone);

        if(firstContact != nullptr and existingNo != "Phone number is not found") {

            cout << "Phone number already exists with name: " + existingNo;
            return; 

        }

        if(!lastContact) {

            lastContact = firstContact = new Node;

            lastContact -> name = name;
            lastContact -> phone = phone;

        }

        else {

            lastContact -> next = new Node, lastContact = lastContact -> next;
            lastContact -> name = name, lastContact -> phone = phone;

        }
        ++sz;
    }

    void insertAt(int pos, string name, string phone) {

        if(pos <= 0 or pos > sz) {

            cout << "Invalid Position" << '\n';
            return;

        }

        if(pos == 1) {

            insertFirst(name, phone);
            return;

        }
            
        else if(pos == sz) {

            insertLast(name, phone);
            return;

        }

        string existingNo = getName(phone);

        if(existingNo != "Phone number is not found") {

            cout << "Phone number already exists with name: " + existingNo;
            return; 

        }
        
        Node *p = firstContact, *q = nullptr;

        for(int i = 1; i < pos; ++i)
            q = p, p = p -> next;

        Node *nw = new Node;
        nw -> name = name, nw -> phone = phone;

        q -> next = nw, nw -> next = p;
        ++sz;

    }    

    string getPhoneNums(string name) {

        Node *p = firstContact;
        string nums = "input name is not found";

        while(p) {

            if(p -> name == name) {

                if(nums == "input name is not found")
                    nums = "Numbers: ";

                nums += p -> phone + ", ";

            } 
            p = p -> next;
        }

        if(nums != "input name is not found") 
            nums.pop_back(), nums.pop_back();
            
        return nums;
    }

    string getName(string phone) {

        Node *p = firstContact;

        while(p) {

            if(p -> phone == phone)
                return p -> name;

            p = p -> next;

        }
        return "Phone number is not found";
    }

    string deleteByPhone(string phone) {

        if(firstContact -> phone == phone) {

            string x = firstContact -> phone;

            Node *tmp = firstContact;
            firstContact = firstContact -> next;
            
            --sz, delete tmp;

            return x + " has been deleted";

        }

        Node *p = firstContact, *q = nullptr;

        while(p) {

            if(p -> phone == phone) {

                string x = p -> phone;
                q -> next = p -> next;

                delete p, --sz;
                return x + " has been deleted";

            }

            q = p;
            p = p -> next;

        }
        return "Not found";
    }         

    void displayAll() {

        Node *p = firstContact;

        while(p) {

            cout << "Contact Name " << p -> name << "Contact Phone " << p -> phone << '\n';
            p = p -> next;

        }

    }

    void UpdateByName(string name, string newPhone) {
        Node* c = firstContact;
        while (c) {
            if (c->name == name) {
                string existingName = getName(newPhone);
                if (existingName != "Phone number is not found" && existingName != name) {
                    cout << "Phone number already exists with name: " << existingName << endl;
                    return;
                }
                c->phone = newPhone;
                cout << "Phone number for " << name << " has been updated to: " << newPhone << endl;
                return;
            }
            c = c->next;
        }
        cout << "مفيش الاسم دا" << endl;
    }

    void UpdateByPhone(string phoneNumber, string newName) {
        Node* c = firstContact;
        while (c) {
            if (c->phone == phoneNumber) {
                string existingPhone = getPhoneNums(newName);
                if (existingPhone != "input name is not found" && existingPhone != phoneNumber) {
                    cout << "Name already exists with phone number: " << phoneNumber << endl;
                    return;
                }
                c->name = newName;
                cout << "Name for phone number " << phoneNumber << " has been updated to: " << newName << endl;
                return;
            }
            c = c->next;
        }
        cout << "مفيش الرقم دا" << endl;
    }
    
    ~Contacts() {

        Node *p = firstContact;

        while(p) {

            Node *tmp = p;
            p = p -> next, delete tmp;

        }

    }
};



int main() 
    {
        int choice;
        int addChoice;
        int delchoise;
        int updatechoise;
        string NewName,NewPhone;
        int ContactPosition;
        string DelPhoneNum;
        string UpdatePhoneNum;
        string NewNum;
        string UpdatePhoneName;
        Contacts NewContact;
    do
    {
        Begin:
        cout << "\nMain Menu:\n";
        cout << "1. Add a contact\n";
        cout << "2. Delete a contact\n";
        cout << "3. Edit a contact\n";
        cout << "4. Display all contacts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if(choice == 5 )
        {
            cout << "Exiting the program.\n";
            break;
        }
        
        // if(choice != NULL && choice > 0 && choice < 6)
        if(choice > 0 && choice < 6)
        {
            do
            {
                switch (choice)
                {
                case 1:
                {
                    cout << "\nChoose where to add the contact:\n";
                    cout << "1. Add at the beginning\n";
                    cout << "2. Add at the end\n";
                    cout << "3. Add at a specific position\n";
                    cout << "Enter your choice: ";
                    cin >> addChoice;
                    if(addChoice <1 || addChoice>3)
                    {cout<<"Invalid Choise";
                    break;}
                    if(addChoice==1)
                    {
                        cout <<"EnterYourName\n";
                        cin >>NewName;
                        cout <<"EnterYourPhone\n";
                        cin >>NewPhone;
                        NewContact.insertFirst(NewName,NewPhone);
                        cout <<"Contact Saved Successfully\n";
                        goto Begin;
                    }
                    else if(addChoice==2)
                    {
                        cout <<"EnterYourName\n";
                        cin >>NewName;
                        cout <<"EnterYourPhone\n";
                        cin >>NewPhone;
                        NewContact.insertLast(NewName,NewPhone);
                        cout <<"Contact Saved Successfully\n";
                        goto Begin;
                    }
                    else
                    {
                        cout <<"EnterYourName\n";
                        cin >>NewName;
                        cout <<"EnterYourPhone\n";
                        cin >>NewPhone;
                        cout <<"EnterThePosition\n";
                        cin >>ContactPosition;
                        NewContact.insertAt(ContactPosition,NewName,NewPhone);
                        cout <<"Contact Saved Successfully\n";
                        goto Begin;
                    }
                }
                case 2:
                {
                    cout << "Enter your Phone Number: ";
                    cin >> DelPhoneNum;
                    NewContact.deleteByPhone(DelPhoneNum);
                    cout << "Contact Has Been Deleted Successfully";
                    goto Begin;
                }
                case 3:
                {
                cout << "\nChoose how to edit the contact:\n";
                cout << "1. Edit phone number by name\n";
                cout << "2. Edit name by phone number\n";
                cout << "Enter your choice: ";
                cin >> updatechoise;
                // if(updatechoise == null || updatechoise >2 || updatechoise < 1)
                if(updatechoise >2 || updatechoise < 1)

                {
                    cout<<"Invalid Choise";
                    break;
                }
                else
                {
                    if(updatechoise==1)
                    {
                        cout << "Enter The Old Number: ";
                        cin >> UpdatePhoneNum;
                        cout << "Enter The New Number";
                        cin >> NewNum;
                        NewContact.UpdateByPhone(UpdatePhoneNum,NewNum);
                        cout << "Contact Updated Successfully";
                        goto Begin;
                    }
                    else if(updatechoise==2)
                    {
                        cout << "Enter The Name: ";
                        cin >> UpdatePhoneName;
                        cout << "Enter The New Number";
                        cin >> NewNum;
                        NewContact.UpdateByName(UpdatePhoneName,NewNum);
                        cout << "Contact Updated Successfully";
                        goto Begin;
                    }

                }
                }
                case 4:
                {
                    NewContact.displayAll();
                    goto Begin;
                }
            }
            }
            // while(choice != nullptr && choice > 0 && choice < 6);
            while( choice > 0 && choice < 6);
        }
        else
        {
            cout <<"Invalid Selection";
        }
    }
    while(true);
    }





    // int sz;
    // cin >> sz;

    // Contacts c1;

    // for(int i = 0; i < sz; ++i) {

    //     string name, phone;
    //     cin >> name >> phone;

    //     c1.insertLast(name, phone);

    // }

    // c1.insertAt(2, "new", "010");
    // c1.deleteByPhone("012");

    // c1.insertFirst("Mohamed", "0312");
    // c1.insertAt(0, "new", "0124");

    // c1.displayAll();
    // cout << c1.size();