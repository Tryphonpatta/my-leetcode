// Last updated: 3/21/2025, 10:41:30 PM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        vector<int> v[300];
        string indexing_string[300];
        unordered_map<string,int> m;
        bool isRecipe[300] = {};
        int countIngredient[300] = {};
        int indexing = 1;
        for(auto recipe : recipes) {
            m[recipe] = indexing;
            indexing_string[indexing] = recipe;
            isRecipe[indexing] = true;
            indexing ++;
        }
        for(auto ingredientss : ingredients) {
            for(auto ingredient : ingredientss) {
                if(m[ingredient] != 0)continue;
                m[ingredient] = indexing;
                indexing_string[indexing] = ingredient;
                indexing ++;
            }
        }
        for(auto supply : supplies){
            if(m[supply] != 0)continue;
            m[supply] = indexing;
            indexing_string[indexing] = supply;
            indexing ++;
        }
        for(int i = 0 ; i < recipes.size() ; i++){
            countIngredient[m[recipes[i]]] = ingredients[i].size();
            // cout << m[recipes[i]] << " " << countIngredient[m[recipes[i]]];
            for(int j = 0 ; j < ingredients[i].size() ; j++){
                v[m[ingredients[i][j]]].push_back(m[recipes[i]]);
            }
        }
        queue<int> q;
        bool vis[300] = {};
        for(auto supply : supplies){
            q.push(m[supply]);
        }
        vector<int> ans_num;
        vector<string> ans_string;
        while(!q.empty()){
            int x = q.front();
            q.pop();
            if(vis[x])continue;
            // cout << x << " " << countIngredient[x] << endl;
            if(isRecipe[x] && countIngredient[x] == 0){
                ans_num.push_back(x);
                vis[x] = true;
            }
            for(int i = 0 ; i < v[x].size() ; i++){
                if(isRecipe[v[x][i]]){
                    countIngredient[v[x][i]] --;
                    if(countIngredient[v[x][i]] == 0)q.push(v[x][i]);
                }
                else {
                    q.push(v[x][i]);
                }
            }
        }
        for(int i = 0; i < ans_num.size() ; i++){
            ans_string.push_back(indexing_string[ans_num[i]]);
        }
        return ans_string;
    }
};