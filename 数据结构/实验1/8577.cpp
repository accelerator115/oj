#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedLists(const vector<int>& A, const vector<int>& B) {
    vector<int> C;
    int i = 0, j = 0;
    while (i < A.size() && j < B.size()) {
        if (A[i] <= B[j]) {
            C.push_back(A[i]);
            i++;
        } else {
            C.push_back(B[j]);
            j++;
        }
    }
    while (i < A.size()) {
        C.push_back(A[i]);
        i++;
    }
    while (j < B.size()) {
        C.push_back(B[j]);
        j++;
    }
    return C;
}

int main() {
    int nA, nB;
    cin >> nA;
    vector<int> A(nA);
    for (int i = 0; i < nA; i++) {
        cin >> A[i];
    }
    cin >> nB;
    vector<int> B(nB);
    for (int i = 0; i < nB; i++) {
        cin >> B[i];
    }

    vector<int> C = mergeSortedLists(A, B);

    cout << "List A:";
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    cout << "List B:";
    for (int i = 0; i < B.size(); i++) {
        cout << B[i] << " ";
    }
    cout << endl;

    cout << "List C:";
    for (int i = 0; i < C.size(); i++) {
        cout << C[i] << " ";
    }
    cout << endl;

    return 0;
}
// 偷鸡大法
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main()
// {
//     vector<int> A, B, C;
//     int nA, nB;
//     cin >> nA;
//     A.resize(nA);
//     for (int i = 0; i < nA; i++)
//     {
//         cin >> A[i];
//     }
//     cin >> nB;
//     B.resize(nB);
//     for (int i = 0; i < nB; i++)
//     {
//         cin >> B[i];
//     }
//     C.resize(nA + nB);
//     for(int i=0;i<nA+nB;i++)
//     {
//         if(i<nA)
//             C[i]=A[i];
//         else
//             C[i]=B[i-nA];
//     }
//     sort(C.begin(), C.end());
//     cout << "List A:";
//     for (int i = 0; i < A.size(); i++)
//     {
//         cout << A[i] << " ";
//     }
//     cout << endl;
//     cout << "List B:";
//     for (int i = 0; i < B.size(); i++)
//     {
//         cout << B[i] << " ";
//     }
//     cout << endl;
//     cout << "List C:";
//     for (int i = 0; i < C.size(); i++)
//     {
//         cout << C[i] << " ";
//     }
//     cout << endl;
//     return 0;
// }