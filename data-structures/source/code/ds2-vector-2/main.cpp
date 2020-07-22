# include "simple_vector.h"
# include<bits\stdc++.h>

int passed = 0;
int wrong = 0;
int counter = 1;
#define CHECKVALUE(test_val, correct_val, test_point) { \
    if(test_val == correct_val) { \
        printf("Passed! Test point %d.\n", test_point); \
        passed++; \
    } else { \
        printf("Error! Test point %d. Pay attention since you didn't pass this.\n", test_point); \
        wrong++; \
    } \
}
#define TESTBREAK printf("-------------------------\n");
using namespace std;

int main(void){
    cout << "********TEST CASES*********" << endl;
    cout << "TEST CASE 1 - 10: DEFAULT-CONSTRUCTOR" << endl;
    Vector<int> vec1(10,20,30);
    for(int i = 0; i < vec1.size(); i++) CHECKVALUE(vec1[i],30,counter++)
    TESTBREAK
    cout << "TEST CASE 11 - 20: COPY-CONSTRUCTOR " << endl;
    Vector<int> vec2(vec1);
    for(int i = 0; i < vec2.size(); i++) CHECKVALUE(vec2[i],30,counter++)
    TESTBREAK
    cout << "TEST CASE 21 - 25: SUBCOPY-CONSTRUCTOR " << endl;
    Vector<int> vec3(vec1,0,5);
    for(int i = 0; i < vec3.size(); i++) CHECKVALUE(vec3[i],30,counter++)
    TESTBREAK
    cout << "TEST CASE 25 - 35: OPERATOR = " << endl;
    for(int i = 0; i < vec1.size();i++) vec1[i] = i;
    vec3 = vec1;
    for(int i = 0; i < vec3.size(); i++) CHECKVALUE(vec3[i],i,counter++)
    TESTBREAK
    cout << "TEST CASE 35 - 65: OPERATOR + & +=" << endl;
    (vec3 = vec1 + vec2) += vec1;
    for(int i = 0; i < vec1.size(); i++) CHECKVALUE(vec3[i],vec1[i],counter++)
    for(int i = vec1.size(); i < vec1.size()+ vec2.size(); i++) CHECKVALUE(vec3[i],30,counter++)
    for(int i = vec1.size()+vec2.size(); i < vec3.size(); i++) CHECKVALUE(vec3[i],i - 20,counter++)
    TESTBREAK   
    cout << "TEST CASE 65 - 70: OPERATOR != & ==" << endl;
    vec3 = vec1;
    CHECKVALUE(vec3 == vec1, true, counter++)
    CHECKVALUE(vec3 == vec2, false, counter++)
    CHECKVALUE(vec3 != vec1, false, counter++)
    CHECKVALUE(vec3 != vec2, true, counter++)
    CHECKVALUE(vec3+vec1 == vec2, false, counter++)
    TESTBREAK
    cout << "TEST CASE 71 - 80: remove" << endl;
    vec1.remove(0);
    vec1.remove(0);
    vec1.remove(vec1.size() - 1);
    for(int i = 0; i < vec1.size(); i++) CHECKVALUE(vec1[i],i+2, counter++);
    vec1.remove(4);
    vec1.remove(2);
    vec1.remove(2);
    vec1.remove(1);
    CHECKVALUE(vec1[0],2,counter++)
    CHECKVALUE(vec1[1],7,counter++)
    CHECKVALUE(vec1[2],8,counter++)
    TESTBREAK
    cout << "TEST CASE 81 - 290: insert" << endl;
    vector<int> std_vec(10);
    Vector<int> test_vec(10,10);
    for(int i = 0; i < 10; i++) std_vec[i] = test_vec[i] = i;
    for(int i = 0; i < 100; i++){
        std_vec.insert(vector<int>::const_iterator(&std_vec[i]),i*i+2);
        test_vec.insert(i,i*i+2);
        std_vec.insert(std_vec.cend(),i);
        test_vec.insert(i);
    }
    for(int i = 0; i < test_vec.size(); i++) CHECKVALUE(test_vec[i],std_vec[i], counter++);
    TESTBREAK    
    cout << "TEST CASE 290 - 300: find & max & min" << endl;
    Vector<int> vec0(10,10);
    for(int i = 0; i < vec0.size(); i += 2) vec0[i] = vec0[i+1] = i;
    CHECKVALUE(vec0.find(100),-1, counter++)
    CHECKVALUE(vec0.find(10),-1, counter++)
    CHECKVALUE(vec0.find(1),-1, counter++)
    CHECKVALUE(vec0.find(2),3, counter++)
    CHECKVALUE(vec0.find(8),9, counter++)
    CHECKVALUE(vec0.max(),9, counter++)
    CHECKVALUE(vec0.min(),1, counter++)
    vec0[4] = 0;
    vec0[5] = 1000;
    CHECKVALUE(vec0.min(),4, counter++)
    CHECKVALUE(vec0.max(),5, counter++)
    CHECKVALUE(vec0.find(1000),5, counter++)
    cout << "YOU HAVE PASSED " << passed << " TESTCASES" << endl;
    cout << "YOU HAVE NOT PASSED " << wrong << " TESTCASES" << endl; 
    return 0;
}
 