class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int &e:students) q.push(e);
        int e=0;
        int f=0;
        while(f<q.size()){
            if(q.front()==sandwiches[e]){
                q.pop();
                e++;
                f=0;
            }else{
                int num=q.front();
                q.pop();
                q.push(num);
                f++;
            }
        }
        return sandwiches.size()-e;
    }
};