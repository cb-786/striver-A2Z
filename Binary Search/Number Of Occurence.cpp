vector<int> searchRange(int nums[],int n, int target) {

          vector<int> ans;
          if(n==1) {

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
        int e = n-1;
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
           e = n-1;
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
	
	
	
	
	
	
	
	
	int count(int arr[], int n, int x) {
	    
	    
	    
	vector<int> ans =   searchRange(arr,n, x);
	

	
	   if(ans[0] == -1 && ans[1] == -1 ) {
	       return 0;
	   }
	   
	   if(ans[0]==ans[1]) {
	       return 1;
	   }
	   
	   if(ans[0]!=ans[1]) {
	       return ans[1] - (ans[0]-1);
	   }
	   
	}