#include<vector>
using namespace std;

void dfs(int i,vector<int>& edges,vector<bool>& vis,vector<int>& path,int dis = 0){
    int ngb = edges[i];
    path[i] = dis;
    dis++;
    vis[i] = true;
    if(ngb == -1 || vis[ngb]) return;
    dfs(ngb,edges,vis,path,dis+1);
}
int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<bool>vis1(edges.size(),false),vis2(edges.size(),false);
        vector<int>path1(edges.size(),1e6),path2(edges.size(),1e6);
        dfs(node1,edges,vis1,path1);
        dfs(node2,edges,vis2,path2);
        int dist = 1e6;
        int ans = -1;
        for(int i = 0;i<edges.size();i++){
            //cout<<path1[i]<<" "<<path2[i]<<endl;
            if(path1[i] == 1e6 || path2[i] == 1e6) continue;
            if(max(path1[i],path2[i]) < dist){
                ans = i;
                dist = max(path1[i],path2[i]);
            }
        }
        return ans;
}