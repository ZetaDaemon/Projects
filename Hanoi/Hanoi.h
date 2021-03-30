#ifndef HANOI_H
#define HANOI_H

class Hanoi {
    private:
    string Disks[5] = {"    |    ", "\033[31m   -|-   \033[39m", "\033[32m  --|--  \033[39m", "\033[33m ---|--- \033[39m", "\033[34m----|----\033[39m"};
    int towers[3][4];
    int stackTop[3] = {3, 3, 3};
    int stackTopVal[3] = {0, 0, 0};
    int moves = 0;

    public:
    Hanoi() {
        for(int i = 0; i < 4; i++) {
            towers[0][i] = i+1;
        }
        stackTopVal[0] = 1;
        stackTop[0] = 0;
        for(int i = 1; i < 3; i++) {
            for(int k = 0; k < 4;k++) {
                towers[i][k] = 0;
            }
        }
    }

    void printTower();
    void updateTop();
    void play();
    bool swapDisk(int a, int b);
    bool testWin();
};

void Hanoi::printTower() {
    for(int i = 0; i < 4; i++) {
        for(int k = 0; k < 3;k++) {
            cout << " " << Disks[(towers[k][i])] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 3; i++) {
        cout << "===========";
    }
    cout << endl;
    for(int i = 0; i < 3; i++) {
        cout << "     " << i+1 << "     ";
    }
    cout << endl << endl;
}

void Hanoi::updateTop() {
    for(int i = 0; i < 3; i++) {
        int k = 0;
        while(towers[i][k] == 0 && k < 3) {
            k++;
        }
        stackTop[i] = k;
        stackTopVal[i] = towers[i][k];
    }
}

bool Hanoi::swapDisk(int a, int b) {
    if(a < 1 || a > 3) {
        cout << "Cannot do this move\n";
        return false;
    }
    if(b < 1 || b > 3) {
        cout << "Cannot do this move\n";
        return false;
    }
    a--;
    b--;
    if((stackTopVal[b] == 0  || (stackTopVal[a] < stackTopVal[b])) && stackTopVal[a] != 0) {
        int nz = 0;
        if(stackTopVal[b] != 0) {
            nz = 1;
        }
        int temp = towers[a][stackTop[a]];
        towers[a][stackTop[a]] = towers[b][stackTop[b]-nz];
        towers[b][stackTop[b]-nz] = temp;
        return true;
    }
    else {
        cout << "Cannot do this move\n";
        return false;
    }
}

bool Hanoi::testWin() {
    bool win = true;
    int winStack[4] = {1, 2, 3, 4};
    for(int i = 0; i < 4; i++) {
        if(towers[2][i] != winStack[i]) {
            win = false;
            break;
        }
    }
    return win;
}

void Hanoi::play() {
    cout << "The goal is to move the stack from the first tower to the third tower.\n";
    printTower();
    int a, b;
    do {
        do {
            cout << "Input two to move a disk, the first being the current location and second being the destination:\n";
            cin >> a >> b;
        } while(!swapDisk(a, b));
        moves++;
        printTower();
        updateTop();
    } while(!testWin());
    cout << "Congrats you did it!\n";
    cout << "Number of moves: " << moves << endl;
}

#endif
