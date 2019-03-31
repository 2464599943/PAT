#include <iostream>
#include<stdio.h>
#include<queue>
#include<algorithm>
#include<string.h>
using namespace std;
struct wwait{
    int start;
    int process;
    friend bool operator<(wwait a,wwait b){
        return a.start>b.start;
    }
};
struct handle{
    int start;
    int finish;
    int process;
    friend bool operator<(handle a,handle b){
        return a.finish>b.finish;
    }
};
int main()
{
    int N,K,hour,minute,second,time;
    scanf("%d%d",&N,&K);
    int startime=8*3600;
    int finishtime=17*3600;
    priority_queue<wwait> wait_queue;
    priority_queue<handle> handle_queue;
    wwait w;
    handle h,h2;
    for(int i=0;i<N;i++){
        scanf("%d:%d:%d %d",&hour,&minute,&second,&time);
        w.start=hour*3600+minute*60+second;
        w.process=time*60;
        wait_queue.push(w);
    }
    double all=0.0;
    while(true){
        if(handle_queue.size()>=K){
            h=handle_queue.top();
            handle_queue.pop();
            all+=h.finish-h.process-h.start;
            cout<<all<<endl;

            if(handle_queue.size()<K&&wait_queue.size()>0){
                w=wait_queue.top();
                wait_queue.pop();
                if(w.start>=startime&&w.start<=finishtime){
                h2.start=w.start;
                h2.process=w.process;
                h2.finish=max(h.finish,w.start)+w.process;
                handle_queue.push(h2);


                }else if(w.start<startime){
                 all+=startime-w.start;
                 h2.start=startime;
                 h2.process=w.process;
                 h2.finish=max(h.finish,startime)+w.process;
                 handle_queue.push(h2);
                }
            }
        }else if(handle_queue.size()==0&&wait_queue.size()!=0){
            for(int i=0;i<K;i++){
                if(!wait_queue.empty()){
                    w=wait_queue.top();
                    wait_queue.pop();
                if(w.start<=finishtime&&w.start>=startime){
                    h.start=w.start;
                    h.process=w.process;
                    h.finish=w.process+w.start;
                    handle_queue.push(h);

                }else if(w.start<startime){
                    all+=startime-w.start;
                    h.start=startime;
                    h.process=w.process;
                    h.finish=w.process+startime;
                    handle_queue.push(h);

                }
                }

            }

        }else if(!handle_queue.empty()&&wait_queue.empty()){
            while(!handle_queue.empty()){
                h=handle_queue.top();
                handle_queue.pop();
                all+=h.finish-h.start-h.process;
                cout<<all<<endl;
            }

        }else{
            break;
        }
    }
    double ans=all/(60*N);
    printf("%.1f\n",ans);
    return 0;
}
