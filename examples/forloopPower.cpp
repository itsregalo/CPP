#include <iostream>
using namespace std;

/*the following code returns a product of a number
entered by the user*/

int main(){
    int num1, num2, answer=1;

    cout<<"Enter the numbers\n";
    cin>>num1>>num2;

    for(int n=1; n<=num2; n++){
        answer=answer*num1;
        cout<<answer<<endl;
    }
    return 0;
}