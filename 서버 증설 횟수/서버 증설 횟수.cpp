// 프로그래머스 서버 증설 횟수
/*
    문제의 핵심은 켜저있어야할 서버 수 와 현재 켜저있느 서버 수 
    그리고 가장 중요한건 삭제 될 타이밍을 어떻게 관리할까. 였던 것 같다.

    서버가 꺼저야 할 시간을 배열로 하나 만들어서 사용하면 for문을 한번 적게 사용해도되서 배열로 사용했는데... 점수를 보아하니 문제의 출제의도는 for문을 사용하길 바랬던 것 같다.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//players 시간별 유저수 , m 증설하게 될 인원수 , k 서버를 가동시 운영되는 시간
int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int activeServer = 0;
    vector<int> closeServer(players.size(), 0);

    for (int i= 0; i<players.size(); i++)
    {
        int requiredServer = players[i] / m;

        //필요 서버 수 와 현재 켜진 서버 수 비교
        if (requiredServer > activeServer)
        {
            int added_Server = requiredServer - activeServer;
            activeServer += added_Server; //필요 서버 수 만큼 서버 키기
            if (i + k - 1 < players.size()) {
                closeServer[i + k - 1] += added_Server; // 인덱스가 벗어나지 않도록
            }
            answer += added_Server;
        }

        if (closeServer[i] != 0)
        {
            activeServer -= closeServer[i];
        }

    }


    return answer;
}

int main()
{
    vector<int> player = { 0, 0, 0, 10, 0, 12, 0, 15, 0, 1, 0, 1, 0, 0, 0, 5, 0, 0, 11, 0, 8, 0, 0, 0 };

    int m = 5;
    int k = 1;
    cout << solution(player, m, k) << endl;
    
    system("pause");
}
