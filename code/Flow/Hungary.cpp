const int N = 505, M = 505;
struct mat{
    int a[N][M];
    int vis[M], match[M] = {0};
    int n, m;
    void init(int _n, int _m){
        n = _n;
        m = _m;
        for(int i = 1; i <= m; i++){
            match[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                a[i][j] = 0;
            }
        }
    }
    bool dfs(int now){
        for(int i = 1; i <= m; i++){
            if(a[now][i] && !vis[i]){
                vis[i] = 1;
                if(!match[i] || dfs(match[i])){
                    match[i] = now;
                    return 1;
                }
            }
        }
        return  0;
    }
    int solve(){
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++) vis[j] = 0;
            if(dfs(i)){
                ans++;
            }
        }
        return ans;
    }
}iu;