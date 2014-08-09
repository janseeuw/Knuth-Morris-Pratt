#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <vector>
#include <queue>

using namespace std;

vector<int> prefixfunction(const string &p){
	int m = p.size();
	vector<int> a(m);
	a[0]=0;
	int k=0;
	for(int q=1; q<m; q++){
		while(k>0 && p[k] != p[q]){
			k = a[k];
		}
		if(p[k] == p[q]){
			k = k + 1;
		}
		a[q]=k;
	}
	return a;
}

void SimpleLinear(const string &p, const string &t){
	int m = p.size();
	int n = t.size();
	
	vector<int> prefix = prefixfunction(p);
	int j=0;
	for (int i = m; i < n; i++) {
    	while (j > 0 && p[j] != t[i])
			j = prefix[j-1];
		if (t[i] == p[j])
			j++;
		if (j == m)
			cout<<"Match at index"<<i - 1 * m;
	}
}

int main(int argc, char *argv[]) {
	string text = "gcatcgcagagagtatacagtacg";
	string pattern = "gagag";
	SimpleLinear(pattern, text);
	
	
	return 0;
}