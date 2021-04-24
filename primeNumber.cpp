#include <iostream>
#include <vector>
using namespace std;
static inline bool isPn(size_t n, vector<size_t>& pn)
{
	bool div = false;
	for(auto&& x :pn)
	{
		if(n % x == 0)
		{
			div=true;
			break;
		}
	}
	return div;
}
int main(int argc, char *argv[])
{
	vector<size_t> pn;
	size_t n=2;
	while(n < SIZE_MAX)
	{
		if(! isPn(n,pn))
		{
			pn.push_back(n);
			cout << n << endl;
		}
		n++;
	}
	return 0;
}