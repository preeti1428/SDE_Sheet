int Solution::compareVersion(string A, string B) {
    
    vector<string>aa;
    vector<string>bb;
    
    int i=0;
    
    while(i<A.size()){
        string a ="";
        
        while(A[i]=='0'){i++;}
        
        while(A[i]!='.' && i<A.size()){
        a+=A[i];
        i++;
        }
        
        aa.push_back(a);
        
        i++;
        
    }
    
    int j=0;
    
    while(j<B.size()){
        string b = "";
        
        while(B[j]=='0'){j++;}
        
        while(B[j]!='.' && j<B.size()){
        b+=B[j];
        j++;
        }
        
        bb.push_back(b);
        
        j++;
    }
    
    int maxsize = max(aa.size(), bb.size());
    
    aa.resize(maxsize);
    bb.resize(maxsize);
    
    
    for(int i=0; i<maxsize;i++){
        if(aa[i].size()>bb[i].size()) return 1;
        else if(aa[i].size()<bb[i].size()) return -1;
        else{
            if(aa[i]>bb[i]) return 1;
            else if(aa[i]<bb[i]) return -1;
        }
        
    }
   
    return 0;
}
