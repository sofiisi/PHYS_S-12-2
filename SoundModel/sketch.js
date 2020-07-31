// Label (start by showing listening)
let label = "listening";
let confidence;
// Global variable to store the classifier
let classifier;

// Teachable Machine model URL:
let ModelURL = 'https://teachablemachine.withgoogle.com/models/1VFGSx7BS/';


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
  }
  else if (confidence < 0.8){
  text("background", width / 2, height / 2);
  }
}
//var firebaseConfig = {
  
//};

// Initialize Firebase
//firebase.initializeApp(firebaseConfig);

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