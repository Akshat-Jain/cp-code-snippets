/**** [ AkJn ] ****/
#include <bits/stdc++.h>
using namespace std;
 
#define fastIO ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define ld long double
#define ll long long
#define input(a,n) for(ll i=0;i<n;i++)cin>>a[i]
#define output(a,n) for(ll i=0;i<n;i++)cout<<a[i]<<" "
#define min3(a, b, c) min(a,min(b, c))
#define min4(a, b, c, d) min(a, min(b, min(c, d)))
#define max3(a, b, c) max(a,max(b, c))
#define max4(a, b, c, d) max(a, max(b, max(c, d)))
#define fr(i,a,n) for(ll i=a; i<n; i++)
#define fre(i,a,n) for(ll i=a; i<=n; i++)
#define yay(x) cout<<endl<<"yay"<<x<<endl;
#define debug(a) do { std::cout << "Value of " << #a << " is: " << (a) << '\n'; } while(false);
#define dbg(a) do { std::cout << "Value of " << #a << " is: " << (a) << '\n'; } while(false);
const ll mod = 1000000007;
const ll INF = 1000010;
// LLONG_MAX, LLONG_MIN
 
/* CHECK THESE POINTS BEFORE SUBMITTING
 * Read the question carefully.
 * Read the code once before final submission.
 * Check the extremities of the constraints.
 * Always check if Binary Search can be applied.
 * 0 is better than -1.
*/
 
void printVector(vector<ll int> v){
    cout << "Printing vector:\n";
    for (ll int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// void printArray(ll int a[], ll int n){
//     cout << "Printing array:\n";
//     for (ll int i = 0; i < n; ++i)
//     {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }

// void printArray(int a[], int n){
//     cout << "Printing array:\n";
//     for (ll int i = 0; i < n; ++i)
//     {
//         cout << a[i] << " ";
//     }
//     cout << endl;
// }
 
// void printSolution(ll int V)  
// {  
//     cout<<"The following matrix shows the shortest distances"
//             " between every pair of vertices \n";  
//     for (int i = 0; i < V; i++)  
//     {  
//         for (int j = 0; j < V; j++)  
//         {
//                 cout<<dist[i][j]<<"  ";  
//         }  
//         cout<<endl;  
//     }  
// }
 
// bool isPrime(ll int n) 
// {
//     if (n <= 1) return false; 
//     if (n <= 3) return true; 

//     if (n%2 == 0 || n%3 == 0) return false; 
  
//     for (ll int i=5; i*i<=n; i=i+6) 
//         if (n%i == 0 || n%(i+2) == 0) 
//            return false;

//     return true; 
// }

int find_set(int a, int parent[]){
    if(a == parent[a]){
        return a;
    }
    return parent[a] = find_set(parent[a],parent);
}

void union_sets(int a, int b, int parent[], int rank[]){
    a = find_set(a, parent);
    b = find_set(b, parent);
    if(a!=b){
        if(rank[a]<rank[b]){
            swap(a,b);
        }
        parent[b] = a;
        if(rank[a] == rank[b]){
            rank[a]++;
        }
    }
}

int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    fastIO
    ll int n;
    cout << "Number of nodes: ";
    cin>>n;
    cout << "Number of edges: ";
    ll int e;
    cin>>e;
    int parent[n+1];
    int rank[n+1];
    bool used[n+1];
    for (int i = 0; i < n+1; ++i)
    {
        parent[i] = i;
        rank[i] = 0;
        used[i] = false;
    }
    for (int i = 0; i < e; ++i)
    {
        ll int a,b;
        cin>>a>>b;
        union_sets(a,b,parent,rank);
    }

    cout << "Parent array is: " << endl;
    for (int i = 1; i < n+1; ++i)
    {
        cout << parent[i] << " ";
    }

    ll int count=0;
    for (int i = 1; i < n+1; ++i)
    {
        int x = find_set(i,parent);
        if(!used[x]){
            used[x] = true;
            count++;
        }
    }
    cout << "Parent array is: " << endl;
    for (int i = 1; i < n+1; ++i)
    {
        cout << parent[i] << " ";
    }
    cout << endl;
    dbg(count);


}
 
 
 
 
// Driver function to sort the vector elements 
// by second element of pairs 
// bool sortbysec(const pair<int,int> &a, 
//               const pair<int,int> &b) 
// { 
//     return (a.second < b.second); 
// }
 
 
// Driver function to sort the vector elements by  
// first element of pair in descending order 
// bool sortinrev(const pair<int,int> &a,  
//                const pair<int,int> &b) 
// { 
//        return (a.first > b.first); 
// }
 
// ll int gcd(ll int a, ll int b)  
//  {  
//     // Everything divides 0  
//     if (a == 0 || b == 0)  
//         return 0;  
   
//     // Base case     
//     if (a == b)  
//         return a;  
   
//     // a is greater  
//     if (a > b)  
//         return gcd(a-b, b);  
//     return gcd(a, b-a);  
//  }
 
// bool isVowel(char ch)
// {
//  if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//      return 1;
//  return 0;
// }
 
// int countVowels(string &s)
// {
//  int cnt = 0;
//  for(int i = 0; i < s.size(); i++)
//      if(isVowel(s[i]))
//          cnt++;
//  return cnt;
// }