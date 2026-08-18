vector<int>ans;

int nxt[1000005];
void init(string a){
    nxt[0]=0;
    int iu=0;
    for(int i=1;i<a.size();i++){
        while(iu&&a[iu]!=a[i]) iu=nxt[iu-1];
        if(a[iu]==a[i]) iu++;
        nxt[i]=iu;
    }
}

void kmp(string a, string ser){
    int iu=-1;
    for(int i=0;i<ser.size();i++){
        while(iu&&a[iu]!=ser[i]) iu=nxt[iu-1];
        if(a[iu]==ser[i]) iu++;
        if(iu==a.size()) ans.pb(i), iu=nxt[iu];
    }
}