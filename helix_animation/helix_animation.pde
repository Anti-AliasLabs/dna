

Light[] lights;
int numLights = 28;
int[] brightnesses = { 
  100, 100, 100, 100, 100, 100, 100, 
  100, 120, 150, 200, 150, 120, 100, 
  100, 100, 100, 100, 100, 100, 100, 
  100, 120, 150, 200, 150, 120, 100
};
int[] dir;

void setup() {
  size( 400, 750 );
  frameRate(20);
  noStroke();
  smooth();

  //brightnesses = new int[numLights];
  dir = new int[numLights];

  lights = new Light[numLights];
  for ( int i=0; i<numLights; i++ ) {
    lights[i] = new Light( width/2, (height-50)/numLights*i+40, brightnesses[i] );
    dir[i] = 1;
  }
}

void draw() {
  background(10, 0, 100);
  for ( int i=0; i<numLights; i++ ) {
    lights[i].draw();
  }

  updateLights();
}

void updateLights() {
  
  for ( int i=0; i<numLights-1; i++ ) {
    brightnesses[i] = brightnesses[i+1];
  }
  brightnesses[27] = brightnesses[0];
  
  for ( int i=0; i<numLights; i++ ) {
    lights[i].updateBrightness(brightnesses[i]);
  }
  println(brightnesses[10]);
}

