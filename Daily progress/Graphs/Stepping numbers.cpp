/*
Given A and B you have to find all stepping numbers in range A to B.

The stepping number:

A number is called as a stepping number if the adjacent digits have a difference of 1.

e.g. 123 is stepping number, but 358 is not a stepping number
*/


//CAN BE DONE WITH SIMPLE VECTOR
//CAN BE DONE WITH DP
//CAN BE DONE WITH BFS

bool isstep(int num){
    if(num==0) return true;
    
    int digits = 0;
    int p = num;
    
    while(p!=0){
        digits++;
        p = p/10;
    }
    
    int iter = digits-1;
   while(iter--){
       int d = num%10;
       num = num/10;
       
       if(abs(d-num%10)!=1)
       return false;
   }
    return true;
}
vector<int> Solution::stepnum(int A, int B) {
    vector<int>ans;
    
    
    for(int i=A; i<=B;i++){
        if(isstep(i))
        ans.push_back(i);
    }
    return ans;
    
}
