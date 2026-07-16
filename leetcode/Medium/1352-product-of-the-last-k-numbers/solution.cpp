class ProductOfNumbers {
    vector<int> ans;
public:
    ProductOfNumbers() {
       //vector<int> ans;

        
    }
    
    void add(int num) {
        //for(int i =0;i<num.size();i++){
            ans.push_back(num);
        //}
        
    }
    
    int getProduct(int k) {
        int product =1;
        int n = ans.size();
        for(int i=n-k;i<n;i++){
            product = product * ans[i];
        }
        return product;
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
