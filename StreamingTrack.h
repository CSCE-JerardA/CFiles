// Copyright 2025 JC

#ifndef STREAMING_TRACK_H
#define STREAMING_TRACK_H

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {

class StreamingTrack : public SongRecording {

  private:
    int stream_count_;
    std::string* genres_;
    int num_genres_;

  public:

    // Constructor with 6 parameters (defaults)
    StreamingTrack(std::string title = "untitled",
		   std::string primary_artist = "unknown",
                   int track_length = 0,
		   int num_artists = 1,
		   std::string primary_genre = "pop",
		   int streams = 0);


    // Constructor from a SongRecording
    StreamingTrack(const SongRecording& song,
		   std::string primary_genre = "pop",
		   int streams = 0);


    // Copy Constructor
    StreamingTrack(const StreamingTrack& other);


    StreamingTrack& operator=(const StreamingTrack& other);

    // Destructor
    ~StreamingTrack();

    // Stream Getters and Setters
    int GetStreams() const;
    void SetStreams(int);
    void AddStreams(int);


    int GetNumGenres() const;
    std::string GetGenre(int index =1) const;
    bool IsGenre(std::string) const;
    void AddGenre(std::string);
    void RemoveGenre(std::string);

};


}  // namespace_csce240_programming_assignment_5

#endif
