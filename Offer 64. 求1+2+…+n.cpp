// 剑指 Offer 64. 求1+2+…+n
// 求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。
// 示例 1：
// 输入: n = 3
// 输出: 6
// 示例 2：
// 输入: n = 9
// 输出: 45
// 限制：
// 1 <= n <= 10000
int sumNums(int n){
    int res=n;
    bool f=(n>0)&&(res+=sumNums(n-1));
    return res;
}