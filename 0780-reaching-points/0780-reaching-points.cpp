class Solution {
public:
    bool f(int x, int y, int dx, int dy){
        if(x==dx && y== dy)return true;
        if(x>dx || y>dy)return false;
        if(x==dx && (dy-y)%dx==0)return true;
        if(y==dy && (dx-x)%dy==0)return true;

        bool w1 = false;
        if(dx>dy){
            w1 = f(x,y,dx%dy,dy);
        }
        bool w2 = false;
        if(dy>dx){
            w2= f(x,y,dx,dy%dx);
        }
        
        
        return w1||w2;
    }
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        
        return f(sx,sy,tx,ty);
    }
};