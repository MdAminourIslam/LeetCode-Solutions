#include <bits/stdc++.h>
using namespace std;

class Router {
private:
    struct Packet {
        int s, d, t;
        Packet(int _s, int _d, int _t) : s(_s), d(_d), t(_t) {}
    };
    
    int memoryLimit;
    deque<Packet> dq;
    set<tuple<int,int,int>> packetSet;

    unordered_map<int, pair<vector<int>, int>> destMap;

public:
    Router(int memoryLimit) : memoryLimit(memoryLimit) {}

    bool addPacket(int s, int d, int t) {
        auto key = make_tuple(s, d, t);
        if (packetSet.count(key)) return false;

        if ((int)dq.size() == memoryLimit) {
            Packet old = dq.front(); dq.pop_front();
            packetSet.erase(make_tuple(old.s, old.d, old.t));
            destMap[old.d].second++; 
        }

        dq.emplace_back(s, d, t);
        packetSet.insert(key);
        destMap[d].first.push_back(t); 

        return true;
    }

    vector<int> forwardPacket() {
        if (dq.empty()) return {};
        Packet pkt = dq.front(); dq.pop_front();
        packetSet.erase(make_tuple(pkt.s, pkt.d, pkt.t));
        destMap[pkt.d].second++; 
        return {pkt.s, pkt.d, pkt.t};
    }

    int getCount(int d, int startTime, int endTime) {
        if (!destMap.count(d)) return 0;
        auto &vec = destMap[d].first;
        int startIdx = destMap[d].second;

        auto it1 = lower_bound(vec.begin() + startIdx, vec.end(), startTime);
        auto it2 = upper_bound(vec.begin() + startIdx, vec.end(), endTime);

        return distance(it1, it2);
    }
};



/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */