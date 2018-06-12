#include<stdio.h>

void print(char ops[]){

    char p[17];
    int i=0,j=49,k=0;
    while(1){
        p[i++]=j++;
        if(j==58){
            break;
        }
        if(ops[k]!='.'){
            p[i++] = ops[k++];
        }
        else{
            k++;
        }


    }

    for(k=0; k<i; k++){
        printf("%c",p[k]);
    }



}


void concat(int nos[9], int ind){

    nos[ind] = 10*nos[ind] + nos[ind+1];

    int i;
    for(i=(ind+1); i<8; i++){
        nos[i] = nos[i+1];
    }


}

int eval(char a[8]){

    int nos[9] = {1,2,3,4,5,6,7,8,9};

    int i,count=0;
    for(i=0; i<8; i++){
        if(a[i]=='.'){
            concat(nos,(i-count));
            count++;
        }
    }

    int newnos[9-count];
    for(i=0; i<(9-count); i++){
        newnos[i] = nos[i];
    }

    char newops[8-count];
    int j=0;
    for(i=0; i<(8-count); i++){
        if(a[j]=='.'){
            j++;
            i--;
        }
        else if(a[j]!='.'){
            newops[i]=a[j++];
        }
    }


    j=1;
    int ans=newnos[0];
    for(i=0; i<(8-count); i++){
        if(newops[i]=='+'){
            ans += newnos[j++];
        }
        else if(newops[i]=='-'){
            ans -= newnos[j++];
        }
    }

    if(ans==100){
        return 1;
    }
    else{
        return 0;
    }

}




int main(){

    int a,b,c,d,e,f,g,h,cnt=0;
    char arr[3] = {'+','-','.'};
    char ops[8];

    for(a=0; a<3; a++){
        ops[0] = arr[a];
        for(b=0; b<3; b++){
            ops[1] = arr[b];
            for(c=0; c<3; c++){
                ops[2] = arr[c];
                for(d=0; d<3; d++){
                    ops[3] = arr[d];
                    for(e=0; e<3; e++){
                        ops[4] = arr[e];
                        for(f=0; f<3; f++){
                            ops[5] = arr[f];
                            for(g=0; g<3; g++){
                                ops[6] = arr[g];
                                for(h=0; h<3; h++){
                                    ops[7] = arr[h];
                                    if(eval(ops)){
                                        print(ops);
                                        printf("=100\n\n");
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
