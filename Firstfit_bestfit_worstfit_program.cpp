#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void firstFit(vector<int> blocks, vector<int> processes) {
    cout << "\nFirst Fit Allocation:\n";
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++) {
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i]) {
                allocation[i] = j;
                blocks[j] -= processes[i];
                break;
            }
        }
    }

    for (int i = 0; i < processes.size(); i++) {
        cout << "Process " << i + 1 << " of size " << processes[i] << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

void bestFit(vector<int> blocks, vector<int> processes) {
    cout << "\nBest Fit Allocation:\n";
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++) {
        int bestIdx = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i]) {
                if (bestIdx == -1 || blocks[j] < blocks[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blocks[bestIdx] -= processes[i];
        }
    }

    for (int i = 0; i < processes.size(); i++) {
        cout << "Process " << i + 1 << " of size " << processes[i] << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

void worstFit(vector<int> blocks, vector<int> processes) {
    cout << "\nWorst Fit Allocation:\n";
    vector<int> allocation(processes.size(), -1);

    for (int i = 0; i < processes.size(); i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (blocks[j] >= processes[i]) {
                if (worstIdx == -1 || blocks[j] > blocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blocks[worstIdx] -= processes[i];
        }
    }

    for (int i = 0; i < processes.size(); i++) {
        cout << "Process " << i + 1 << " of size " << processes[i] << " -> ";
        if (allocation[i] != -1)
            cout << "Block " << allocation[i] + 1 << endl;
        else
            cout << "Not Allocated\n";
    }
}

int main() {
    vector<int> blocks = {100, 500, 200, 300, 600};
    vector<int> processes = {212, 417, 112, 426};

    firstFit(blocks, processes);
    bestFit(blocks, processes);
    worstFit(blocks, processes);

    return 0;
}
