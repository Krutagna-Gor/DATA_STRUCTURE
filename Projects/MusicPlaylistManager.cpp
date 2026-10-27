#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

struct Song
{
    string title;
    string artist;
    bool favorite;
    Song* next;
    Song* previous;
};

// Convert text to lowercase
string toLowerCase(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = tolower((unsigned char)text[i]);
    }

    return text;
}

class Playlist
{
private:
    Song* first;
    Song* current;
    int songCount;
    bool repeatMode;

    // Find a song using its position
    Song* getSongByNumber(int number)
    {
        if (number < 1 || number > songCount)
            return NULL;

        Song* temp = first;

        for (int i = 1; i < number; i++)
        {
            temp = temp->next;
        }

        return temp;
    }

public:
    Playlist()
    {
        first = NULL;
        current = NULL;
        songCount = 0;
        repeatMode = false;
    }

    // Add a new song
    void createSong()
    {
        Song* newSong = new Song;

        cout << "\nEnter Song Title (no spaces): ";
        cin >> newSong->title;

        cout << "Enter Artist Name (no spaces): ";
        cin >> newSong->artist;

        newSong->favorite = false;

        if (first == NULL)
        {
            first = newSong;
            newSong->next = newSong;
            newSong->previous = newSong;
            current = newSong;
        }
        else
        {
            Song* last = first->previous;

            newSong->next = first;
            newSong->previous = last;

            last->next = newSong;
            first->previous = newSong;
        }

        songCount++;

        cout << "\nSong Added Successfully!\n";
    }

    // Display all songs with numbers
    void displayPlaylist()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        Song* temp = first;
        int number = 1;

        cout << "\n========== YOUR PLAYLIST ==========\n";

        do
        {
            cout << "\nSong Number: " << number;
            cout << "\nTitle: " << temp->title;
            cout << "\nArtist: " << temp->artist;

            if (temp == current)
                cout << "\nStatus: Currently Selected";

            if (temp->favorite)
                cout << "\nFavorite: Yes";

            cout << "\n-----------------------------------";

            temp = temp->next;
            number++;

        } while (temp != first);

