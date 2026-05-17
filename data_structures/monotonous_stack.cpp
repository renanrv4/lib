// Stack Monotônica
stack<int> st;
for(int i = 0; i <= n; i++) {
    ll cur;
    if(i == n) {
        cur = 0;
    } else {
        cur = heights[i];
    }
    while(!st.empty() && heights[st.top()] > cur) {
        ll h = heights[st.top()]; st.pop();
        ll width = st.empty() ? i : i - st.top() - 1;
        if(st.empty()) {
            width = i;
        } else {
            width = i - st.top() - 1;
        }
        max_area = max(max_area, h * width);
    }
    st.push(i);
}
