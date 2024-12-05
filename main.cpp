#include "Widget.h"
#include <QApplication>
#include <vector>
#include <math.h>
#include <QFile>
#include <iostream>
using namespace std;
namespace _2040 {
class Solution {
public:
    long long ltOrEq(const vector<int>& nList1,const vector<int>& nList2,long long limit){
        long long cnt = 0;
        for(auto n:nList1){
            if(n>0){
                if(limit>0){
                    int target = limit/n;
                    auto it = upper_bound(nList2.begin(),nList2.end(),target);
                    cnt += (it-nList2.begin());
                }
                else if(limit==0){
                    auto it = upper_bound(nList2.begin() , nList2.end() , 0);
                    cnt += (it-nList2.begin());
                }
                else{
                    if(limit % n){
                        auto it = lower_bound(nList2.begin() , nList2.end() , limit/n);
                        cnt += (it-nList2.begin());
                    }
                    else{
                        auto it = upper_bound(nList2.begin() , nList2.end() , limit/n);
                        cnt += (it-nList2.begin());
                    }
                }
            }
            else if(n==0){
                if(limit >= 0){
                    cnt += nList2.size();
                }
            }
            else{
                if(limit > 0){
                    auto it = lower_bound(nList2.begin() , nList2.end() , limit/n);
                    cnt += nList2.end() - it;

                }
                else if(limit == 0){
                    auto it = lower_bound(nList2.begin() , nList2.end() , 0);
                    cnt += nList2.end() - it;
                }
                else{
                    if(limit%n){
                        auto it = upper_bound(nList2.begin(),nList2.end() , limit/n);
                        cnt += nList2.end() - it;
                    }
                    else{
                        auto it = lower_bound(nList2.begin(),nList2.end() , limit/n);
                        cnt += nList2.end() - it;
                    }
                }
            }
        }
        return cnt;
    }
    long long f(vector<int>&v1,vector<int>&v2,long long t){
        long long ct=0;
        long long cnt1 = 0;
        long long cnt2 = 0;
        long long cnt3 = 0;
        for(long long i=0;i<v1.size();i++){
            if(v1[i]==0){
                if(t>=0)ct+=v2.size();
            }
            else if(v1[i]>0){
                long long val = floor((double)t/v1[i]);
                auto it = upper_bound(v2.begin(),v2.end(),val);
                ct+=it-v2.begin();
            }else{
                long long val = ceil((double)t/v1[i]);
                auto it = lower_bound(v2.begin(),v2.end(),val);
                ct+=(v2.end()-it);
            }
            //if(ct>k)return ct;
        }
        return ct;
    }
    long long kthSmallestProduct(vector<int>& n1, vector<int>& n2, long long k) {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        long long head1 = n1[0];
        long long end1 = n1.back();
        long long head2 = n2[0];
        long long end2  = n2.back();
        long long hi = max({head1*head2 ,head1*end2,end1*head2,end1*end2});
        long long lo = min({head1*head2 ,head1*end2,end1*head2,end1*end2});

        while(lo<hi){
            auto mid = lo + (hi-lo)/2;

            auto cnt = f(n1,n2,mid);
            if(cnt < k ){

                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }

        return lo;
    }
};
}
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
}
