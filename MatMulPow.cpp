#define MAX_N 3
typedef struct{
    ll mat[3][3];
}Matrix;
Matrix matMul(Matrix a, Matrix b){
	Matrix ans; int i,j,k;
	for(i=0;i<MAX_N;i++)
        for(j=0;j<MAX_N;j++)
            for(ans.mat[i][j] = k = 0;k<MAX_N; k++)
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k]%1000000009 * b.mat[k][j]%1000000009)%1000000009;
                //if you want real answer, delete the modulo
    return ans;
}
Matrix matPow(Matrix base, ll p){
	Matrix ans; int i,j;
	for(i=0;i<MAX_N;i++) for(j=0;j<MAX_N;j++) ans.mat[i][j] = (i==j);
    while(p){
        if(p&1) ans = matMul(ans,base);
        base = matMul(base,base);
        p>>=1;
    }
    return ans; //trifib(n) is in base[1][1], change to fib(n) --> stored in [1][0]
}
