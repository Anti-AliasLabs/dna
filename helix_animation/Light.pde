class Light {
  int x;
  int y;
  int brightness;
  int diameter;

  Light( int xpos, int ypos, int startingBrightness ) {
    x = xpos;
    y = ypos;
    brightness = startingBrightness;
    diameter = 20;
  }

  void updateBrightness( int b ) {
    brightness = b;
  }

  void draw() {
    fill( brightness );
    ellipse( x+20, y, diameter, diameter);
    ellipse( x-20, y, diameter, diameter);
  }
}

