class Solution {
public:
    
    
    /*
    
    UNion find solution
    a==b , c == a, b!=c
    a | c
    -----           if b!=c then is will be false;
    b | a
    */
    
    
    
    
    
    
    
    int uf[26];
    int find(int x) {
        if(x!= uf[x])
            uf[x] = find(uf[x]);
        return uf[x];
    }
    
    bool equationsPossible(vector<string>& equations) {
        
        for(int i =0;i<26;i++)
            uf[i]=i;
        
        for(auto e : equations) {
            if(e[1] == '=')
                uf[find(e[0] - 'a')] = find(e[3]- 'a');
        }
        
        for(auto e : equations) {
            if(e[1] == '!' and (find(e[0]- 'a') == find(e[3] - 'a')))
               return false;
                
        }
               
        return true;
    }
};