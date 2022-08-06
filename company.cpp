//
// Created by Sg on 05.08.2022.
//

#include "company.h"

int Human::nextID;
int TeamWorkers::getWorkerCount() const {
    return countWorker;
}
Worker** TeamWorkers::getWorkers() {
    return workers;
}
TeamWorkers::TeamWorkers(int _countWorker)    {
    countWorker = _countWorker;
    workers = new  Worker*[countWorker];
    for (int i = 0; i < countWorker; ++i) {
        cout << "--Worker N" << i +1 << endl;
        workers[i] = new  Worker();
    }
}
int TeamWorkers::busyCount() const {
    int count = 0;
    for (int i = 0; i <countWorker; ++i)
    {
        if(workers[i]->busy())
            count++;
    }
    return count;
}
bool TeamWorkers::getAllBusy() const {
    return allBusy;
}
Manager::Manager() : Human() {
    teamWorker = nullptr;
}
void Manager::giveTaskTeam(int Task) {

    if(teamWorker == nullptr)
        return;

    srand ( ID + Task);

    int busyWorkerCount = teamWorker->busyCount();
    int workerCount = teamWorker->getWorkerCount();
    int workerCountForTask = rand() % (workerCount - busyWorkerCount) + 1;
    Worker** wWorker = teamWorker->getWorkers();
    wWorker+=busyWorkerCount;

    for (int i = 0; i < workerCountForTask; ++i)
    {
        (*wWorker)->setTask(rand() % 3);
        busyWorkerCount++;
        wWorker++;
    }

    wWorker-=busyWorkerCount;
    for (int i = 0; i < busyWorkerCount; ++i)
    {
        cout << "--Worker:" << (*wWorker)->getInformation() << " do task '" << (*wWorker)->getTask() << "'" << endl;
        wWorker++;
    }

    cout << "Busy " << busyWorkerCount << " workers, free workers " << workerCount - busyWorkerCount << endl;

    if(busyWorkerCount == workerCount)
        setAllBusy();

}
void Manager::setTeamWorkers(struct TeamWorkers *inTeamWorker) {
    teamWorker = inTeamWorker;
}
void Manager::setAllBusy() {
    teamWorker->allBusy = true;
}
bool Manager::getAllTeamBusy() const {
    return teamWorker->getAllBusy();
}
void Worker::setTask(int nTask) {
    if(nTask == 0)
        task = 'A';
    else if(nTask == 1)
        task = 'B';
    else if(nTask == 2)
        task = 'C';
}
bool Worker::busy() const {
    if(task != '-')
        return true;
    else
        return false;
}
char Worker::getTask() const {
    return task;
}
void Director::giveTask(Manager *myM, int inTask) {
    if(myM->teamWorker != nullptr)
    {
        if(!myM->getAllTeamBusy())
            myM->giveTaskTeam(inTask);
        else
            cout << "Error! All workers in team manager " << ID << " is busy!" << endl;
    }
    system("pause");
    system("cls");
}
bool allCompanyBusy(Manager **myMT, int m) {
    for (int i = 0; i < m; ++i) {
        if(!myMT[i]->getAllTeamBusy())
            return false;
    }
    return true;
}
Human::Human() {
    nextID++;
    ID = nextID;
    cout << "Enter the name:";
    cin >> name;
}
string Human::getInformation() const {
    return name + " ID " + to_string(ID);
}
void Human::setNextID(int inID) {
    nextID = inID;
}
