typedef struct data
{
    data* bit[26];
    int cnt = 0;
}trie;

trie* head;

void insert(string &s)
{
    trie* cur = head;
    for(auto &it:s)
    {
        int b = it - 'A';
        if(!cur->bit[b])
            cur->bit[b] = new trie();
        cur = cur->bit[b];
        cur->cnt++;
    }
}

int n, k;
string s[N];

int query(trie* cur, int lvl)
{
    if(!cur)
        return 0;
    int ans = (cur -> cnt / k);
    for(int i = 0; i <= 25; i++)
        if(cur -> bit[i])
            ans += query(cur -> bit[i], lvl + 1);
    return ans;
}

// implemented during kickstart 2020 round A
// https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ffc7/00000000001d3ff3
// inside main function
// head = new trie();
// for(int i = 1; i <= n; i++)
// {
//     cin >> s[i];
//     insert(s[i]);
// }
// int ans = query(head, 0);
