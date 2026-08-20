struct info {
    int mx, mxcnt, smx, mi, micnt, smi, sum, tag = 0;
    void update(int, int, int);
} tree[MAXN << 2];

int a[MAXN];
// t = 0 chmin, t = 1 chmax, t = 2 add 
void info::update(int t, int val, int len) {
    if (t == 0) {
        if (mx <= val) return;
        sum += (val - mx) * mxcnt;
        if (mi == mx) {
            mi = val;
        } else if (smi == mx) {
            smi = val;
        }
        mx = val;
    } else if (t == 1) {
        if (mi >= val) return;
        sum += (val - mi) * micnt;
        if (mx == mi) {
            mx = val;
        } else if (smx == mi) {
            smx = val;
        }
        mi = val;
    } else {
        sum += val * len;
        mx += val;
        smx = max(-LINF, smx + val);
        mi += val;
        smi = min(LINF, smi + val);
        tag += val;
    }
}

void push(int pos, int l, int r) {
    if (tree[pos].tag) {
        int mid = l + r >> 1;
        tree[lpos].update(2, tree[pos].tag, mid - l + 1);
        tree[rpos].update(2, tree[pos].tag, r - mid);
        tree[pos].tag = 0;
    }

    int v = tree[pos].mx;
    tree[lpos].update(0, v, 0);
    tree[rpos].update(0, v, 0);

    v = tree[pos].mi;
    tree[lpos].update(1, v, 0);
    tree[rpos].update(1, v, 0);
}

void pull(int pos) {
    int smx = (tree[lpos].mx == tree[rpos].mx) ? -LINF : min(tree[lpos].mx, tree[rpos].mx),
       smi = (tree[lpos].mi == tree[rpos].mi) ? LINF : max(tree[lpos].mi, tree[rpos].mi);
    smx = max({smx, tree[lpos].smx, tree[rpos].smx});
    smi = min({smi, tree[lpos].smi, tree[rpos].smi});
    tree[pos] = {
        max(tree[lpos].mx, tree[rpos].mx),
        tree[lpos].mxcnt * (tree[lpos].mx >= tree[rpos].mx) + tree[rpos].mxcnt * (tree[lpos].mx <= tree[rpos].mx),
        smx,
        min(tree[lpos].mi, tree[rpos].mi),
        tree[lpos].micnt * (tree[lpos].mi <= tree[rpos].mi) + tree[rpos].micnt * (tree[lpos].mi >= tree[rpos].mi),
        smi,
        tree[lpos].sum + tree[rpos].sum,
        tree[pos].tag
    };
}

void build(int pos, int l, int r) {
    if (l == r) {
        tree[pos] = {a[l], 1, -LINF, a[l], 1, LINF, a[l], 0};
        return;
    }
    int mid = l + r >> 1;
    build(lpos, l, mid);
    build(rpos, mid + 1, r);
    pull(pos);
}

void mod(int pos, int l, int r, int ml, int mr, int val, int t) {
    if (ml <= l && mr >= r) {
        if ((t == 0 && val > tree[pos].smx) || (t == 1 && val < tree[pos].smi) || t == 2) {
            tree[pos].update(t, val, r - l + 1);
            return;
        }
    }
    push(pos, l, r);
    int mid = l + r >> 1;
    if (ml <= mid) mod(lpos, l, mid, ml, mr, val, t);
    if (mr > mid) mod(rpos, mid + 1, r, ml, mr, val, t);
    pull(pos);
}

int query(int pos, int l, int r, int ql, int qr) {
    if (ql <= l && qr >= r) return tree[pos].sum;
    push(pos, l, r);
    int mid = l + r >> 1;
    int res = 0;
    if (ql <= mid) res += query(lpos, l, mid, ql, qr);
    if (qr > mid) res += query(rpos, mid + 1, r, ql, qr);
    return res;
}