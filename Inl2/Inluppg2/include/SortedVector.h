#ifndef SORTEDVECTOR_H
#define SORTEDVECTOR_H
#include <stdexcept>
#include <iostream>

template <class T, int sz>  class SortedVector
{
    private:
        int size_total;
        int size_curr;
        T vec[sz];

    public:
        SortedVector() : size_curr(0), size_total(sz) { }
        SortedVector(const T &v, int s);
        ~SortedVector();
        bool add ( const T &v );
        SortedVector& median ();
        void sortVec();
        void removeLarger( const T& v );
        void print( ostream & os );
        int getSizeTotal() const { return size_total; }
        int getSizeCurr() const { return size_curr; }
        SortedVector& operator+=( const T &v );
        T& operator[](int ix);
        friend ostream & operator<<( ostream & out, const SortedVector & v );

    protected:

};

template <class T, int sz> SortedVector<T,sz>::SortedVector( const T &v, int s) : size_curr(v.size), size_total(2 * s), vec(new T[size_total])

{
    cout << "Skapar en sortedVector med polygoner" << endl;
    for (int i=0;i < size_curr: i++) vec[i] = v.vec[i];
    sortVec();

}

template <class T, int sz> SortedVector<T,sz>::~SortedVector()
{
    delete[] vec;
}

template <class T, int sz>  bool SortedVector<T,sz>::add ( const T &v )
{
    cout << "Lägger till en polygon" << endl;
    if (size_curr >= size_total) return false;

    size_curr++;
    vec[size_curr] = v;
    sortVec();

    return true
}
 template <class T, int sz> SortedVector<T,sz>& SortedVector<T,sz>::median ()
 {
   // Beräkna mittersta polygonen
   //
   cout << "Hittar mittersta polygonen" << endl;
 }

template <class T, int sz> void SortedVector<T,sz>::removeLarger( const T& v )
{
    // Identifiera polygon med största ytan
    // Ta bort den polygonen, minska size_curr med ett
    cout << "Tar bort största polygonen" << endl;
}

template <class T, int sz> void SortedVector<T,sz>::sortVec()
{
    // Sortera vektorn i polygonernas storleksordning
    cout << "Sorterar i storleksordning" << endl;
}

template <class T, int sz> void SortedVector<T,sz>::print( ostream &os )
{
    // Skriver ut polygoner
    cout << "Skriver ut polygoner" << endl;
}

template <class T, int sz> int SortedVector<T,sz>::getSizeTotal() const { return size_total; }

template <class T, int sz> int SortedVector<T,sz>::getSizeCurr() const { return size_curr; }

template <class T, int sz> SortedVector<T,sz>& SortedVector<T,sz>::operator+=( const T &v )
{
    // Adderar en vector till en annan
    cout << "Adderar vectorer" << endl;
}
template <class T, int sz> SortedVector<T,sz>& SortedVector<T,sz>::operator[](int ix)
{
    //Indexoperation på vectorklassen, kontroll innanför "ramar"
    cout << "Returnerar polygon i begärt index" << endl;
    return vec[ix];
}

template <class T, int sz> ostream & operator<<( ostream & out, const SortedVector<T,sz> & v )
{
    out << "{" << endl;

    return out;
}

#endif // SORTEDVECTOR_H
