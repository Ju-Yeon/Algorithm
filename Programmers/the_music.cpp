#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getTime(string time);
string solution(string m, vector<string> musicinfos);
struct music{
    int time;
    string title;
    string notes;
};

int main(){
    string m = "ABC";//"CC#BCC#BCC#BCC#B";
    vector<string> musicinfos = {"11:59,13:13,HELLO,C#DEFGABC", "13:00,13:05,WORLD,ABCDEF", "13:00,13:05,WORLD,ABCDEF"}; //{"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"};

    cout<<solution(m, musicinfos)<<endl;
}

string solution(string m, vector<string> musicinfos) {
    music answer = {0, "", ""};
    int size = musicinfos.size();

    music* musics= new music[size];
    for(int i = 0; i < size; i++)
    {
        musics[i].time = getTime(musicinfos[i].substr(0, 11));
        musics[i].title = musicinfos[i].substr(12,musicinfos[i].find(',',12)-12);
        string note = musicinfos[i].substr(musicinfos[i].find(',',12)+1, 1439);

        for(int t = 0, l = 0; t < musics[i].time; t++, l++) {
            musics[i].notes += note[l%note.length()];
            if(note[l%note.length()+1] == '#') musics[i].notes += note[(++l)%note.length()];

        }

        //cout<<musics[i].title<<" : "<< musics[i].time<<"분 동안 "<<musics[i].notes<<endl;

        int idx = musics[i].notes.find(m);
        if(idx != -1 && musics[i].notes[idx+m.length()] != '#' ){
            if(!answer.time) answer = musics[i];
            else answer = answer.time < musics[i].time ? musics[i] : answer;
        }
    }
    if(!answer.time) return "(None)";
    return answer.title;
}

int getTime(string time){

    int t[4], flag = 0, result = 0;
    for(int i = 0; i< 4; i++)
        t[i] = atoi(time.substr(3*i,2).c_str());

    if(t[1] > t[3]){
        result = 60 - t[1] + t[3];
        flag = 1;
    }else {
        result = t[3] - t[1];
    }

    result += 60 * (t[2]- t[0] - flag);
    return result;
}
