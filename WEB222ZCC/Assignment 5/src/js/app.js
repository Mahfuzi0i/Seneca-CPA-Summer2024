/**
 * WEB222 – Assignment 05
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
 *      Date:       <20 July 2024 (Saturday)>
 */

// All of our data is available on the global `window` object.
// Create local variables to work with it in this file.
const { artists, songs } = window;

// For debugging, display all of our data in the console. You can remove this later.
//console.log({ artists, songs }, "App Data");

document.addEventListener("DOMContentLoaded", function () {
  const menu = document.querySelector("#menu");
  const artistDetails = document.querySelector("#selected-artist");
  const songList = document.querySelector(".card-container");

  function createArtistButton(artist) {
    const button = document.createElement("button");
    button.textContent = artist.name;
    // On click of the artist button, show the artist's info and songs
    button.addEventListener("click", function () {
      showArtistInfo(artist);
      showSongs(artist.artistId);
    });
    // Append the button to the menu
    menu.appendChild(button);
    return button; // Return the button for further use
  }

  function showArtistInfo(artist) {
    // Name of the artist
    artistDetails.innerHTML = "";
    const artistInfo = document.createElement("div");
    artistInfo.classList.add("artist-info");

    const artistImage = document.createElement("img");
    artistImage.classList.add("artist-image");
    artistImage.src = artist.artistImageUrl;
    artistInfo.appendChild(artistImage);

    const artistNameSocials = document.createElement("div");
    artistNameSocials.classList.add("artist-name-socials");

    const artistName = document.createElement("h3");
    artistName.classList.add("artist-name");
    artistName.textContent = artist.name;
    artistNameSocials.appendChild(artistName);

    const socials = document.createElement("div");
    socials.classList.add("socials");

    artist.urls.forEach((link) => {
      //Create a link to the artist's page

      const a = document.createElement("a");
      a.classList.add("social-link");
      a.href = link.url; //href is the url of the link
      a.target = "_blank"; //Open the link in a new tab

      const img = document.createElement("img");
      img.classList.add("social-link-image");
      if (link.name === "Website,") {
        img.src =
          "https://lh3.googleusercontent.com/vdKbcWCGwxtvvoZG5LK-rQcix_6mXl7Z2zzVil3ggiZ6hUETgtSVdbw0hrNAbRoCTCuSt_yn4EJrBS5XzILlYBxGIhMuikJ9nVt1HVA5nI76zA5ludsdTQF9t-ANf4lZPV7Wli9JzTrA8fj1wa5YAgcza7EK1Y8uqcj92Hjm1jaJJ10OJAkdaQg6oB7lKQ";
      } else if (link.name === "Facebook,") {
        img.src = "https://upload.wikimedia.org/wikipedia/commons/6/6c/Facebook_Logo_2023.png";
      } else if (link.name === "Instagram,") {
        img.src =
          "https://upload.wikimedia.org/wikipedia/commons/thumb/9/95/Instagram_logo_2022.svg/1200px-Instagram_logo_2022.svg.png";
      } else if (link.name === "X") {
        img.src =
          "https://banner2.cleanpng.com/20240119/sut/transparent-x-logo-logo-brand-identity-company-organization-black-background-white-x-logo-for-1710916376217.webp";
      }

      a.appendChild(img); //Append the image to the link
      socials.appendChild(a); //Append the link to the socials
    });

    artistNameSocials.appendChild(socials);
    artistInfo.appendChild(artistNameSocials);

    artistDetails.appendChild(artistInfo);
  }

  // For each artist, show the artist's songs
  function showSongs(artistId) {
    songList.innerHTML = "";

    // Filter the songs by the artistId and remove explicit songs
    const filteredSongs = songs.filter((song) => song.artistId === artistId && !song.explicit);

    // For each song, create a card
    filteredSongs.forEach((song) => {
      const card = createSongCard(song);
      // Append the card to the songList
      songList.appendChild(card);
    });
  }

  // Create a song card
  function createSongCard(song) {
    // Create a <div> to hold the card
    const card = document.createElement("div");
    // Add the .card class to the <div>
    card.classList.add("card");

    // Create a song image, use the .card-image class
    const songImg = document.createElement("img");
    songImg.classList.add("card-image");
    songImg.src = song.imageUrl;
    songImg.classList.add("card-image");
    songImg.addEventListener("click", function () {
      window.open(song.url, "_blank");
    });
    card.appendChild(songImg);

    // Create a heading for the song title
    const songTitleLink = document.createElement("a");
    const songTitle = document.createElement("h3");
    songTitleLink.classList.add("card-title");
    songTitleLink.textContent = song.title;
    songTitleLink.href = song.url;
    songTitleLink.target = "_blank";
    songTitle.appendChild(songTitleLink);
    card.appendChild(songTitle);

    const yearDurationDiv = document.createElement("div");
    yearDurationDiv.classList.add("card-year-duration");
    // Create a <time> element for the year recorded
    const songYearDiv = document.createElement("div");
    const songYear = document.createElement("time");
    songYear.classList.add("card-year");
    songYear.textContent = song.year;
    songYearDiv.appendChild(songYear);
    yearDurationDiv.appendChild(songYearDiv);

    // Create a <div> for the duration
    const songDuration = document.createElement("div");
    songDuration.classList.add("card-duration");
    songDuration.textContent = `${Math.floor(song.duration / 60)}:${
      song.duration % 60 < 10 ? "0" : ""
    }${song.duration % 60}`;
    yearDurationDiv.appendChild(songDuration);

    card.appendChild(yearDurationDiv);

    // Return the card’s <div> element to the caller
    return card;
  }

  // Initialize app
  // For each artist, create a button that links to the artist's page
  const artistButtons = artists.map(createArtistButton);

  // Trigger click on the first artist button to show the first artist by default
  if (artistButtons.length > 0) {
    artistButtons[0].click();
  }
});
