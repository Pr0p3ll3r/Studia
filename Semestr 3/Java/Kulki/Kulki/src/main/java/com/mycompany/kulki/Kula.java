package com.mycompany.Kulki;

import java.awt.Color;

public class Kula {

    public int x, y, size, xspeed, yspeed;
    public Color color;
    private final int MAX_SPEED = 5;

    public Kula(int x, int y, int size) {
        this.x = x;
        this.y = y;
        this.size = size;
        color = new Color((float) Math.random(), (float) Math.random(), (float) Math.random());
        while (xspeed == 0) {
            xspeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
        }
        while (yspeed == 0) {
            yspeed = (int) (Math.random() * MAX_SPEED * 2 - MAX_SPEED);
        }
    }

    public void update() {
        x += xspeed;
        y += yspeed;

        if (x <= 0 || x >= 100) {
            xspeed = -xspeed;

        }
        if (y <= 0 || y >= 100) {
            yspeed = -yspeed;
        }
    }
}
