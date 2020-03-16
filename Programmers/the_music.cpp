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
    string m = "ABC";
    vector<string> musicinfos = {"11:59,12:13,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABDEF", "13:00,13:15,BOOOM,ABC#DEFABC#DEFABC"};
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
        //원래 음악의 악보
        string note = musicinfos[i].substr(musicinfos[i].find(',',12)+1, 1439);
        //악보를 재생시간만큼, #고려하기
        for(int t = 0, l = 0; t < musics[i].time; t++, l++) {
            musics[i].notes += note[l%note.length()];
            if(note[l%note.length()+1] == '#') musics[i].notes += note[(++l)%note.length()];
        }

        //cout<<musics[i].title<<" : "<< musics[i].time<<"분 동안 "<<musics[i].notes<<endl;
        //#이 있으면 다음번 문자열 찾기를 진행해야함!
        int idx = musics[i].notes.find(m);
        while(idx != -1 && musics[i].notes[idx+m.length()] == '#' ){
            idx = musics[i].notes.find(m, idx+1);
        }

        if(idx != -1 && musics[i].notes[idx+m.length()] != '#' ){
            if(!answer.time) answer = musics[i];
            else answer = answer.time < musics[i].time ? musics[i] : answer;
        }
    }
    if(!answer.time) return "(None)";
    return answer.title;
}

//시간 문자열을 통해 재생시간 계산
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
