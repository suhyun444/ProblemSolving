int main(){
    int n,path = 2,a = 0;;
    scanf("%d",&n);
    if(n == 1){
        path = 1;
    }
    if(n > 7){
    n -= 7;
    path++;
    }
    while(n > 12+6*a){
        n -= 12+6*a;
        path++;
        a++;
    }
    printf("%d",path);
    return 0;
}