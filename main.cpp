#include <iostream>
#include "company.h"

using namespace std;
template<typename T>

void enterValue(T &n, T min = numeric_limits<T>::min(), T max = numeric_limits<T>::max()) {
    n = max / 2;
    do
    {
        if(!cin || (n < min || n > max))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout << "-------------------Error----------------\n";
            cout << min << " <= number diapason <= " << max;
            cout << "\n-----------------------------------------\n";
            cout << "Repeat enter:";
        }

        cin>>n;
    }
    while(!cin || (n < min || n > max));
}

int main() {

    Human::setNextID(100);
    Manager** teamManagers;
    int countManagers = 0;

    cout << "---Company---" << endl;
    cout << "Hello, whats your name?" << endl;
    Director myDir;
    cout << "-Ok, " << myDir.getInformation() << " now you director!" << endl;
    cout << "How many managers in your company?:";
    enterValue(countManagers,1,5);
    cout << "-ok" << endl;
    teamManagers = new Manager*[countManagers];

    for (int i = 0; i < countManagers; ++i)
    {
        system("cls");
        int countWorkers = 0;
        cout << "-Manager N " << i + 1 << endl;
        teamManagers[i] = new Manager();
        cout << "-How many worker in team Manager N" << i + 1 <<"?:";
        enterValue(countWorkers,5,25);
        teamManagers[i]->setTeamWorkers(new TeamWorkers(countWorkers));
        cout << "-ok" << endl;
    }

    system("cls");

    while(!allCompanyBusy(teamManagers, countManagers))
    {
        int Task = 0;
        int nManager;
        cout << "---Task statement---" << endl;
        cout << "Enter task-cod:";
        enterValue(Task,0);
        cout << "Enter number of manager for task-cod '" << Task  <<"':";
        enterValue(nManager,1,countManagers);
        system("cls");
        cout << "Message from manager " << teamManagers[nManager - 1]->getInformation() << ":" << endl;
        myDir.giveTask(teamManagers[nManager - 1],Task);
    }

    system("cls");
    cout << "Congratulations! All the workers are busy, you can go home!" << endl;
    cout << "---Bye, bye---" << endl;
    system("pause");
    return 0;
}
