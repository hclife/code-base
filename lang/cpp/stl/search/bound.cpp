// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <algorithm>    // std::lower_bound, std::upper_bound, std::sort
#include <vector>       // std::vector

int main () {
	int myints[] = {10,20,30,30,20,10,10,20};
	std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20
	std::sort (v.begin(), v.end());                // 10 10 10 20 20 20 30 30

	while (true) {
		int val;std::cin>>val;
		std::vector<int>::iterator low,up;
		low=std::lower_bound (v.begin(), v.end(), val);
		up=std::upper_bound (v.begin(), v.end(), val);
		std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
		std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
	}

#if 0
	while (1) {
		u64 x;cin>>x;
		vector<u64>::iterator low,up;
		low=lower_bound(v.begin(),v.end(),x);
		up=upper_bound(v.begin(),v.end(),x);
		cout<<"low:"<<*low<<' '<<(low-v.begin())<<endl;
		cout<<" up:"<<*up<<' '<<(up-v.begin())<<endl;
	}
#endif
	return 0;
}
