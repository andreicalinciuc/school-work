#include "MyClass.h"

bool ComparatorSongByYear::operator() (const Song a, const Song b)
{
    return a.year < b.year;
}

Song::Song()
{

}

Song::Song (string _artist, string _title, int _year)
{
    artist = _artist;
    title = _title;
    year = _year;
}

string Song::PrintSong()
{
    return artist + " - " + title + " (" + to_string (year) + ")";
}

SongCollection::SongCollection()
{
    count = 0;
}

SongCollection::SongCollection (initializer_list <Song> args)
{
    count = 0;
    for (auto it : args)
    {
        collection[++count] = it;
    }
}

SongCollection& SongCollection::operator += (const Song& S)
{
    collection[++count] = S;
    return *this;
}

SongCollection& SongCollection::operator = (SongCollection& S)
{
    count = 0;
    for (int i = 1; i <= S.count; ++i)
    {
        collection[++count] = S.collection[i];
    }
    return *this;
}

Song* SongCollection::begin()
{
    return &collection[1];
}

Song* SongCollection::end()
{
    return &collection[count+1];
}

SongCollection SongCollection::operator () (int index, int size)
{
    SongCollection aux;
    for (int i = index; i <= index + size - 1; ++i) 
    {
        aux.collection[++aux.count] = collection[i];
    }
    return aux;
}

set <Song, ComparatorSongByYear> SongCollection::GetSongsByArtist (string _artist)
{
    set <Song, ComparatorSongByYear> aux;
    for (int i = 1; i <= count; ++i)
    {
        if (collection[i].artist == _artist)
        {
            aux.insert (collection[i]);
        }
    }
    return aux;
}

vector <Song> SongCollection::GetSongsByYear (int _year)
{
    vector <Song> aux;
    for (int i = 1; i <= count; ++i)
    {
        if (collection[i].year == _year)
        {
            aux.push_back (collection[i]);
        }
    }
    return aux;
}
