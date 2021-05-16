#include<vector>
#include<iostream>
using namespace std;

int main() {
	//we must declare functions before using them
	void init_vector(vector <int> &vecTest);
	void show_vector(vector <int> &vecTest);
	void insert_array_to_vector(vector<int> &vecTest,
				    int a[],int length);

	vector<int> vec;
	init_vector(vec);
	show_vector(vec);

	int a[] = {12,29,83};
	insert_array_to_vector(vec,a,sizeof(a)/sizeof(a[0]));
	//vec.insert(vec.begin()+3,100);
	show_vector(vec);

	return 0;
}


//initializa vector
void init_vector(vector <int> &vecTest){
	for(int i=0;i<10;i++) {
		vecTest.push_back(i);
	}
}

//show all contents of vector
void show_vector(vector <int> &vecTest){
	vector<int>::iterator it = vecTest.begin();
	while(it<vecTest.end()){
		cout<<*it<<' ';
		it++;
	}
	cout<<endl;
}

//insert array into vector
void insert_array_to_vector(vector<int> &vecTest,int a[],int length){
	for (register int i=0;i<length;++i)
		vecTest.push_back(a[i]);
}
