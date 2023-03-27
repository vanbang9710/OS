#include "common.h"
#include <set>

class IncompleteProgress
{
public:
    int processID;
    int duration;
    IncompleteProgress(int processID, int duration) {
        this->duration = duration;
        this->processID = processID;
    }
    pair<int,int> getPair() const {
        return pair<int,int> (this->duration, this->processID);
    }
    friend bool operator < (const IncompleteProgress& a, const IncompleteProgress& b) {
        return a.getPair() < b.getPair();
    }
    friend bool operator > (const IncompleteProgress& a, const IncompleteProgress& b) {
        return a.getPair() > b.getPair();
    }
};

void SRTF(const queue &q, Gantt &running_chart)
{
    set<IncompleteProgress> readyQueue;
    int clock = 0;
    int completeTask = 0;
    int nextInProcess = 0;

    while (completeTask < q.size())
    {
        // Add proccess to Ready queue
        while (nextInProcess < q.size() && q[nextInProcess]._appear <= clock)
        {
            readyQueue.insert(IncompleteProgress(nextInProcess, q[nextInProcess]._duration));
            ++nextInProcess;
        }

        // If there are no process in Ready queue, increase the clock to next process appear time and skip the remain code
        if (readyQueue.empty()) {
            clock = q[nextInProcess]._appear;
            continue;
        }

        // Get the smallest remaining burst duration process in the Ready queue
        IncompleteProgress executingProgress = *readyQueue.begin();
        readyQueue.erase(readyQueue.begin());
        int executeDuration = executingProgress.duration;
        for (int i=nextInProcess;i<q.size();++i)
            if (q[i]._appear+q[i]._duration < clock + executingProgress.duration) {
                executeDuration = q[i]._appear - clock;
                break;
            }
        
        // Simulate execute the executing process for executeDuration time units
        clock += executeDuration;
        running_chart.push_back(CPUBurst(executingProgress.processID, executeDuration));
        executingProgress.duration -= executeDuration;

        // If the executing process haven't finished, push it back to the Ready queue
        // Else increase the complete task counter
        if (executingProgress.duration > 0)
            readyQueue.insert(executingProgress);
        else
            ++completeTask;
    }
}