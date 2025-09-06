// Copyright 2025 Jerard

#include "StreamingTrack.h"

namespace csce240_programming_assignment_5 {


// 6 parameter constructor
StreamingTrack::StreamingTrack(std::string title, std::string primary_artist,
			       int track_length, int num_artists,
			       std::string primary_genre, int streams)
	: SongRecording(title, primary_artist, track_length, num_artists),
         stream_count_(0), genres_(nullptr), num_genres_(0) {

  SetStreams(streams);
  genres_ = new std::string[1];
  genres_[0] = primary_genre;
  num_genres_ = 1;

}


// Constructor for SongRecording obj
StreamingTrack::StreamingTrack(const SongRecording& song,
			       std::string primary_genre,
                               int streams)
	: SongRecording(song), stream_count_(0), genres_(nullptr), num_genres_(0) {
  SetStreams(streams);
  genres_ = new std::string[1];
  genres_[0] = primary_genre;
  num_genres_ = 1;

}


// Copy Constructor
StreamingTrack::StreamingTrack(const StreamingTrack& other) : SongRecording(other), stream_count_(other.stream_count_), num_genres_(other.num_genres_) {

  genres_ = new std::string[num_genres_];
  for (int i = 0; i < num_genres_; ++i)
    genres_[i] = other.genres_[i];

}


// Assignment Operator
StreamingTrack& StreamingTrack::operator=(const StreamingTrack& other) {
  if (this != &other) {
    SongRecording::operator=(other);
    stream_count_ = other.stream_count_;


    delete[] genres_;
    num_genres_ = other.num_genres_;
    genres_ = new std::string[num_genres_];
    for (int i = 0; i < num_genres_; ++i)
      genres_[i] = other.genres_[i];

  }
  return *this;
}

// Deconstructor
StreamingTrack::~StreamingTrack() {
  delete[] genres_;
}

// Stream Getters and Setters
int StreamingTrack::GetStreams() const {
  return stream_count_;
}

void StreamingTrack::SetStreams(int count) {
  if (count >= 0)
    stream_count_ = count;
}

void StreamingTrack::AddStreams(int count) {
  if (count >= 0)
    stream_count_ += count;
}


// Genre Getter and Setter Methods
int StreamingTrack::GetNumGenres() const {
  return num_genres_;
}

std::string StreamingTrack::GetGenre(int index) const {
  if (index >= 1 && index <= num_genres_) 
    return genres_[index - 1];
  return "out of bounds";

}


bool StreamingTrack::IsGenre(std::string genre) const {
  for (int i = 0; i < num_genres_; ++i) {
    if(genres_[i] == genre)
      return true;
  }
  return false;
}

void StreamingTrack::AddGenre(std::string genre) {
  if (IsGenre(genre))
    return;


  std::string* new_genres = new std::string[num_genres_ + 1];
  for (int i = 0; i < num_genres_; ++i)
    new_genres[i] = genres_[i];

  new_genres[num_genres_] = genre;
  delete[] genres_;

  genres_ = new_genres;
  num_genres_++;

}

void StreamingTrack::RemoveGenre(std::string genre) {
  if (!IsGenre(genre)) {
    return;
  }

  int new_size = num_genres_ - 1;
  std::string* new_genres = new std::string[new_size];
  int j = 0;


  for (int i = 0; i < num_genres_; ++i) {
    if (genres_[i] != genre) {
      new_genres[j] = genres_[i];
      j++;
    }
  }

  delete[] genres_;
  genres_ = new_genres;
  num_genres_ = new_size;

}

} // namespace csce240_programming_assignment_5


