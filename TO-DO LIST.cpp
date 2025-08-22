#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string work;
    bool work_status;
};

vector<Task> tasks;

//  add a task to do list
void taskinput(string work) {
    tasks.push_back({work, false});
    cout << "Task added\n";
}

//to view all tasks
void viewtasks() {
    if (tasks.empty()) {
        cout << "No tasks\n";
        return;
    }
    cout << "\nTo-Do List\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i+1 << ". " << tasks[i].work 
             << (tasks[i].work_status ? "Done" : "pending") <<"\n";
    }
}

//  mark a task as completed
void marktaskcompleted(int index) {
    if (index<1 || index>tasks.size()) {
        cout <<"Invalid task number!\n";
        return;
    }
    tasks[index- 1].work_status = true;
    cout << "Task marked as completed!\n";
}

// remove a task
void removetask(int index) {
    if (index < 1 || index > tasks.size()) {
        cout << "Invalid task number!\n";
        return;
    }
    tasks.erase(tasks.begin() + (index - 1));
    cout << "Task removed \n";
}
//to do list manager
int main() {
    int choice;
    string work;
    do {
        cout << "\n--- TO-DO LIST MANAGER ---\n";
        cout << "1. add task\n";
        cout << "2. view tasks\n";
        cout << "3. mark task as completed\n";
        cout << "4. remove task\n";
        cout << "5. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        cin.ignore();
        

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin,work);
                taskinput(work);
                break;
            case 2:
                viewtasks();
                break;
            case 3:
                int completedchoice;
                cout << "Enter task number to mark as completed: ";
                cin>> completedchoice;
                marktaskcompleted(completedchoice);
                break;
            case 4:
                int removechoice;
                cout<< "Enter task number to remove: ";
                cin >>removechoice;
                removetask(removechoice);
                break;
            case 5:
                cout<< "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while(choice!=5);

    return 0;
}