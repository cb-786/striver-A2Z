vector<int> searchRange(vector<int>& nums, int target) {

          vector<int> ans;
          if(nums.size()==1) {

             if(target == nums[0]) {
                ans.push_back(0);
                ans.push_back(0);
                return ans;
             }


             else {
                ans.push_back(-1);
                ans.push_back(-1);
                return ans;
             }





          }



        int ans1 = -1;
        int ans2 = -1;

        int flag=0;
        int s = 0;
        int e = nums.size()-1;
        int mid = s+ ( (e-s)/2);

        while(s<e) {

            mid = s + ((e-s)/2);

            if(nums[mid]==target) {
                flag++;
                if(nums[s] == target) {
                    ans1=s;
                    break;
                }
                ans1 = mid;
                e=mid-1;
                
            }


               if(nums[mid]>target) {
               
                if(nums[s] == target) {
                    ans1=s;
                    e=mid-1;
                    break;
                }

                if(nums[e]==target) {
                    ans1 = e;
                    e=mid-1;
                    continue;
                   }
               
                
                e=mid-1;
                continue;
               }


               if(nums[mid]<target) {
                     
                        if(nums[s] == target) {
                    ans1=s;
                    break;
                }

                if(nums[e]==target) {
                    ans1 = e;
                    e=e-1;
                    continue;
                   }
                      
                
                s=mid+1;
                continue;
               }

        }

           s=0;
           e = nums.size()-1;
             mid = s+ ( (e-s)/2);


        while(s<e) {

            mid = s+ ( (e-s)/2);

            if(nums[mid]==target) {
                if(nums[e]==target) {
                    ans2 = e;
                    break;
                   }
                ans2 = mid;
                s=mid+1;
            }


               if(nums[mid]>target) {

                if(nums[e]==target) {
                    ans2 = e;
                    break;
                   }

                if(nums[s] == target) {
                    ans2=s;
                    s=s+1;
                    continue;
                }

                e=mid-1;
               }


               if(nums[mid]<target) {

                 if(nums[e]==target) {
                    ans2 = e;
                    s=mid+1;
                    break;
                   }

                if(nums[s] == target) {
                    ans2=s;
                    s=mid+1;
                    continue;
                }
                s=mid+1;
               }

        }

        
         ans.push_back(ans1);
         ans.push_back(ans2);

         return ans;



    }