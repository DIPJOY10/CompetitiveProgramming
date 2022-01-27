//reference problem:https://codeforces.com/contest/1625/problem/D

struct Node{
        int ptr;
        Node* child[2];
        Node(){
            ptr=0;
            child[0]=NULL;
            child[1]=NULL;
        }
    };
    struct TRIE{
        Node* root;
        TRIE(){
            root=new Node();
        }
        void insert(int num){
            Node* temp=root;
            for(int i=30;i>=0;i--){
                int set=((num>>i)&1);
                if(!temp->child[set]){
                    temp->child[set]=new Node();
                }
                temp=temp->child[set];
                temp->ptr++;
            }
        }
        int max_xor(int num){
            int ans=0;
            Node* temp=root;
            for(int i=30;i>=0;i--){
                int set=((num>>i)&1);
                if(temp->child[!set]){
                    ans+=(1<<i);
                    temp=temp->child[!set];
                }else{
                    temp=temp->child[set];
                }
            }
            return ans;
        }
    };
