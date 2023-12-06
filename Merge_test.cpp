#include <iostream>
#include <list>
#include <set>
#include <string_view>
#include <vector>
#include <variant>

using namespace std;

#include <utility>
#include <memory>
using namespace std;

 /*Измените сигнатуру этой функции, чтобы она могла
 сливать не только векторы, но и любые другие контейнеры*/
template <typename T, typename T2>
void Merge(const vector<T>& src1, const vector<T>& src2, ostream& out) {
    size_t i1 = 0, i2 = 0;
    while (i1 < src1.size() && i2 < src2.size()) {
        if (src1[i1] < src2[i2]) {
            out << src1[i1++] << endl;
        }
        else {
            out << src2[i2++] << endl;
        }
    }
    while (i1 < src1.size()) {
        out << src1[i1++] << endl;
    }
    while (i2 < src2.size()) {
        out << src2[i2++] << endl;
    }
}

template <typename InputIt1, typename InputIt2>
void Merge(InputIt1 cont1_begin, InputIt1 cont1_end, InputIt2 cont2_begin, InputIt2 cont2_end,ostream& out) {
    
   
    size_t size1 = std::distance(cont1_begin, cont1_end);
    size_t size2 = std::distance(cont2_begin, cont2_end);
    

    size_t i1 = 0, i2 = 0;
    
    
    while (i1 < size1 && i2< size2) {

    if (std::less<>()(*cont1_begin, *cont2_begin)) {
            out << *cont1_begin++ << endl;
            i1++;
    }
        else {
            out << *cont2_begin++ << endl;
            i2++;
        }
    }
    while (i1 < size1) {
        out << *cont1_begin << endl;
        i1++;
    }
    while (i2 < size2) {
        out << *cont2_begin++ << endl;
        i2++;
    }
}

template <typename cont1,typename cont2>
void MergeSomething(const cont1& src1, const cont2& src2, ostream& out) {
    
    Merge(src1.begin(), src1.end(), src2.begin(), src2.end(), out);
}
// Реализуйте эту функцию:
template <typename T>
void MergeHalves(const vector<T>& src, ostream& out) {
    size_t mid = (src.size() + 1) / 2;
    Merge(src.begin(), src.begin()+mid, src.begin() + mid, src.end(), out);

}

int main() {
    vector<int> v1{ 60, 70, 80, 90 };
   // Any any(v1);

    vector<int> v2{ 65, 75, 85, 95 };
    MergeSomething(v1, v2,cout);
    vector<int> combined{ 60, 70, 80, 90, 65, 75, 85, 95 };
    list<double> my_list{ 0.1, 72.5, 82.11, 1e+30 };
    string_view my_string = "ACNZ"sv;
    set<unsigned> my_set{ 20u, 77u, 81u };

    // пока функция MergeSomething реализована пока только для векторов
    cout << "Merging vectors:"sv << endl;
    MergeSomething(v1, v2, cout);
    
    cout << "Merging vector and list:"sv << endl;
    MergeSomething(v1, my_list, cout);

    cout << "Merging string and list:"sv << endl;
    MergeSomething(my_string, my_list, cout);

    cout << "Merging set and vector:"sv << endl;
    MergeSomething(my_set, v2, cout);

    cout << "Merging vector halves:"sv << endl;
    MergeHalves(combined, cout);
}