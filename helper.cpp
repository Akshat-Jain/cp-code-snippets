// (a^b) % mod
ll pow(ll a, ll b, ll m=mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1)
            ans=(ans*a)%m;
        b/=2;
        a=(a*a)%m;
    }
    return ans;
}
 
ll modinv(ll k)
{
    return pow(k, mod - 2, mod);
}

// gcd
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

// (a*b) % mod
ll moduloMultiplication(ll a, ll b) 
{
    return ((a%mod)*(b%mod))%mod;
}

