#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class FoodRatings {
public:
  unordered_map<string, int> ftr;
  unordered_map<string, string> ftc;
  unordered_map<string, map<int, set<string>>> ctr;
  FoodRatings(vector<string> &foods, vector<string> &cuisines,
              vector<int> &ratings) {
    for (int i = 0; i < foods.size(); i++) {
      ftr[foods[i]] = ratings[i];
      ftc[foods[i]] = cuisines[i];
      ctr[cuisines[i]][ratings[i]].insert(foods[i]);
    }
  }

  void changeRating(string food, int newRating) {
    int oldRating = ftr[food];
    string cuisine = ftc[food];
    ctr[cuisine][oldRating].erase(food);
    if (ctr[cuisine][oldRating].empty()) {
      ctr[cuisine].erase(oldRating);
    }
    ctr[cuisine][newRating].insert(food);
    ftr[food] = newRating;
  }

  string highestRated(string cuisine) {
    int highestRating = ctr[cuisine].rbegin()->first;
    return *ctr[cuisine][highestRating].begin();
  }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */