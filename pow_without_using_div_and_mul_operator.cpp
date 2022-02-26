#include<bits/stdc++.h>
using namespace std;

/*

1) First 5 times add 5, we get 25. (5^2) 
2) Then 5 times add 25, we get 125. (5^3) 
3) Then 5 times add 125, we get 625 (5^4) 
4) Then 5 times add 625, we get 3125 (5^5) 
5) Then 5 times add 3125, we get 15625 (5^6) 


#include <iostream>
using namespace std;
 
int pow(int a, int b)
{
    if (b == 0) {
        return 1;
    }
 
    int result = 0;
    int power = pow(a, b - 1);
 
    for (int i = 0; i < a; i++) {
        result += power;
    }
 
    return result;
}
 
int main()
{
    cout << pow(7, 3);
    return 0;
}
*/
/* A recursive function to get x*y */
int multiply(int x, int y)
{
	if(y)
		return (x + multiply(x, y - 1));
	else
		return 0;
}

/* A recursive function to get a^b
Works only if a >= 0 and b >= 0 */
int pow(int a, int b)
{
	if(b)
		return multiply(a, pow(a, b - 1));
	else
		return 1;
}

// Driver Code
int main()
{
	cout << pow(5, 3);
	getchar();
	return 0;
}

// This code is contributed
// by Akanksha Rai
