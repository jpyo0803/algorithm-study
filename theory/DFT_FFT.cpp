//
// Discrete Fourier Transform
// O(N*N)
//
// Fast Fourier Transform
// O(NlogN)
//

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

typedef complex<double> Z;

vector<Z> DFT(vector<Z>& a) {
    int n = a.size();

    vector<Z> Y(n);
    for (int i = 0; i < n; i++) {
        Z c(0, 0);
        for (int j = 0; j < n; j++) {
            double exp = 2 * M_PI * i * j / n;
            c += Z(cos(exp) * a[j].real(), sin(exp) * a[j].real());
        }
        Y[i] = c;
    }
    return Y;
}

vector<Z> FFT(vector<Z>& a) {
    int n = a.size();

    if (n == 1) return vector<Z>(1, a[0]);

    vector<Z> w(n / 2);
    for (int i = 0; i < n / 2; i++) {
        double exp = 2 * M_PI * i / n;
        w[i] = Z(cos(exp), sin(exp));
    }

    vector<Z> Ae(n / 2), Ao(n / 2); // 짝수와 홀수 원소들을 분리
    for (int i = 0; i < n / 2; i++) {
        Ae[i] = a[2 * i];
        Ao[i] = a[2 * i + 1];
    }

    vector<Z> Ye = FFT(Ae);
    vector<Z> Yo = FFT(Ao);

    vector<Z> Y(n);

    for (int k = 0; k < n / 2; k++) {
        Y[k] = Ye[k] + w[k] * Yo[k];
        Y[k + n / 2] = Ye[k] - w[k] * Yo[k];
    }
    return Y;
}

int main() {
    vector<Z> a{1, 2, 3, 4};

    vector<Z> c = DFT(a);
    cout << "DFT Result : " << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << c[i].real() << " + " << c[i].imag() << "i" << endl;
    }
    cout << endl;

    vector<Z> b = FFT(a);
    cout << "FFT Result : " << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << b[i].real() << " + " << b[i].imag() << "i" << endl;
    }

    return 0;
}



