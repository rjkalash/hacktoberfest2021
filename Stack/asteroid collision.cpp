class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n=asteroids.size();
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            if(s.empty())
                s.push(asteroids[i]);
            else 
            {
                if(asteroids[i]<0)
                {
                   while(!s.empty() && abs(asteroids[i]-0)>abs(s.top()-0) && s.top()>0)
                       s.pop();
                    if(!s.empty() && abs(asteroids[i]-0)==abs(s.top()-0) && s.top()>0)
                        s.pop();
                    else if(!s.empty() && abs(asteroids[i]-0)<abs(s.top()-0) && s.top()>0)  
                        continue;
                    else 
                        s.push(asteroids[i]);
                }
                else 
                    s.push(asteroids[i]);           
                
            }
        }
        vector<int> vect;
        while(!s.empty())
            vect.push_back(s.top()),s.pop();
        reverse(vect.begin(),vect.end());
        return vect;
        
    }
};