#include <bits/stdc++.h>
using namespace std;

// Intution too stack kaa aa raha hai 
// par yaar solve karna muskil hoo raha hai


// Again 
// class Solution {

//     int solveAND(string exp , int & idx){
//         while(exp[idx]!=')' && exp[idx]!='f'){
//             idx++;
//         }

//         bool check =  exp[idx] == ')'?1 : 0;

//         while(exp[idx]!=')'){
//             idx++;
//         }

//         return check;
//     }

//     int solveOR(string exp , int & idx){
//         while(exp[idx]!=')' && exp[idx]!='t'){
//             idx++;
//         }

//         bool check =  exp[idx] == ')'?0: 1;

//         while(exp[idx]!=')'){
//             idx++;
//         }

//         return check;
//     }

// public:
//     bool parseBoolExpr(string expression) {
//         stack<char> st;

//         int n = expression.size();

//         int i = 0;

//         while(i < n){
//             if(expression[i] == ',')i++;
//             else if(expression[i] == '!' || expression[i] == '&' || expression[i] == '|'|| expression[i] == '(' ){
//                 st.push(expression[i]);
//             }

//             else if(expression[i] == 'f' || (expression[i] == 't')){
//                 st.pop();
//                 char op = st.top();
//                 st.pop();   
//                 if(op == '&'){
//                     if(solveAND(expression , i))
//                         st.push('t');
//                     else{
//                         st.push('f');
//                     }
//                     i++;
//                 }

//                 else if(op == '|'){
//                     if(solveOR(expression , i))
//                         st.push('t');
//                     else{
//                         st.push('f');
//                     }
//                     i++;
//                 }

//                 else if(op == '!'){
//                     if(expression[i] == 't')st.push('f');
//                     else st.push('t');
//                     i+=2;
//                 }

//                 else if(op == ')'){
//                     // pop the elements check the operator and perform the operation and push again 
//                 }
//             }
//         }

//         // while(!st.empty()){
//         //     string temp = "";
//         //     while(!st.empty() && st.top() == )
//         // }


//     }
// };

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        int n = expression.size();

        for(int i = 0 ; i < n ; i++){
            if(expression[i]==',')continue;

            else if(expression[i]!=')'){
                // push karte chalo 
                st.push(expression[i]);
            }

            else{
                // pop the elements untill operator and perform the operation and push again 
                int count_f = 0 , count_t = 0;
                // cout<<st.top();
                char curr = st.top();
                while(!st.empty() && curr == 'f' || curr =='t'){
                    if(curr == 'f')count_f++;
                    else count_t++;
                    st.pop();
                    curr = st.top();
                }

                if(!st.empty() && st.top() == '(') st.pop();

                // check which operator is this 
                if(!st.empty()){
                    char op = st.top();
                    st.pop();
                    
                    if(op == '&'){
                        if(count_f)st.push('f');
                        else st.push('t');
                    }
                    else if(op == '|'){
                        if(count_t)st.push('t');
                        else st.push('f');
                    }
                    else{
                        // definitely not operator is there
                        if(count_f)st.push('t');
                        else st.push('f');
                    }
                }
            }   
        }

        return st.top() == 'f' ? false : true;
    }
};

// In order to made a problem a little harder 

// Just think what if the parenthesis are not there 
//then what could be your hypothesis 

// I can say multiple possibilies are there and we can made any of these possiblities 

// Now here we use something kind of partition ??????? 

// Yes soo the pattern has successfully be found 

// Remember Always be in a step by step process to get the result 

// Just think about objective now pipelining how do you achieve that objective 



//find the number of ways of the expression that fields true 



int main() {
    
    return 0;
}