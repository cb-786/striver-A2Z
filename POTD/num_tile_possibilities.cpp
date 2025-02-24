void rec(string &tiles,int i,string &sub,set<string> &st) {
    if(i>=tiles.size()) {
       if(!sub.empty()) {
           st.insert(sub);
       }
             
             return ;
    }
   
   rec(tiles,i+1,sub,st);
   sub.push_back(tiles[i]);
   rec(tiles,i+1,sub,st);
   sub.pop_back();
   

   return ;

}


void permute(string &s, int l, int r, vector<string> &result) {
if (l == r) {  
result.push_back(s);  
return;
}

for (int i = l; i <= r; i++) {
swap(s[l], s[i]);    
permute(s, l + 1, r, result);  
swap(s[l], s[i]);      
}
}



int numTilePossibilities(string tiles) {
set<string> st;
vector<string> res;
string sub;
permute(tiles,0,tiles.size()-1,res);
for(int i=0;i<res.size();i++) {
         rec(res[i],0,sub,st);
}

return st.size();
}