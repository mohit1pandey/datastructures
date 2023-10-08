// find the winner
// if votes are same so return shortest string
#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class umap{
 unordered_map<string,int>map;
 vector<string>show;  
public:

void winner(string arr[],int n){

  for (int i=0;i<n;i++){
   string key=arr[i];
   map[key]++;
  }
   
   int max_vote=0;
   string name="";


  for(auto it=map.begin();it!=map.end();it++){
   
    if(it->second > max_vote){
     max_vote= it->second;
     name=it->first; 
    }
    else if(it->second == max_vote){

     if(it->first < name)   // current cnditate  name is smaller
     name= it->first;

    }

 }
    show.push_back(name);
   string temp= to_string(max_vote);
   show.push_back(temp);

}

void show_winner(){
    for(auto it:show){
        cout<<it<<" ";
    }
}

};



int main(){
  string candidate[10]={"mohit","rink","tiwari","rink","jagga","rink","tiwari","tara","tiwari","tiwari"}; 
  
  umap m1;
  m1.winner(candidate,10);
  m1.show_winner();
    return 0;
}
