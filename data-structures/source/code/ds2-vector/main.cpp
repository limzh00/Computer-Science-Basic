# include"simple_vector.h"
# include<bits/stdc++.h>

int main(void){
    Vector vec(10,2,10);
    for(int i = 0; i < vec.size(); i++) printf("%d ", vec.get(i));
    return 0;
}