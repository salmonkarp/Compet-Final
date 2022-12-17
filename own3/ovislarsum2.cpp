#include <bits/stdc++.h>
#define LL long long

using namespace std;
LL MOD = 1000000007;
LL mod = 0;

LL fast_exponent(LL base, LL pangkat)
{
	if(pangkat==0)
		return 1;
	else if(pangkat ==1)
		return base%MOD;
	else
	{
		LL hasil = fast_exponent(base, pangkat/2);
		hasil = (hasil%MOD * hasil%MOD) % MOD;
	
		if(pangkat & 1) //jika ganjil
			hasil = (hasil%MOD * base%MOD) % MOD;
	
		return hasil % MOD;
	}
}

LL mod_kurang(LL a, LL b)
{
	a = a % MOD;
	b = b % MOD;
	LL temp = (a - b) % MOD;
	if(temp<0)
		temp = (temp + MOD) % MOD;
	return temp;
}

LL mod_div(LL top, LL bottom)
{
	LL new_top = top % MOD;
	LL new_bottom = fast_exponent(bottom,MOD-2) % MOD;
	return (new_bottom%MOD * new_top%MOD) % MOD;
}

LL calc(LL r)
{
	//SATU PUTARAN
	LL temp1 = ( ((mod-1)%MOD) * (mod%MOD) ) % MOD;
	LL sum_of_cycle = mod_div(temp1,2);

	//JUMLAH PUTARAN
	LL no_of_cycle = r/mod;
	// cout << "no of cycle " << no_of_cycle << endl;

	LL nos_left = r % mod;
	LL temp2 = ((nos_left%MOD) * (nos_left%MOD + 1)) % MOD ;
	LL sum_of_left = mod_div(temp2,2);

	LL right_answer = (((sum_of_cycle%MOD) * (no_of_cycle%MOD)) % MOD + sum_of_left) % MOD;
	// cout << right_answer << endl;
	return right_answer;
}

int main()
{
	LL l,r;
	scanf("%lld %lld %lld",&l,&r,&mod);
	
	LL final_ans = mod_kurang(calc(r), calc(l-1) );
	printf("%lld\n",final_ans);
}