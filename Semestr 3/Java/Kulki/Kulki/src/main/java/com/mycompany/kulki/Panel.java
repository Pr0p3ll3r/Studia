package com.mycompany.Kulki;

import java.awt.Color;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import javax.swing.JPanel;
import javax.swing.Timer;

public class Panel extends JPanel {

    private ArrayList<Kula> listaKul;
    private int size = 20;
    private Timer timer;
    private final int DELAY = 33;
    private Pisarz pisarz;
    //dla 30fps -> 1s/30 = 0,033s

    public Panel() {
        listaKul = new ArrayList<>();
        setBackground(Color.BLACK);
        pisarz = new Pisarz();
        addMouseListener(new Event());

        timer = new Timer(DELAY, new Event());
        timer.start();
        
        pisarz.prostyOdczyt("Plik.txt", listaKul);
        repaint();
    }

    @Override
    protected void paintComponent(Graphics g) {
        super.paintComponent(g);

        for (Kula k : listaKul) {
            g.setColor(k.color);
            g.drawOval(k.x, k.y, k.size, k.size);
        }
        g.setColor(Color.YELLOW);
        g.drawString(Integer.toString(listaKul.size()), 40, 40);
    }

    private class Event implements MouseListener,
            ActionListener {

        @Override
        public void mouseClicked(MouseEvent e) {
        }

        @Override
        public void mousePressed(MouseEvent e) {
            listaKul.add(new Kula(e.getX(), e.getY(), size));
            repaint();
        }

        @Override
        public void mouseReleased(MouseEvent e) {
        }

        @Override
        public void mouseEntered(MouseEvent e) {
        }

        @Override
        public void mouseExited(MouseEvent e) {
        }

        @Override
        public void actionPerformed(ActionEvent e) {
            for (Kula k : listaKul) {
                //k.update();
                String linia="";
                if (k.x <= 0 || k.x >= getWidth()) {
                    linia=k.x+":"+k.y+":"+k.size+"\n";
                    pisarz.prostyZapis(linia);
                }
                if (k.y <= 0 || k.y >= getHeight()) {
                    linia=k.x+":"+k.y+":"+k.size+"\n";
                    pisarz.prostyZapis(linia);
                }
            }
            repaint();
        }
    }
}