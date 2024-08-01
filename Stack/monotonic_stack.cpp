#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> montonicincreasing(vector<int>&nums){
    int n = nums.size();
    stack<int> st;
    vector<int> result;
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top()>nums[i]){
            st.pop();
        }
        st.push(nums[i]);
    }
    while(!st.empty()){
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;
}

vector<int> monotonicdecreasing(vector<int>&nums){
    int n=nums.size();
    stack<int> st;
    vector<int> result;
    for(int i=0;i<n;i++){
        while(!st.empty()&&st.top()<nums[i]){
            st.pop();
        }
        st.push(nums[i]);
    }
    while(!st.empty()){
        result.insert(result.begin(), st.top());
        st.pop();
    }
    return result;
}

int main(){
    vector<int> nums={2, 1, 8, 12, 1, 3, 4};
    vector<int> result = montonicincreasing(nums);
    cout<<"Monotonic increasing stack: ";
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl;
    result = monotonicdecreasing(nums);
    cout<<"Monotonic decreasing stack: "; 
    for(int i:result){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
