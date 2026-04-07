class Robot {
public:
    int ind=0, ismove=0;
    vector<vector<int>> pos;
    Robot(int width, int height) {
        pos.push_back({0, 0, 3});
        for(int i=1; i<width; i++){
            pos.push_back({i, 0, 0});
        }
        for(int i=1; i<height; i++){
            pos.push_back({width-1, i, 1});
        }
        for(int i=width-2; i>=0; i--){
            pos.push_back({i, height-1, 2});
        }
        for(int i=height-2; i>0; i--){
            pos.push_back({0, i, 3});
        }
    }
    
    void step(int num) {
        ismove=1;
        ind=(ind+num)%pos.size();
    }
    
    vector<int> getPos() {
        return {pos[ind][0], pos[ind][1]};
    }
    
    string getDir() {
        if(!ismove) return "East";
        if(pos[ind][2]==0) return "East";
        if(pos[ind][2]==1) return "North";
        if(pos[ind][2]==2) return "West";
        return "South";
    }

    
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */