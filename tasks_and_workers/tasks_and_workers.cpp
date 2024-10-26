#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <fstream>



using namespace std;

int main()
{
    cout << "Hello World!\n";
    int timeStimate;
    cin >> timeStimate;
    clock_t startTime = clock();
    int numberOfTasks, numberOfWorkers, minimumTime =10000, maximumTime;
    //the values are for test run
    int abilityToWork[8][3] = { {1,0,1},{1,1,1},{0,1,0},{1,0,1},{0,1,0},{0,1,0},{1,0,1},{1,1,1} };
    int tasksTimeStimates[8] = {3, 5, 9, 12, 4, 5, 7, 8};
    int resultAssignedTasks[8] = {0};
    int resultTimeTake[3] = {0};
    //readfile function code
    /*
    ifstream inputFile("input.txt");
    if (!inputFile)
    {
        cout << "file didn't opened";
        exit(-1);
    }
    inputFile >> numberOfTasks >> numberOfWorkers;
    for (int i = 0; i < 3; i++)
        inputFile >> tasksTimeStimates[i];
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            inputFile >> abilityToWork[i][j];
    */
    //seed of random number generator using time(0)
    srand(time(0));

    //(clock() - startTime) returns the clocs that are past from current time
    // ( ... / CLOCKS_PER_SEC )  returns the past clocks in seconds form
    while ((clock() - startTime) / CLOCKS_PER_SEC < timeStimate) 
    {
        int assignedTasks[8] = { 0 };
        int timeTake[3] = { 0 };
        maximumTime = 0;


        for (int i = 0; i < 8; i++)
        {
            int randomWorker = rand() % 3;
            while (abilityToWork[i][randomWorker] == 0)
                randomWorker = rand() % 3;
            assignedTasks[i] = randomWorker + 1;
            timeTake[randomWorker] += tasksTimeStimates[i];
        }
        for (int i = 0; i < 3; i++)
            if (timeTake[i] > maximumTime)
                maximumTime = timeTake[i];
        if (minimumTime > maximumTime) 
        {
            minimumTime = maximumTime;
            for (int i = 0; i < 8; i++)
                resultAssignedTasks[i] = assignedTasks[i];
            for (int i = 0; i < 3; i++)
                resultTimeTake[i] = timeTake[i];
        }
        else
            continue;
        for (int i = 0; i < 8; i++)
            cout << assignedTasks[i] << "  ";
        cout << endl << maximumTime << endl;
    }
    cout << "result" << endl;
        for (int i = 0; i < 8; i++)
            cout << resultAssignedTasks[i] << "  ";
        cout << endl << minimumTime << endl;
}
