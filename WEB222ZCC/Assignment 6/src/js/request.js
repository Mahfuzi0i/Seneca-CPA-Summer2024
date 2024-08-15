// Function to add new social media URL input
function addSocial() {
  const socialMediaContainer = document.getElementById("social-media-container");
  const newInput = document.createElement("input");
  newInput.type = "url";
  newInput.name = "socialMediaUrls";
  newInput.placeholder = "Add another social media URL";
  socialMediaContainer.appendChild(newInput);
}

// Function to add new song/video URL input
function addVideo() {
  const songVideoContainer = document.getElementById("song-video-container");
  const newInput = document.createElement("input");
  newInput.type = "url";
  newInput.name = "songVideoUrls";
  newInput.placeholder = "Add another song/video URL";
  songVideoContainer.appendChild(newInput);
}

// Function to validate URLs
function isValidURL(url) {
  const urlPattern = new RegExp(
    "^(https?:\\/\\/)?" + // protocol
      "((([a-z\\d]([a-z\\d-]*[a-z\\d])*)\\.?)+[a-z]{2,}|" + // domain name
      "((\\d{1,3}\\.){3}\\d{1,3}))" + // OR ip (v4) address
      "(\\:\\d+)?(\\/[-a-z\\d%_.~+]*)*" + // port and path
      "(\\?[;&a-z\\d%_.~+=-]*)?" + // query string
      "(\\#[-a-z\\d_]*)?$",
    "i"
  ); // fragment locator
  return !!urlPattern.test(url);
}

// Function to validate the form
function validateForm() {
  const artistName = document.getElementById("artist-name").value.trim();
  const genre = document.getElementById("genre").value.trim();
  const description = document.getElementById("description").value.trim();
  const socialMediaUrls = document.getElementsByName("socialMediaUrls");
  const songVideoUrls = document.getElementsByName("songVideoUrls");

  // Regular expression to check if input contains at least one alphanumeric character
  const validInputRegex = /[a-zA-Z0-9]/;
  // Regular expression to allow only letters and numbers
  const descriptionRegex = /^[a-zA-Z0-9\s(),.?<>!{}]+$/;

  if (artistName === "" || artistName.match(/^\s+$/) || !validInputRegex.test(artistName)) {
    displayMessage("Artist name cannot be empty, just spaces, or only special characters.");
    return false;
  }

  if (genre === "" || genre.match(/^\s+$/) || !validInputRegex.test(genre)) {
    displayMessage("Genre cannot be empty, just spaces, or only special characters.");
    return false;
  }

  if (description === "" || description.match(/^\s+$/) || !validInputRegex.test(description)) {
    displayMessage("Description cannot be empty, just spaces, or only special characters.");
    return false;
  }

  if (!descriptionRegex.test(description)) {
    displayMessage("Description can only contain alphabetical characters, numbers, and spaces.");
    return false;
  }

  if (description.length < 50) {
    displayMessage("Description must be at least 50 characters long.");
    return false;
  }

  // Validate social media URLs
  for (let i = 0; i < socialMediaUrls.length; i++) {
    const url = socialMediaUrls[i].value.trim();
    if (!isValidURL(url)) {
      displayMessage("Please enter a valid social media URL.");
      return false;
    }
  }

  // Validate song/video URLs
  for (let i = 0; i < songVideoUrls.length; i++) {
    const url = songVideoUrls[i].value.trim();
    if (!isValidURL(url)) {
      displayMessage("Please enter a valid song/video URL.");
      return false;
    }
  }

  // Check if one of the explicit radio buttons is selected
  const explicitYes = document.getElementById("explicit-yes").checked;
  const explicitNo = document.getElementById("explicit-no").checked;

  if (!explicitYes && !explicitNo) {
    displayMessage("Please specify if the artist contains explicit lyrics.");
    return false;
  }

  return true; // Allow form submission if all checks pass
}

// Function to display messages
function displayMessage(message) {
  const messageContainer = document.getElementById("message-container");
  messageContainer.textContent = message;
  messageContainer.style.display = "block";
}

// Attach functions to window for usage in HTML
window.addSocial = addSocial;
window.addVideo = addVideo;
window.validateForm = validateForm;
