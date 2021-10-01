	string minimum_Number(string s){
   	    sort(s.begin(),s.end());
   	  int i=0;
   	  while(s[i]=='0' && i<s.length())
   	  i++;
   	   // cout<<i;
   	   if(i==s.length())
   	   return s;
   	    swap(s[0],s[i]);
   	    return s;
   	} 