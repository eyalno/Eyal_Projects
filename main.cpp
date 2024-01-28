#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

vector<int>  sortedSquares(vector<int>& nums);
vector<int>  sortedSquaresV2(vector<int>& nums);
vector<int>  sortArrayByParity(vector<int>& nums);
vector<int>  sortArrayByParityV2(vector<int>& nums);

vector<int> twoSum(vector<int>& nums, int target);

vector<int> twoSumMap(vector<int>& nums, int target);

int partitionDisjoint(vector<int>& nums);
int partitionDisjointV2(vector<int>& nums);
int partitionDisjointV3(vector<int>& nums);

 bool isLongPressedName(string name, string typed);

int main(){
      
     cout << "Main Start"<<endl; 
      
     vector<int> nums = {24,11,49,80,63,8,61,22,73,85};
 
      string name ="ssaeed";

      string typed ="sssaaedd";                  

      twoSumMap(nums,71);

      return 0;
}


vector<int> twoSumMap(vector<int>& nums, int target){

      map<int,int> myMap;

      int size = nums.size();

      vector<int> indices(2);
      
      for (int i = 0 ; i < size-1; i++  ){
            
            int compliment = target - nums[i];
            myMap.insert(nums[i],i);
            
            if (myMap[compliment] &&  myMap[compliment] != i ){

                  indices[0] = i;
                  indices[1] = myMap[compliment];
                  break;
            }
      }

      return indices;

}


vector<int> twoSum(vector<int>& nums, int target){


      int size = nums.size();

      vector<int> indices(2);

      for (int i = 0 ; i < size-1; i++  ){
            for (int j = i+1; j < size; j++){

                  if (nums[i] + nums[j] == target){
                        indices[0] = i;
                        indices[1] = j;
                        return indices;
                  }
                        

            } 

      }

      return indices;

}

 bool isLongPressedName(string name, string typed) {

      bool bIs= true;
      
      int i=0;
      for (int  j=0;  j < typed.length(); ){
            if ((i < name.length()) && name[i] == typed[j] ){
                  i++;
                  j++;

            }else if (j != 0 &&  typed[j] == typed[j-1])
                  j++;
            else
                  return false;
      }

      return i == name.length();

 }


 int partitionDisjointV3(vector<int>& nums) {
 
      int size = nums.size();

      int currentMax;
      int possibleMax;
      int length = 1;
      currentMax = possibleMax = nums[0];
      

      
      for (int i= 1; i < size ; i++ ){
      
            if (nums[i] < currentMax ){
                  length = i+1;
                  currentMax = possibleMax;
            }
            else{
                 possibleMax =   max(possibleMax,nums[i]);
            }
      
      }
            return length;

     
 }




 int partitionDisjointV2(vector<int>& nums) {
 
      int size = nums.size();

      int currentMax;
      int minRight[size];

      currentMax = nums[0];
      minRight[size-1] = nums[size-1];

      for (int i= size-2; i >= 0 ; i-- ){
            minRight[i] = min(nums[i],minRight[i+1]);
      }
  
      for (int i=1; i < size; i++ ){
         
            if (currentMax <= minRight[i])
                   return i;

            currentMax = max(nums[i],currentMax);
      }
      return -1;
 }





 int partitionDisjoint(vector<int>& nums) {
 
      int size = nums.size();

      int maxLeft[size];
      int minRight[size];

      maxLeft[0] = nums[0];
      minRight[size-1] = nums[size-1];

      for (int i=1; i < size; i++ ){
            maxLeft[i] = max(nums[i],maxLeft[i-1]);
      }

      for (int i= size-2; i >= 0 ; i-- ){
            minRight[i] = min(nums[i],minRight[i+1]);
      }
  
      for (int i=1; i < size; i++ )
            if (maxLeft[i-1] <= minRight[i])
            return i;
      
      return -1;
 }





bool compareParity(int a, int b){
      return (a%2 == 0) && (b%2 ==1);
}

 vector<int> sortArrayByParityV2(vector<int>& nums) {

      sort(nums.begin(),nums.end(),compareParity);

      return nums;


 }

 vector<int> sortArrayByParity(vector<int>& nums) {
 
      int size = nums.size();

      for (int i = 0 , j = size -1; i<j;  ){

            if ( (nums[i]%2 == 1 ) && (nums[j]%2 == 0)){

                  int temp =  nums[i];
                  nums[i] = nums[j];
                  nums[j] = temp; 
            }
            if (nums[i]%2 == 0)
                        ++i;
            if (nums[j]%2 == 1)
                        --j;

      }
      return nums;
 
 }


 vector<int> sortedSquaresV2(vector<int>& nums){

      int size = nums.size();

      vector<int> res(size,0);
      int left = 0;
      int right = size -1;

      for (int i = size -1 ; i >= 0  ; --i){

            int leftSq = pow(nums[left],2); 
            int rightSq = pow(nums[right],2); 

            if (leftSq > rightSq){
                  res[i] = leftSq;
                  left++;
            }
            else{
                  res[i] = rightSq;
                  right--;
            }

      }
      return res;
 }




 vector<int> sortedSquares(vector<int>& nums){
	
     vector<int> res(nums.size(),0); 
     
     vector<int>::iterator it = nums.begin();
     vector<int>::reverse_iterator rit = nums.rbegin();

      if(it == nums.end() || rit == nums.rend() || nums.empty()  ){
            cout<< "empty vector"; 
            return nums;
      }
     
     //-15,-10,0,1, 2, 3, 4, 5
      for (auto currIt = res.rbegin() ;it <= rit.base() && currIt != res.rend() ;currIt++ ){
            
            int leftSq = (*it)*(*it); 
            int rightSq = (*rit)*(*rit);

            if (leftSq > rightSq){
                  *currIt = leftSq;
                  it++;
            }
            else{
                  *currIt = rightSq;
                  rit++;
            }
            
      }
     

      return res;
}       


        
	




