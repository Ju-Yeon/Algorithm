#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(vector<string> lines);
int* getStime(int etime[3], int time);
bool isSmall(int small[3], int big[3]);

struct transaction {
    int * stime;
    int * etime;
};


int solution(vector<string> lines) {
    int answer = 0;
    transaction * t = new transaction[lines.size()];

    for(int i = 0; i < lines.size(); i++){
        t[i].stime = new int[3];
        t[i].etime = new int[3];

        for(int l = 0; l < 2; l++)
            t[i].etime[l] = atoi(lines[i].substr(11 + 3 * l, 2).c_str());
        t[i].etime[2] = atof(lines[i].substr(17, 6).c_str()) * 1000.0;

        t[i].stime = getStime(t[i].etime, atof(lines[i].substr(24, lines[i].find("s")-24).c_str()) * 1000.0);
    }

//    for(int i = 0; i < lines.size(); i++) {
//        for (int a = 0; a < 3; a++) {
//            cout << t[i].stime[a] << " ";
//        }
//        cout << endl;
//        for (int a = 0; a < 3; a++) {
//            cout << t[i].etime[a] << " ";
//        }
//        cout << endl << endl;
//    }

    int *stime = new int[3];
    int *etime = new int[3];
    int count = 0;

    for(int i = 0; i < lines.size(); i++){
        count = 0;
        for(int l = 0; l<3; l++){
            stime[l] = t[i].etime[l];
            etime[l] = t[i].etime[l];
        }

        etime[2] = etime[2] + 1000 - 1;

        for(int l = i; l < lines.size(); l++){
             if(!isSmall(t[l].etime, stime) && !isSmall(etime, t[l].stime)) {
                 count ++;
             }
        }
        answer = answer < count ? count : answer;
    }

    return answer;
}

int* getStime(int etime[3], int time){
    int *result = new int[3];

    if(etime[2] > time){
        for(int i = 0; i < 2; i++){
            result[i] = etime[i];
        }
        result[2] = etime[2] - time + 1;

    }else{
        if(result[1] != 0){
            result[0] = etime[0];
            result[1] = etime[1] - 1;
        }else{
            result[0] = etime[0]-1;
            result[1] = 59.0;
        }
        result[2] = 60000 - (time - etime[2] - 1);
    }

    return result;
}

bool isSmall(int small[3], int big[3]){
    if(small[0] < big[0])return true;
    else if(small[0] > big[0])return false;

    if(small[1] < big[1]) return true;
    else if(small[1] > big[1])return false;

    if(small[2] < big[2]) return true;
    else if(small[2] >= big[2]) return false;
}

int main(){
    vector<string> lines = {
            "2016-09-15 20:59:57.421 0.351s",
            "2016-09-15 20:59:58.233 1.181s",
            "2016-09-15 20:59:58.299 0.8s",
            "2016-09-15 20:59:58.688 1.041s",
            "2016-09-15 20:59:59.591 1.412s",
            "2016-09-15 21:00:00.464 1.466s",
            "2016-09-15 21:00:00.741 1.581s",
            "2016-09-15 21:00:00.748 2.31s",
            "2016-09-15 21:00:00.966 0.381s",
            "2016-09-15 21:00:02.066 2.62s"
    };

    vector<string> lines1 = {"2016-09-15 01:00:04.001 2.0s","2016-09-15 01:00:07.000 2s"};//{"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"};


    cout<<solution(lines)<<endl;
    return 0;
}
