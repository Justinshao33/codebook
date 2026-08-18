struct Lichou{
    int m,k;
    Lichou(){}
    Lichou(int a,int b):m(a),k(b){}
    int val(int x) {
        return x*m+k;
    }
};
 
Lichou seg[500005];
 
void build(int l,int r,int ind,Lichou seg1){
    if(l==r) {
        seg[ind]=seg1;
        return;
    }
    int mid=l+r>>1;
    seg[ind]=seg1;
    build(l,mid,ind*2,seg1);build(mid+1,r,ind*2+1,seg1);
}
 
void upd(int l,int r,int ind,Lichou seg1){
    if(l==r) {
        if(seg1.val(l)>seg[ind].val(l)){
            seg[ind]=seg1;
        }
        return;
    }
    int mid=l+r>>1;
    if(seg1.m>seg[ind].m) swap(seg[ind],seg1);
    if(seg1.val(mid)<seg[ind].val(mid)){
        upd(l,mid,ind*2,seg1);
    }
    else {
        upd(mid+1,r,ind*2+1,seg[ind]);
        seg[ind]=seg1;
    }
}
 
int val(int l,int r,int ind,int x){
    if(l==r) return seg[ind].val(x);
    int mid=l+r>>1;
    if(x<=mid) return max(val(l,mid,ind*2,x),seg[ind].val(x));
    else return max(val(mid+1,r,ind*2+1,x),seg[ind].val(x));
}