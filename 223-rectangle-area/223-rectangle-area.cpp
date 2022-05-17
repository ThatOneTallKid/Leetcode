class Solution {
public:
    
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
    int s1 = (C - A) * (D - B);
    int s2 = (G - E) * (H - F); 
    if (A >= G || C <= E || D <= F || B >= H)
        return s1 + s2; 
    return s1 - (min(G, C) - max(A, E)) * (min(D, H) - max(B, F)) + s2;

    }
};






















//         int w1=abs(ax1-ax2);
//         int b1 = abs(ay1-ay2);
//         int w2 = abs(by1-by2);
//         int b2 = abs(bx1-bx2);
//         int wc =0;
//         int bc =0;
//         int total,ar1,ar2;
//        int common =0;
//         int a1 = max(ax1,bx1);
//             int b11 = max(ay1,by1);
//             int c1 = min(ax2,bx2);
//             int d1 = min(ay2,by2);
//             wc = abs(c1-a1);
//             bc = abs(d1-b11);
        
//         if(wc > 0 and bc > 0)
//             common = wc * bc;
        
        
        
            
//             total = w1*b1 + w2*b2 - common;
//             return total;