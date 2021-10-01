int isPerfectNumber(long long N) {
        if(N==1)
        return 0;
        long long int n=N,sum=0;
        for(long long i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if((n/i)==i)
                sum+=i;
                else 
                {
                    sum+=i;
                    sum+=(n/i);
                }
            }
        }
        sum+=1;
        if(sum==n)
        return 1;
        return 0;
    }