        cout << endl;
    }

    // Display currently selected song
    void playCurrentSong()
    {
        if (current == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        cout << "\nNow Playing: " << current->title;
        cout << "\nArtist: " << current->artist << endl;
    }

    // Play next song
    void playNextSong()
    {
        if (current == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        if (repeatMode)
        {
            cout << "\nRepeat Mode ON!";
            cout << "\nRepeating Current Song: "
                 << current->title << endl;
            return;
        }

        current = current->next;

        cout << "\nPlaying Next Song: "
             << current->title << endl;
    }

    // Play previous song
    void playPreviousSong()
    {
        if (current == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        if (repeatMode)
        {
            cout << "\nRepeat Mode ON!";
            cout << "\nRepeating Current Song: "
                 << current->title << endl;
            return;
        }

        current = current->previous;

        cout << "\nPlaying Previous Song: "
             << current->title << endl;
    }

    // Show total songs
    void showTotalSongs()
    {
        cout << "\nTotal Songs: " << songCount << endl;
    }

    // Search using part of a title
    void searchSong()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        string keyword;

        cout << "\nEnter song name or a few letters: ";
        cin >> keyword;

        keyword = toLowerCase(keyword);

        Song* temp = first;
        int number = 1;
        int matches = 0;

        cout << "\n========== SEARCH RESULTS ==========\n";

        do
        {
            string title = toLowerCase(temp->title);

            if (title.find(keyword) != string::npos)
            {
                cout << "\nSong Number: " << number;
                cout << "\nTitle: " << temp->title;
                cout << "\nArtist: " << temp->artist << endl;

                matches++;
            }

            temp = temp->next;
            number++;

        } while (temp != first);

        if (matches == 0)
            cout << "\nNo Matching Songs Found!\n";
        else
            cout << "\nTotal Matches: " << matches << endl;
    }

    // Delete a song by its exact title
    void deleteSong()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        string songTitle;

        cout << "\nEnter Exact Song Title to Delete: ";
        cin >> songTitle;

        songTitle = toLowerCase(songTitle);

        Song* temp = first;

        do
        {
            if (toLowerCase(temp->title) == songTitle)
            {
                if (songCount == 1)
                {
                    first = NULL;
                    current = NULL;
                }
                else
                {
                    temp->previous->next = temp->next;
                    temp->next->previous = temp->previous;

                    if (first == temp)
                        first = temp->next;

                    if (current == temp)
                        current = temp->next;
                }

                delete temp;
                songCount--;

                cout << "\nSong Deleted Successfully!\n";
                return;
            }

            temp = temp->next;

        } while (temp != first);

        cout << "\nSong Not Found!\n";
    }

    // Mark or unmark a favorite song
    void markFavorite()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        displayPlaylist();

        int number;

        cout << "\nEnter Song Number: ";
        cin >> number;

        Song* temp = getSongByNumber(number);

        if (temp == NULL)
        {
            cout << "\nInvalid Song Number!\n";
            return;
        }

        temp->favorite = !temp->favorite;

        if (temp->favorite)
            cout << "\nAdded to Favorites!\n";
        else
            cout << "\nRemoved from Favorites!\n";
    }

    // Display favorite songs
    void displayFavorites()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        Song* temp = first;
        int matches = 0;

        cout << "\n========== FAVORITE SONGS ==========\n";

        do
        {
            if (temp->favorite)
            {
                cout << "\nTitle: " << temp->title;
                cout << "\nArtist: " << temp->artist << endl;
                matches++;
            }

            temp = temp->next;

        } while (temp != first);

        if (matches == 0)
            cout << "\nNo Favorite Songs Yet!\n";
    }

    // Select a song by number
    void playBySongNumber()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        displayPlaylist();

        int number;

        cout << "\nEnter Song Number to Play: ";
        cin >> number;

        Song* temp = getSongByNumber(number);

        if (temp == NULL)
        {
            cout << "\nInvalid Song Number!\n";
            return;
        }

        current = temp;

        playCurrentSong();
    }

    // Shuffle to a random song
    void shufflePlaylist()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        int number = rand() % songCount + 1;

        current = getSongByNumber(number);

        cout << "\nShuffled Successfully!";
        cout << "\nRandom Song: " << current->title << endl;
    }

    // Turn repeat mode on or off
    void toggleRepeat()
    {
        repeatMode = !repeatMode;

        if (repeatMode)
            cout << "\nRepeat Mode: ON\n";
        else
            cout << "\nRepeat Mode: OFF\n";
    }

    // Release all dynamically allocated memory
    ~Playlist()
    {
        while (first != NULL)
        {
            Song* temp = first;

            if (songCount == 1)
            {
                first = NULL;
            }
            else
            {
                first = first->next;
                first->previous = temp->previous;
                temp->previous->next = first;
            }

            delete temp;
            songCount--;
        }

        current = NULL;
    }
};

int main()
{
    srand((unsigned int)time(NULL));

    Playlist myPlaylist;
    int choice;
    char continueChoice;

    do
    {
        cout << "\n====================================\n";
        cout << "       MUSIC PLAYLIST MANAGER\n";
        cout << "====================================\n";

        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Current Song\n";
        cout << "4. Play Next Song\n";
        cout << "5. Play Previous Song\n";
        cout << "6. Show Total Songs\n";
        cout << "7. Delete Song\n";
        cout << "8. Smart Search\n";
        cout << "9. Mark / Unmark Favorite\n";
        cout << "10. Display Favorite Songs\n";
        cout << "11. Play by Song Number\n";
        cout << "12. Shuffle Playlist\n";
        cout << "13. Toggle Repeat Mode\n";

        cout << "\nEnter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                myPlaylist.createSong();
                break;

            case 2:
                myPlaylist.displayPlaylist();
                break;

            case 3:
                myPlaylist.playCurrentSong();
                break;

            case 4:
                myPlaylist.playNextSong();
                break;

            case 5:
                myPlaylist.playPreviousSong();
                break;

            case 6:
                myPlaylist.showTotalSongs();
                break;

            case 7:
                myPlaylist.deleteSong();
                break;

            case 8:
                myPlaylist.searchSong();
                break;

            case 9:
                myPlaylist.markFavorite();
                break;

            case 10:
                myPlaylist.displayFavorites();
                break;

            case 11:
                myPlaylist.playBySongNumber();
                break;

            case 12:
                myPlaylist.shufflePlaylist();
                break;

            case 13:
                myPlaylist.toggleRepeat();
                break;

            default:
                cout << "\nInvalid Choice! Try Again.\n";
        }

        cout << "\nDo you want to continue? (Y/N): ";
        cin >> continueChoice;

    } while (continueChoice == 'Y' ||
             continueChoice == 'y');

    cout << "\nThank You for Using Music Playlist Manager!\n";

    return 0;
}