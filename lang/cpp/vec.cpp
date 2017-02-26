//vector 是C++中最常用的容器类
#include<vector>
#include<iostream>
using namespace std;

int main(){
	//注意：在使用函数之前，一定要申明！
	void init_vector(vector <int> &vecTest);
	void show_vector(vector <int> &vecTest);
	void insert_array_to_vector(vector<int> &vecTest,
				    int a[],int length);

	//申明一个vector
	vector<int> vec;
	//初始化vector
	init_vector(vec);
	//显示vector
	show_vector(vec);
	//向vector中插入一个数组
	int a[] = {12,29,83};
	insert_array_to_vector(vec,a,sizeof(a)/sizeof(a[0]));
	//vec.insert(vec.begin()+3,100);
	show_vector(vec);

	return 0;
}


/*初始化容器*/
void init_vector(vector <int> &vecTest){
	for(int i=0;i<10;i++)
		//push_back()方法在vector的末尾附加元素  
		vecTest.push_back(i);
	/*
	   vector<int>::iterator it = vecTest.begin();  
	//it是地址
	while(it<vecTest.end()){
	cout<<*it<<endl;  
	it++; 
	}*/
}

/* 显示容器中的所有数据*/
void show_vector(vector <int> &vecTest){
	vector<int>::iterator it = vecTest.begin();
	//it 是一个地址
	while(it<vecTest.end()){
		cout<<*it<<' ';
		it++;
	}
	cout<<endl;
}

/*向容器中插入一个数组*/
void insert_array_to_vector(vector<int> &vecTest,int a[],int length){
	for (register int i=0;i<length;++i)
		vecTest.push_back(a[i]);
}
