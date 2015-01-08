#include<map>
#include<iostream>
using namespace std;

int main(void){
    map<string, int> chord;
    string note1, note2, note3;
    int interval1, interval2;
    chord["C"] = chord["B#"]  = chord["c"] = chord["b#"]= 0;
    chord["c#"] = chord["db"] = chord["C#"] = chord["Db"] = 1;
    chord["d"] = chord["D"] = 2;
    chord["D#"] = chord["Eb"]  = chord["d#"] = chord["eb"]= 3;
    chord["E"] = chord["Fb"] = chord["e"] = chord["fb"] = 4;
    chord["f"] = chord["e#"]= chord["F"] = chord["E#"] = 5;
    chord["F#"] = chord["Gb"]  = chord["f#"] = chord["gb"]= 6;
    chord["G"]  = chord["G"] = 7;
    chord["g#"] = chord["ab"] = chord["G#"] = chord["Ab"] = 8;
    chord["a"] = chord["A"] = 9;
    chord["A#"] = chord["Bb"]  = chord["a#"] = chord["bb"]= 10;
    chord["b"] = chord["cb"] = chord["B"] = chord["Cb"] = 11;
    while(cin>>note1>>note2>>note3){
        if(chord[note1]>chord[note2])
            interval1 = chord[note1] - chord[note2];
        else
            interval1 = chord[note2] - chord[note1];
        if(chord[note2]>chord[note3])
            interval2 = chord[note2] - chord[note3];
        else
            interval2 = chord[note3] - chord[note2];
        if((interval1 == 4 && interval2 == 3)|| (interval1 == 3 && interal2 == 7) || (interval1 == ))


    }
    return 0;
}
