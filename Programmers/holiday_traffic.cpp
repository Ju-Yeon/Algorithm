#include <iostream>
#include <string>
#include <vector>

using namespace std;
int solution(vector<string> lines);
double* getStime(double etime[3], double time);
bool isSmall(double small[3], double big[3]);

struct transaction {
    double * stime;
    double * etime;
};

//2016-09-15 21:00:02.066 2.62s
int solution(vector<string> lines) {
    int answer = 0;
    transaction * t = new transaction[lines.size()];

    for(int i = 0; i < lines.size(); i++){
        t[i].stime = new double[3];
        t[i].etime = new double[3];

        for(int l = 0; l < 2; l++)
            t[i].etime[l] = atof(lines[i].substr(11 + 3 * l, 2).c_str());
        t[i].etime[2] = atof(lines[i].substr(17, 6).c_str());
        t[i].stime = getStime(t[i].etime, atof(lines[i].substr(24, lines[i].find("s")-24).c_str()));
    }

    double *stime = new double[3];
    double *etime = new double[3];
    int count = 0;

    for(int i = 0; i < lines.size(); i++){
        count = 0;
        stime = t[i].etime;
        etime = t[i].etime;
        etime[2] += 1.000;

        for(int l = i; l < lines.size(); l++){
             if(!isSmall(t[l].etime, stime) && !isSmall(etime, t[l].stime)) {
                 count ++;
                 cout<<i<<" "<<l<<endl;
             }
        }
        answer = answer < count ? count : answer;
    }

    return answer;
}

double* getStime(double etime[3], double time){
    double *result = new double[3];
    double flag = 0.0;

    if(etime[2] > time){
        for(int i = 0; i < 2; i++){
            result[i] = etime[i];
        }
        result[2] = etime[2] - time + 0.001;

    }else{
        if(result[1] != 0){
            result[0] = etime[0];
            result[1] = etime[1] - 1;
        }else{
            result[0] = etime[0]-1;
            result[1] = 59.0;
        }
        result[2] = 60 - (time - etime[2] - 0.001);
    }

    return result;
}

bool isSmall(double small[3], double big[3]){
    for(int i = 0; i<2; i++){
        if(small[i] > big[i]) return false;
    }
    if(small[2] >= big[2]) return false;
    else return true;
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

    cout<<solution(lines)<<endl;
    return 0;
}
