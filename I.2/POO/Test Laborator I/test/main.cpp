#include "MyClass.h"
#include <iostream>

using namespace std;

int main()
{
	Song s1 ("The Temper Trap", "Soldier", 2002);
	Song s2 ("The Black Keys", "Turn Blue", 2001);
	Song s3 ("The Black Keys", "Weight of love", 2002);
	SongCollection sc = {s1, s2};
	sc += s3;
	for (auto s : sc)
	{
		cout << s.PrintSong() << endl;
	}
	auto songsArtist = sc.GetSongsByArtist ("The Black Keys");
	auto songsYear = sc.GetSongsByYear (2002);
	SongCollection sc2 = sc (1, 2);
	return 0;
}

