#include<iostream>
#include<map>

using namespace std;

int main(void){
    map<string,int> scale;
    map<int,string> scaleinv;
    scale["C"] = 0;
    scale["C#"] = 1;
    scale["D"] = 2;
    scale["D#"] = 3;
    scale["E"] = 4;
    scale["E#"] = 5;
    scale["F"] = 5;
    scale["F#"] = 6;
    scale["G"] = 7;
    scale["G#"] = 8;
    scale["A"] = 9;
    scale["A#"] = 10;
    scale["B"] = 11;
    scale["B#"] = 0;
    scaleinv[0] = "C";
    scaleinv[1] = "C#";
    scaleinv[2] = "D";
    scaleinv[3] = "D#";
    scaleinv[4] = "E";
    scaleinv[5] = "F";
    scaleinv[6] = "F#";
    scaleinv[7] = "G";
    scaleinv[8] = "G#";
    scaleinv[9] = "A";
    scaleinv[10] = "A#";
    scaleinv[11] = "B";
    int notes[12][12] = {
    1,0,1,0,1,1,0,1,0,1,0,1,
    1,1,0,1,0,1,1,0,1,0,1,0,
    0,1,1,0,1,0,1,1,0,1,0,1,//d
    1,0,1,1,0,1,0,1,1,0,1,0,//eb
    0,1,0,1,1,0,1,0,1,1,0,1,//e
    1,0,1,0,1,1,0,1,0,1,1,0,//f
    0,1,0,1,0,1,1,0,1,0,1,1,//f#
    1,0,1,0,1,0,1,1,0,1,0,1,//g
    1,1,0,1,0,1,0,1,1,0,1,0,//as
    0,1,1,0,1,0,1,0,1,1,0,1,//a
    1,0,1,1,0,1,0,1,0,1,1,0,//bes
    0,1,0,1,1,0,1,0,1,0,1,0,//b
    };
    string input, newstr;
    int len, value;
    bool valid[12], first;
    while(getline(cin,input)){
        if(input == "END")
            return 0;
        for(int i=0;i<12;i++)
            valid[i] = true;
        len = input.length();
        for(int i=0;i<len;i++){
            if(input.at(i)!=' ')
                newstr = newstr + input.at(i);
            else if(input.at(i)==' '){
                value = scale[newstr];
                newstr.clear();
                for(int j=0;j<12;j++)
                    if(notes[j][value]==0)
                        valid[j] = false;
            }
            if(i==len-1 && newstr.size()>0){
                value = scale[newstr];
                newstr.clear();
                for(int j=0;j<12;j++)
                    if(notes[j][value]==0)
                        valid[j] = false;
            }

        }
        first = true;
        for(int i=0;i<12;i++)
            if(valid[i]){
                    cout<<scaleinv[i]<<" ";
            }
        cout<<endl;
    }
    return 0;
}
