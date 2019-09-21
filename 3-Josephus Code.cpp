#include <iostream>
using namespace std;

int t=0;
int josephus(int n, int k) 
{ 
  if (n == 1) 
    return 1; 
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the 
       recursive call josephus(n - 1, k) considers the original position  
       k%n + 1 as position 1 */
    t=(josephus(n - 1, k) + k-1) % n + 1;
    // cout<<n<<" "<<k<<" "<<t<<endl;
    return t; 
}
int main() 
{ 
  int n = 4; 
  int k = 3; 
  cout<<"The chosen place is "<<josephus(n, k); 
  return 0; 
} 
