#ifndef SortVector_H
#define SortVector_H

#include <stdexcept>
#include <iostream>
#include <ostream>

template <class T, int sz>  class SortVector
{
private:
    int mSzTot;
    int mSzCurr;
    T mVecArr[sz];

public:
    SortVector() : mSzCurr(0), mSzTot(sz) { }
    SortVector(const T &v, int s);
    ~SortVector();
    bool add ( const T &v );
    SortVector& median ();
    void sortVectArr();
    void removeLarger( const T& v );
    void print( ostream & os );
    int getSizeTotal() const
    {
        return mSzTot;
    }
    int getSizeCurr() const
    {
        return mSzCurr;
    }
    SortVector& operator+=( const T &v );
    T& operator[](int ix);
    friend std::ostream & operator<<( std::ostream & out, const SortVector & v );

protected:

};

//
template <class T, int sz>
SortVector<T,sz>::SortVector( const T &v, int s) : mSzCurr(v.mSzCurr), mSzTot(2 * s), mVecArr(new T[mSzTot])

{
    cout << "Skapar en SortVector med T-element" << endl;
    for (int i=0; i < mSzCurr; i++) mVecArr[i] = v.mVecArr[i];
    cout << "Sorterar sortVectArr" << endl;
    sortVectArr();

}

template <class T, int sz>
SortVector<T,sz>::~SortVector()
{
    delete[] mVecArr;
}

template <class T, int sz>
bool SortVector<T,sz>::add ( const T &v )
{
    cout << "Lägger till ett element" << endl;
    if (mSzCurr >= mSzTot) return false;

    mSzCurr++;
    mVecArr[mSzCurr] = v;
    sortVectArr();

    return true;
}

template <class T, int sz>
SortVector<T,sz>& SortVector<T,sz>::median ()
{
    // Beräkna mittersta polygonen
    cout << "Hittar mittersta T-elementet" << endl;
    /*int tmpMed = 0;
    if (mSzCurr % 2 == 0)
    {
        tmpMed = mSzCurr / 2;
    } else
        tmpMed = (int) mSzCurr / 2 + 0.5;

    return mVecArr[tmpMed];*/
}

template <class T, int sz>
void SortVector<T,sz>::removeLarger( const T& v )
{
    // Identifiera polygon med största ytan
    // Ta bort den polygonen, minska mSzCurr med ett
    cout << "Tar bort största T-elementet" << endl;
}

template <class T, int sz>
void SortVector<T,sz>::sortVectArr()
{
    // Sortera vektorn i polygonernas storleksordning
    cout << "Sorterar i storleksordning" << endl;
}

template <class T, int sz>
void SortVector<T,sz>::print( ostream &os )
{
    // Skriver ut polygoner
    cout << "Skriver ut T-element" << endl;
}

template <class T, int sz>
SortVector<T,sz>& SortVector<T,sz>::operator+=( const T &v )
{
    // Adderar en mVecArrtor till en annanconst
    cout << "Adderar mVecArrtorer" << endl;
}

template <class T, int sz>
T& SortVector<T,sz>::operator[](int ix)
{
    //Indexoperation på mVecArrtorklassen, kontroll innanför "ramar"
    cout << "Returnerar T-element i begärt index" << endl;
    return mVecArr[ix];
}

template <class T, int sz>
std::ostream & operator<<( std::ostream & out, const SortVector<T,sz>  & v )
{
    out << "{" << endl;
    for( int i = 0; i < v.mSzCurr; i++ )
    {
        out << "  " << v.mVecArr[i] << endl;
    }
    out << "}";

    return out;
}

#endif // SortVector_H
