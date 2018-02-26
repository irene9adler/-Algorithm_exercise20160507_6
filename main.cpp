#include <stdio.h>
#include <algorithm>
#include <string.h>
//积分赛第一场E 答案
using namespace std;

long long a[505],b[505],c[505],la,lb,lc;
long long sum[505*505],len;

int bin(long long x)
{
    long long l = 0,r = len-1;
    while(l<=r)
    {
        long long mid = (l+r)>>1;
        if(sum[mid] == x)
            return 1;
        else if(sum[mid]>x)
            r = mid-1;
        else
            l = mid+1;
    }
    return 0;
}

int main()
{
    long long m,s,cas = 1,i,j,k;
    while(~scanf("%I64d%I64d%I64d",&la,&lb,&lc))
    {
        for(i = 0; i<la; i++)
            scanf("%I64d",&a[i]);
        for(i = 0; i<lb; i++)
            scanf("%I64d",&b[i]);
        for(i = 0; i<lc; i++)
            scanf("%I64d",&c[i]);
        sort(c,c+lc);
        len = 0;
        for(i = 0; i<la; i++)
        {
            for(j = 0; j<lb; j++)
            {
               sum[len++] = a[i]+b[j];
            }
        }
        sort(sum,sum+len);
        len = unique(sum,sum+len)-sum;
        scanf("%I64d",&m);
        printf("Case %I64d:\n",cas++);
        while(m--)
        {
            scanf("%I64d",&s);
            if(s>sum[len-1]+c[lc-1] || s<sum[0]+c[0])
            {
                printf("NO\n");
                continue;
            }
            long long flag = 0;
            for(i = 0;i<lc;i++)
            {
                int kk = s-c[i];
                if(bin(kk))
                {
                    flag = 1;
                    break;
                }
            }
            if(flag)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }

    return 0;
}
