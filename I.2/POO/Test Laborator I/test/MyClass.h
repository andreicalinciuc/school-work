#include <iostream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class Song;

class ComparatorSongByYear
{
  public:
	bool operator() (const Song a, const Song b);
};

class Song
{
  public:
	string artist;
	string title;
	int year;
	Song();
	Song (string _artist, string _title, int _year);
	string PrintSong();
};

class SongCollection
{
	Song collection[100];
	int count;
  public:
    SongCollection ();
    SongCollection (initializer_list <Song> args);
    SongCollection& operator += (const Song& S);
    SongCollection& operator = (SongCollection& S);
    Song* begin();
    Song* end();
    SongCollection operator () (int index, int size);
	set <Song, ComparatorSongByYear> GetSongsByArtist (string _artist);
	vector <Song> GetSongsByYear (int _year);
};
