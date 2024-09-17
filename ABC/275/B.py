a,b,c,d,e,f = map(int, input().split())
MOD = 998244353
print(((a *b*c)% MOD -(d * e * f) % MOD) % MOD)
