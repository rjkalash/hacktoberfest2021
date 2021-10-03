class QueriesPointsInsideaCircle {
    public int checkInside(int xc,int yc,int rc,int points[][])
    {
        int count =0;
        for(int i=0;i<points.length;i++)
        {
            int x=points[i][0];
            int y=points[i][1];
            if((x-xc)*(x-xc) + (y-yc)*(y-yc) <= rc*rc)
                count++;
            
            
            
        }
        return count;
        
    }
    public int[] countPoints(int[][] points, int[][] q) {
        
        int []a=new int[q.length];
         for(int i=0;i<q.length;i++)
        {
             int total=0;
            int xc=q[i][0];
            int yc=q[i][1];
            int rc=q[i][2];
                    total=checkInside( xc,yc,rc,points);
             a[i]=total;

            
        }
        return a;
        
    }
}