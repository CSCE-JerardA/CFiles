// Copyright Jerard 2025
#ifndef SONG_RECORDING_H
#define SONG_RECORDING_H

#include<string>
#include<iostream>

namespace csce240_programming_assignment_5 {


class SongRecording {
  private:
    std::string title_;
    std::string* artists_;
    int num_artists_;
    int track_length_;

  public:
    // Constructor with defaults

    SongRecording(std::string title = "untitled",
		  std::string primary_artist = "unknown",
		  int track_length = 0,
                  int num_artists = 1);

    // Copy Constructor
    SongRecording(const SongRecording& other);

    // Assignment Operator
    SongRecording& operator=(const SongRecording& other);

    // Destructor
    ~SongRecording();

    // Getters and Setters
    std::string GetTitle() const;
    void SetTitle(std::string title);

    int GetNumArtists() const;
    void SetNumArtists(int num_artists);

    void SetArtist(std::string artist, int index = 1);
    std::string GetArtist(int index = 1) const;

    int GetTrackLength() const;
    void SetTrackLength(int length);

};

}  // namespace csce240_programming_assignment

#endif
