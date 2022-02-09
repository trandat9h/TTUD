/* COde by https://duongdinh24.com/ 
   Github: https://github.com/duongdinh24/
*/
#include<iostream>
#include<string>  // Thu vi?n x? lý xâu
using namespace std;

void longest_Common(string a, string b){  // Hàm tìm xâu con l?n nh?t và in ra màn hình
    int n = a.size();  // n chi?u dài xâu a, m chi?u dài xâu b
    int m = b.size();
    int max_Size;     // Bi?n luu d? dài con chung l?n nh?t
    string subsequence = "";  // Bi?n luu con chung dùng khi truy v?t
    int L[n+1][m+1];   // Khai báo m?ng luu k?t qu?:  n+1 hàng, m+1 c?t
    
    for(int i=0; i<=n; i++)   // Gán c?t d?u tiên b?ng 0
        L[i][0] = 0;
    for(int j=0; j<=m; j++)   // Gán hàng d?u tiên = 0
        L[0][j] = 0;
        
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            if(a[i-1] == b[j-1]){  // N?u có ph?n t? b?ng nhau
                L[i][j] = L[i-1][j-1] + 1;   // Áp d?ng công th?c
            }
            else{   // Tru?ng h?p a[i-1] khác b[j-1]
                if(L[i-1][j] >= L[i][j-1])     // Tìm max gi?a L[i-1][j] và L[i][j-1]
                    L[i][j] = L[i-1][j];
                else
                    L[i][j] = L[i][j-1];
            }
        }
    }
    
    max_Size = L[n][m];  // Tìm du?c d? dài con l?n nh?t
    int i = n; 
    int j = m;
    while(L[i][j] != 0){ // Ði?u ki?n d?ng
        if(a[i-1] == b[j-1]){  // N?u b?ng nhau
            subsequence += a[i-1];   // C?ng a[i-1] vào xâu con
            i--;
            j--;
        }
        else{  // N?u khác nhau
            if(L[i-1][j] >= L[i][j-1]) // So sánh
                i--;
            else
                j--;
        }
    }
    
    cout<<"\nDo dai xau lon nhat: "<<max_Size;  // In ra d? dài con l?n nh?t
    cout<<"\nXau con: ";
    for(int t = max_Size-1 ; t>=0; t--)  // In ngu?c t? cu?i v? d?u d? xâu con dúng th? t?
        cout<<subsequence[t];
}
int main(){
    string a, b;
    cout<<"Nhap xau a: "; cin>>a;
    cout<<"Nhap xau b: "; cin>>b;
    longest_Common(a,b);
    return 0;    
}
