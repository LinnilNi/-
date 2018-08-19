/*（约瑟夫问题）有n个人围坐在圆桌周围，每个人都有一个固定的编号。
从第s（≤n）个人开始报数（按顺时针方向，从1开始），报到m的人出列（离开），
接着再从出列者的下一个人开始报数（仍然从1开始），报到m的人又出列……依此重复进行，
直至所有的人都出列。对任意给定的n、s和m，按出列的先后顺序输出每个出列者的编号。
*/

#include<iosraem>
#include<vector>
using namespace std;

template<typename T>
void josephu(int s, int m, vector<T> &v1, vector<T> &v2){
	vector<T>::iterator iter1 = v1.begin(), iter2 = v2.end();
	//找第一个报数者
	for(int i = 1; i < s; i++, iter1++)
		if(iter1 == v1.end())
			iter1 = v1.begin();
	while(!v1.empty()){
		for(i = 1; i < m; i++)
			if(++iter1 == v1.end())
				iter1 = v1.begin();
		v2.insert(iter2++, *iter1);//插入向量v2中
		v1.erase(iter1);//在v1中删除出列者
		//若出列者是最后一个元素，则求下一个出列者时，从第一个元素开始报数
		if(iter1 == v1.end())
			iter1 = v1.begin();
	}
}


void main(){
	vector<int> L, M;
	int n, val, s, m;
	cout<<"请输入人数n：";
	cin>>n;
	L.reserve(n);
	M.reserve(n);
	cout<<"输入"<<n<<"个元素，用空格隔开，最后以'enter'键结束：\n";
	for(int i = 0; i < n; i++){
		cin>>val;
		L.push_back(val);
	}
	cout<<"输入起始位置和报数值s,m：";
	cin>>s>>
	josephu(s, m, L, M);
	cout<<"\n列出顺序："<<endl;
	vector<int>::const_iterator veciter = M.begin();
	while(veciter != M.end())
		cout<<*veciter++<<'';
}