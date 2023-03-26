#include <iostream>
#include <cstring>
#include <fstream>
 
using namespace std;
 
int n,c, a[10][10],sm=0,m[10];
 
void docfile(){ //Dung de doc file, sau do gan vao mang a[][]
    int q,p;
    ifstream dothi ("C:\\Users\\Administrator\\Desktop\\dothi.txt");
    if (dothi.is_open())
    {
        dothi >> n;
        dothi >> c;
        while (!dothi.eof()) //Doc file cho den cuoi file
        {
            dothi >> q;
            dothi >> p;
            a[q][p]=1;
            a[p][q]=1;
        }
        dothi.close();
    }
    else cout << "Khong mo duoc file";
}
 
void xuly(){ //Xu ly de cho ra ket qua vao mang m[]
    int kt;
    for(int i=1;i<=n;i++)
        if(!m[i]) {
            sm++; //Dem so mau
            m[i]=sm;
            for(int j=i+1;j<=n;j++) //Kiem tra xem nhung dinh nao co the gan bang mau sm nua khong
                if((a[i][j]==0)&&(m[j]==0)){
                    kt=1;
                    for(int k=i+1;k<j;k++)
                        if((a[k][j]==1)&&(m[i]==m[k])){
                            kt=0;
                            break;
                        }
                    if(kt==1) m[j]=sm;
                }                   
        }
}
void xuatkq(){ //In ket qua ra man hinh
    ofstream myfile;
	myfile.open("C:\\Users\\Administrator\\Desktop\\to_mau.txt");
	myfile<<"graph dothi\n";
	myfile<<"{\n";
	for(int j=1;j<=n;j++){
		for(int i=1;i<=sm;i++)
		if(m[j]==i){
		string tr;
	    switch(i){
		case 1: tr="green"; break;
		case 2: tr="red"; break;
		case 3: tr="blue"; break;
		case 4: tr="yellow"; break;
		case 5: tr="black"; break;
		case 6: tr="white"; break;
		case 7: tr="silver"; break;
		case 8: tr="purple"; break;
		case 9: tr="gray"; break;
		case 10: tr="navy"; break;
	}
		myfile<<j<<"["<<"fillcolor="<<tr<<", style=filled"<<"]"<<";"<<endl;
	}
	}
	int q,p;
    ifstream dothi ("C:\\Users\\Administrator\\Desktop\\dothi.txt");
    if (dothi.is_open())
    {
        dothi >> n;
        dothi >> c;
        while (!dothi.eof()) //Doc file cho den cuoi file
        {
            dothi >> q;
            dothi >> p;
            myfile<<q<<"--"<<p<<";"<<endl;
        }
        dothi.close();
    }
    else cout << "Khong mo duoc file";
    myfile<<"}";
	myfile.close();	
}
int main(){
    docfile();
    xuly();
    xuatkq();
    return 0;
}
