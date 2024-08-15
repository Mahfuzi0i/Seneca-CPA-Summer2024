/**
 * WEB222 – Assignment 04
 *
 * I declare that this assignment is my own work in accordance with
 * Seneca Academic Policy. No part of this assignment has been
 * copied manually or electronically from any other source
 * (including web sites) or distributed to other students.
 *
 * Please update the following with your information:
 *
 *      Name:       <Abdullah Al Mahfuz>
 *      Student ID: <180377236>
 *      Date:       <06 July 2024 (Saturday)>
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
window.onload = function () {
  const { artists, songs } = window;

  // Selecting the necessary DOM elements.
  const menu = document.getElementById("menu");
  const tbody = document.getElementById("songs");
  const selectedArtist = document.getElementById("selected-artist");
  const artistLinks = document.getElementById("artist-links");

  // For debugging, display all of our data in the console. You can remove this later.
  console.log({ artists, songs }, "App Data");

  // Function to dynamically create menu buttons for each artists
  artists.forEach((artist) => {
    const button = document.createElement("button");
    button.textContent = artist.name;
    button.addEventListener("click", () => {
      showArtistSongs(artist.artistId);
    });
    menu.appendChild(button);
  });

  // Function to display songs of a selected artist
  function showArtistSongs(artistId) {
    // Find the selected artist
    const artist = artists.find((a) => a.artistId === artistId);
    if (!artist) return;

    // Update the selected artist title
    selectedArtist.textContent = artist.name;

    // Clear the existing links
    artistLinks.innerHTML = "";

    // create anchor elements for artist links
    artist.urls.forEach((link) => {
      const anchor = document.createElement("a");
      anchor.href = link.url;
      anchor.textContent = link.name;
      anchor.target = "_blank"; // Open the link in a new tab
      artistLinks.appendChild(anchor);
      artistLinks.appendChild(document.createTextNode(" "));
    });

    // Clear existing songs in the table body
    tbody.innerHTML = "";

    // Filter songs based on the selected artist and non-explicit songs
    const filteredSongs = songs.filter((song) => song.artistId === artistId && !song.explicit);

    // Populate the table with filtered songs
    filteredSongs.forEach((song) => {
      const tr = document.createElement("tr");

      // Click event listener on the song row to log song details
      tr.addEventListener("click", () => {
        console.log(song);
      });

      // create table cells for song details
      const tdTitle = document.createElement("td");
      const titleLink = document.createElement("a");
      titleLink.href = song.url;
      titleLink.textContent = song.title;
      titleLink.target = "_blank"; // Open the link in a new tab
      tdTitle.appendChild(titleLink);

      const tdYear = document.createElement("td");
      tdYear.textContent = song.year;

      const tdDuration = document.createElement("td");
      const minutes = Math.floor(song.duration / 60);
      const seconds = song.duration % 60;
      tdDuration.textContent = `${minutes}:${seconds.toString().padStart(2, "0")}`;

      // Append table cells to the table row
      tr.appendChild(tdTitle);
      tr.appendChild(tdYear);
      tr.appendChild(tdDuration);

      // Append table row to the table body
      tbody.appendChild(tr);
    });
  }

  // Show songs of the first artist by default on page load
  if (artists.length > 0) {
    showArtistSongs(artists[0].artistId);
  }
};
