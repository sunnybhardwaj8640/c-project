#include <iostream>
using namespace std;

int main()

 {
//     int num, orn, rem=0;
//     cout<<"enter the number";
//     cin>>num;
//     orn=num;
//     while(num!=0){
//         rem =rem*10 +num%10;
//         num/=10;
//     }
//     if(orn==num){
//         cout<<"palidrome";
//     }
//     else{
//         cout<<"not paldrome";
//     }



//     int year;
//     cout<<"enter the year";
//     cin>>year;
// if((year%4==0 && year%100!=0) || (year%400==0)){
//     cout<<"leap year";
// }
// else{
//     cout<<"not leap year";  
// }




// int num, sum=0;
// cout<<"Enter the number :";
// cin>>num;

// while(num!=0){
//     sum +=num%10;
//     num/=10;
// }
// cout<<"The Digits of Number is "<<sum;




// int a=1;
// while (a<=500)
// {
//     if(a%2!=0){
//         cout<<a<<endl;
//     }
//     a++;
// }

// int num;
// cout<<"Enter the Number :";
// cin>>num;
// for(int i=1; i<num; i++){
//     cout<<num<<"x"<<i<<"="<<(num*i)<<endl;
// }




// int num, number=1;
// cout<<"enter the number";
// cin>>num;
// for(int i=1; i<=number; i++){
//     i *= num;
// }
// cout<<num;






// int num;
// cout<<"enter the number";
// cin>>num;

// if(num>0){
//     cout<<"postive number";
// }
// else if(num<0){
//     cout<<"nagavtive number";
// }
// else{
//     cout<<"zero number";
// }


// int num1 ,num2;
// cout<<"enter the first num";
// cin>>num1;
// cout<<"enter the second num";
// cin>>num2;
//  int max_num = (num1>num2)? num1:num2;
//  int min_num = (num1< num2)? num1:num2;
//  cout<<"The maximum number is :"<<max_num;
//  cout<<"The manimum number is :"<<min_num;



// print sum of even number 1 to n;
// int n, sum=0;
// cout<<"enter the  postive number";
// cin>>n;
// if(n<=0){
//     cout<<"please enter the postive number"<<endl;

//     return 1;
// }
// for(int i=2; i<=n; i+=2){ //for loop of sum even number
//     sum +=i;
// }
// cout<<"this number postive"<<n<<"is"<<sum<<endl;


// print the calcualte all natural nmber
// int n, sum=0;
// cout<<"enter the natural numbers";
// cin>>n;
// if(n<=0){
//     cout<<"enter the postive natural number";
//     return 1;
// }
// sum =(n*(n+1))/2; //formula to calcualte the natural number
// cout<<"this natural"<<n<<sum<<endl;






//print 1 to 100 which is divide by 5

// for(int i=1; i<=100; i++){
//     if(i%5==0){
//         cout<<i<<endl;
//     }
// }



//Print the sum of squares of the first n natural numbers
//  int n, sum=0;
//  cout<<"enter the number :";
//  cin>>n;
//  for(int i=1; i<=n; i++){
//     sum +=i*i;
//  }
//  cout<<"The square of first " <<n<<"Natural number : "<<sum;


//equilateral, isosceles, or scalene
int side1, side2, side3;
cout<<"Enter the First Side :";
cin>>side1;
cout<<"Enter the Second Side :";
cin>>side2;
cout<<"Enter the Third Side :";
cin>>side3;
if(side1 == side2 && side2== side3){
   cout<<"It is equilateral tirangle";
}
else if((side1 == side2 && side2== side3) || (side1==side3)){
   cout<<"isosceles";
}
else{
   cout<<"scalene";
}
    return 0;
 }