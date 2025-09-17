class FoodRatings {
public:
    map<string, set<pair<int, string>>> cuisineSet;
    map<string, string> foodCuisineMap;
    map<string, int> foodRatingMap;

    FoodRatings(vector<string>& food, vector<string>& cuisine, vector<int>& ratings) {
        for(int i=0;i<food.size();i++){
            foodCuisineMap[food[i]] = cuisine[i];
            foodRatingMap[food[i]] = ratings[i];
            cuisineSet[cuisine[i]].insert({-1*ratings[i], food[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodCuisineMap[food];
        int rating = foodRatingMap[food];
        cuisineSet[cuisine].erase({-1*rating, food});
        cuisineSet[cuisine].insert({-1*newRating, food});
        foodRatingMap[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        auto it = *(cuisineSet[cuisine].begin());
        return it.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */