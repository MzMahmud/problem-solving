/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*> pointer;
        
        for(Employee *p : employees)
            pointer[p->id] = p;
        
        return dfs(pointer[id],pointer);
    }
    
    int dfs(Employee *self,unordered_map<int,Employee*> &pointer){
        int total = self->importance;

        for(int sub_id : self->subordinates)
            total += dfs(pointer[sub_id],pointer);
        
        return total;
    }
};