LIMIT = 1000

perimeter = {}
for a in range(1, LIMIT):
    for b in range(a + 1, LIMIT):
        for c in range(b + 1, LIMIT):
            p = a + b + c
            if p > LIMIT:
                continue

            if (a**2 + b**2) != c**2:
                # not right angled triangle
                continue

            if p in perimeter:
                perimeter[p] += 1
            else:
                perimeter[p] = 1


# print(perimeter)
max_count = max(perimeter.keys(), key=(lambda k: perimeter[k]))
print(f"{max_count} has maximum")
# 840 has maximum
# Python took 52s in google collab

# C++ Code took .40s
# #include <bits/stdc++.h>

# using namespace std;

# int main() {
#     int LIMIT = 1000;

#     vector<int> perimeter(LIMIT + 1,0);
#     for(int a = 1;a < LIMIT;a++){
#         for(int b = a + 1;b < LIMIT;b++){
#             for(int c = b + 1;c < LIMIT;c++){
#                 int p = a + b + c;
#                 if (p > LIMIT)
#                     continue;

#                 if((a*a + b*b) != c*c)//not right angled triangle
#                     continue;

#                 ++perimeter[p];
#             }
#         }
#     }

#     int max_count = -1;
#     int max_p = -1;
#     for(int p = 1;p <= LIMIT;++p){
#         if(perimeter[p] > max_count){
#             max_count = perimeter[p];
#             max_p = p;
#         }
#     }
#     printf("%d has maximum",max_p);
#     return 0;
# }
