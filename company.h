//
// Created by Sg on 05.08.2022.
//
#include <string>
#include <iostream>
#include <limits>
#pragma once
using namespace std;
class Human
{
    static int nextID;
protected:
    string name = "none";
    int ID = 0;
public:
    static void setNextID(int inID);
    string getInformation() const;

    explicit Human();
};
class Worker: public Human
{
protected:
    char task = '-';
public:
    void setTask(int nTask = 0);
    char getTask() const;
    bool busy() const;
};
class Director: public Human
{
public:
    void giveTask(class Manager *myM, int inTask);
};
class Manager: public Human
{
    class TeamWorkers* teamWorker = nullptr;
    void giveTaskTeam(int Task);
    void setAllBusy();
    friend void Director::giveTask(class Manager *myM, int inTask);
public:
    bool getAllTeamBusy() const;
    void setTeamWorkers(class TeamWorkers* inTeamWorker);

    explicit Manager();
};
class TeamWorkers
{
    Worker** workers = nullptr;
    int countWorker = 0;
    bool allBusy = false;
    Worker ** getWorkers();
    friend class Manager;
public:
    int getWorkerCount() const;
    int busyCount() const;
    bool getAllBusy() const;

    explicit TeamWorkers(int inCountWorker);
};
bool allCompanyBusy(Manager** myMT, int m);





