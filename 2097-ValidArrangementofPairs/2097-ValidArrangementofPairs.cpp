std::unordered_map<int, std::list<int>> paths(pairs.size());
std::unordered_map<int, int> in_out(pairs.size()); // merge in and out degrees
std::vector<std::vector<int>> res(pairs.size(), std::vector<int>(2));

for (const auto& pair : pairs) {
    int from = pair[0], to = pair[1];
    paths[from].push_back(to); // add path to adj list
    in_out[from]++; // increment in degrees
    in_out[to]--; // decrement out degrees
}

int start = pairs[0][0];
for (const auto& [node, degree] : in_out) {
    if (degree == 1) { // check for difference between in and out degrees of 1
        start = node;
        break;
    }
}

std::stack<int> s;
s.push(start);

int i = pairs.size();
while (!s.empty()) {
     auto f = s.top();

     if (paths[f].empty()) {
          // build the result vector directly here
          if (i < pairs.size()) { res[i][0] = f; } // set the start of curr node
          if (i - 1 >= 0) { res[i - 1][1] = f; } // set the end of prev node
          i--;
          s.pop();
          continue;
     }

     auto neighbor = paths[f].front();
     paths[f].pop_front();
     s.push(neighbor);
}

return res;