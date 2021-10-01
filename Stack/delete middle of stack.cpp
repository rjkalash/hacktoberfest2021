void deleteMid(stack<char> &st, int n,
                          int curr=0)
{
   // If stack is empty or all items
   // are traversed
   if (st.empty() || curr == n)
     return;
 
   // Remove current item
   char x = st.top();
   st.pop();
 
   // Remove other items
   deleteMid(st, n, curr+1);
 
   // Put all items back except middle
   if (curr != n/2)
     st.push(x);
}