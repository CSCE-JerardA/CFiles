
// Copyright Jerard 2025

#include "SongRecording.h"

namespace csce240_programming_assignment_5 {


// Constructor
SongRecording::SongRecording(std::string title, std::string primary_artist,
			     int track_length, int num_artists) : title_("untitled"), artists_(nullptr), num_artists_(1), track_length_(0) {

  SetTitle(title);
  SetNumArtists(num_artists);
  SetArtist(primary_artist, 1);
  SetTrackLength(track_length);

}

// Copy Constructor
SongRecording::SongRecording(const SongRecording& other)
    : title_(other.title_), num_artists_(other.num_artists_), track_length_(other.track_length_) {
  artists_ = new std::string[num_artists_];
  for (int i = 0; i < num_artists_; ++i)
    artists_[i] = other.artists_[i];
}


// Assignment operator
SongRecording& SongRecording::operator=(const SongRecording& other) {
  if (this != &other) {
    title_ = other.title_;
    track_length_ = other.track_length_;

    delete[] artists_;

    num_artists_ = other.num_artists_;
    artists_ = new std::string[num_artists_];
    for (int i = 0; i < num_artists_; ++i)
      artists_[i] = other.artists_[i];
  }
  return *this;

}

// Destructor
SongRecording::~SongRecording() {
  delete[] artists_;
}


// GetTitle
std::string SongRecording::GetTitle() const {
  return title_;
}

// SetTitle
void SongRecording::SetTitle(std::string title) {
  if (title.length() >= 1)
    title_ = title;
}

// GetNumArtists
int SongRecording::GetNumArtists() const {
  return num_artists_;
}

// SetNumArtists
void SongRecording::SetNumArtists(int num_artists) {
  if (num_artists > 0) {
    std::string* new_artists = new std::string[num_artists];

    int min_size = (artists_ != nullptr) ? (num_artists_ < num_artists ? num_artists_ : num_artists) : 0;
    for (int i = 0; i < min_size; ++i)
      new_artists[i] = artists_[i];


    delete[] artists_;
    artists_ = new_artists;
    num_artists_ = num_artists;
  }

}

// SetArtist
void SongRecording::SetArtist(std::string artist, int index) {
  if (artist.length() >= 1 && index <= num_artists_) {
    artists_[index - 1] = artist;
  }
}


// GetArtist
std::string SongRecording::GetArtist(int index) const {
  if (index >= 1 && index <= num_artists_)
    return artists_[index - 1];
  return "out of bounds";
}


// GetTrackLength
int SongRecording::GetTrackLength() const {
  return track_length_;
}


// SetTrackLength 
void SongRecording::SetTrackLength(int length) {
  if (length >= 0)
    track_length_ = length;
}

} // namespace csce240_programming_assignment_5
