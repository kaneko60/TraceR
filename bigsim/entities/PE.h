/*
 * PE.h
 *
 *  Created on: Oct 20, 2010
 *      Author: ehsan
 */

#ifndef PE_H_
#define PE_H_

#include "MsgEntry.h"
#include "../events/Event.h"
#include "../events/ExecCompleteEvent.h"
#include <cstring>
#include "Task.h"
#include <vector>

using namespace std;
class Task;

class PE {
  public:
    PE();
    vector<int> msgBuffer;
    Task* myTasks;	// all tasks of this PE
    unsigned long long currTime;
    bool busy;
    int windowOffset;
    int beforeTask, totalTasksCount;
    int myNum, myEmPE;
    int tasksCount;	//total number of tasks
    int currentTask; // index of first not-executed task (helps searching messages)

    long long startExec(unsigned long long newTime);
    void completeExec(unsigned long long);	// after complete event
    long long startRecursiveExec(int tInd, unsigned long long beforeExecutedTime);	// exec task tree
    void receiveMsg(MsgID, unsigned long long);
    bool noUnsatDep(int tInd);	// there is no unsatisfied dependency for task
    void printStat();
    void check();
    void printState();

    //BILGE
    unsigned long long getTaskExecTime(int tInd);
};

#endif /* PE_H_ */
