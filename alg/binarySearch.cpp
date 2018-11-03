    #include <cstdio>
    #include <cstdlib>
    #include <cstring>

    int n, S[1000000], q, T[50000], A[500000], ans;


    int binarySearch(int A[500000], int key){
        int left = 0, right = n, mid = 0, count=0;

        while (left < right){

            mid = (left + right)/2;

            if(A[mid]==key){

                return 1;

            }else if(A[mid]>key){

                right = mid;

            }else{

                left = mid + 1;

            }


        }

        return 0;

    }



    int main(){

        scanf("%d",&n);

        for(int i = 0; i < n; i++)
        {
            scanf("%d",&S[i]);
        }

        scanf("%d",&q);

    for(int i = 0; i < q; i++)
    {
        scanf("%d",&T[i]);
        ans += binarySearch(S,T[i]);
    }

    printf("%d\n",ans);

    return 0;

    }





