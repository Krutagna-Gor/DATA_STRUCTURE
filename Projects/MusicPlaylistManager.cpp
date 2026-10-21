#include <iostream>
#include <string>
using namespace std;

struct Song
{
    string title;
    string artist;
    struct Song* next;
    struct Song* previous;
};

class Playlist
{
private:
    struct Song* first;
    struct Song* current;
    int songCount;

public:
    Playlist()
    {
        first = NULL;
        current = NULL;
        songCount = 0;
    }

    void createSong()
    {
        Song* newSong = new Song;

        cout << "\nEnter Song Title: ";
        cin >> newSong->title;

        cout << "Enter Artist Name: ";
        cin >> newSong->artist;

        if (first == NULL)
        {
            first = newSong;
            newSong->next = newSong;
            newSong->previous = newSong;
            current = newSong;
        }
        else
        {
            struct Song* last = first->previous;

            newSong->next = first;
            newSong->previous = last;

            last->next = newSong;
            first->previous = newSong;
        }

        songCount++;

        cout << "\nSong Added Successfully!\n";
    }

    void displayPlaylist()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        struct Song* temp = first;

        cout << "\n===== MUSIC PLAYLIST =====\n";

        do
        {
            cout << "\nSong Title: " << temp->title;
            cout << "\nArtist Name: " << temp->artist;

            if (temp == current)
                cout << "\nStatus: Currently Playing";

            cout << "\n-------------------------";

            temp = temp->next;

        } while (temp != first);

        cout << endl;
    }

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

    void playNextSong()
    {
        if (current == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        current = current->next;

        cout << "\nPlaying Next Song: "
             << current->title << endl;
    }

    void playPreviousSong()
    {
        if (current == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        current = current->previous;

        cout << "\nPlaying Previous Song: "
             << current->title << endl;
    }

    void showTotalSongs()
    {
        cout << "\nTotal Songs in Playlist: "
             << songCount << endl;
    }

    void deleteSong()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        string songTitle;

        cout << "\nEnter Song Title to Delete: ";
        cin >> songTitle;

        struct Song* temp = first;

        do
        {
            if (temp->title == songTitle)
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

    void searchSong()
    {
        if (first == NULL)
        {
            cout << "\nPlaylist Is Empty!\n";
            return;
        }

        string songTitle;

        cout << "\nEnter Song Title to Search: ";
        cin >> songTitle;

        struct Song* temp = first;

        do
        {
            if (temp->title == songTitle)
            {
                cout << "\nSong Found!";
                cout << "\nSong Title: " << temp->title;
                cout << "\nArtist Name: " << temp->artist << endl;
                return;
            }

            temp = temp->next;

        } while (temp != first);

        cout << "\nSong Not Found!\n";
    }

    ~Playlist()
    {
        while (first != NULL)
        {
            struct Song* temp = first;

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
    Playlist myPlaylist;
    int choice;
    char continueChoice;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Display Playlist\n";
        cout << "3. Play Current Song\n";
        cout << "4. Play Next Song\n";
        cout << "5. Play Previous Song\n";
        cout << "6. Show Total Songs\n";
        cout << "7. Delete Song\n";
        cout << "8. Search Song\n";

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