// Label (start by showing listening)
let label = "listening";
let confidence;
// Global variable to store the classifier
let classifier;

// Teachable Machine model URL:
let ModelURL = 'https://teachablemachine.withgoogle.com/models/1VFGSx7BS/';

//src="https://www.gstatic.com/firebasejs/7.13.2/firebase-app.js"

 var firebaseConfig = {
    apiKey: "AIzaSyAIRFvX5HPsCbqlmTZ8Q1n0R1YjljIZJBI",
    authDomain: "final-project-ac183.firebaseapp.com",
    databaseURL: "https://final-project-ac183.firebaseio.com",
    projectId: "final-project-ac183",
    storageBucket: "final-project-ac183.appspot.com",
    messagingSenderId: "958472231173",
    appId: "1:958472231173:web:57d42f9d729321bff8bf6c"
  };
  // Initialize Firebase
  firebase.initializeApp(firebaseConfig);
  var ref = firebase.database().ref("/");

function preload() {
  // Load the model
  classifier = ml5.soundClassifier(ModelURL + 'model.json');
}

function setup() {
  createCanvas(320, 240);
  // Start classifying
  // The sound model will continuously listen to the microphone
  classifier.classify(gotResult);
}

function draw() {
  background(0);
  // Draw the label in the canvas
  fill(255);
  textSize(32);
  textAlign(CENTER, CENTER);
  if (confidence > 0.8){
  text(label, width / 2, height / 2);
  upload();
  }
  else if (confidence < 0.8){
  text("background", width / 2, height / 2);
  }
}

// The model recognizing a sound will trigger this event
function gotResult(error, results) {
  if (error) {
    console.error(error);
    return;
  }
  // The results are in an array ordered by confidence.
   console.log(results[0]);
  label = results[0].label;
  confidence = results[0].confidence;
}

function upload(){
  console.log("function works");
  if (label == "Red"){
  ref.update({
    "Red" : "ON"
    });
  }
  else if (label != "Red"){
  ref.update({
    "Red" : "OFF"
    });
  }
  if (label == "Orange"){
  ref.update({
    "Orange" : "ON"
    });
  }
}