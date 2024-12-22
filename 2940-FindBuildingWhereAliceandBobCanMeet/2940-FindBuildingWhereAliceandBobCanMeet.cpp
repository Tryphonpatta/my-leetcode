if (x > y) // let x <= y
    swap(x, y);
if (x == y|| heights[x]<heights[y])
    ans[i] = y;// alice & bob meet
else idx.emplace_back(y, i);