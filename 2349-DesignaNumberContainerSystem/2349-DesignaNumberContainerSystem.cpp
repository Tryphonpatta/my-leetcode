class NumberContainers {
public:

    unordered_map<int, set<int>> numIndex;
    unordered_map<int, int> indexNum;

    NumberContainers() {
        //No initialization    
    }
    
    void change(int index, int number) {
        if(indexNum.find(index) != indexNum.end()) {
            int prevNum = indexNum[index];
            numIndex[prevNum].erase(numIndex[prevNum].find(index));
            if(numIndex[prevNum].size() == 0) {
                numIndex.erase(prevNum);
            }
        }
        indexNum[index] = number;
        numIndex[number].insert(index);
    }
    
    int find(int number) {
        if(numIndex.find(number) == numIndex.end()) {
            return -1;
        }
        return *numIndex[number].begin();
    }
};