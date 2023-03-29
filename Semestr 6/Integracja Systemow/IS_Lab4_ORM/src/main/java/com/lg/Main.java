package com.lg;

import jakarta.persistence.EntityManager;
import jakarta.persistence.EntityManagerFactory;
import jakarta.persistence.Persistence;
import jakarta.persistence.Query;

import java.util.List;

public class Main {
    public static void main(String[] args) {
        System.out.println("JPA project");
        EntityManagerFactory factory = Persistence.createEntityManagerFactory("Hibernate_JPA");
        EntityManager em = factory.createEntityManager();
        em.getTransaction().begin();
        User u1 = new User(null, "test_1","test_1","Andrzej",
                "Kowalski", Sex.MALE);
        User u2 = new User(null, "test_2","test_2","Adam",
                "Kowalski", Sex.MALE);
        User u3 = new User(null, "test_3","test_3","Jakub",
                "Dudek", Sex.MALE);
        User u4 = new User(null, "test_4","test_4","Andrzej",
                "Nowak", Sex.MALE);
        User u5 = new User(null, "test_5","test_5","Grażyna",
                "Nowak", Sex.FEMALE);
        Role r1 = new Role(null, "Admin");
        Role r2 = new Role(null, "User");
        Role r3 = new Role(null, "Guest");
        Role r4 = new Role(null, "Mod");
        Role r5 = new Role(null, "Owner");
        em.persist(u1);
        em.persist(u2);
        em.persist(u3);
        em.persist(u4);
        em.persist(u5);
        em.persist(r1);
        em.persist(r2);
        em.persist(r3);
        em.persist(r4);
        em.persist(r5);
        em.getTransaction().commit();

        User userUpdate = em.find(User.class, 1);
        if (userUpdate != null) {
            userUpdate.setPassword("123456789");
            em.getTransaction().begin();
            em.merge(userUpdate);
            em.getTransaction().commit();
        }

        Role roleDelete = em.find(Role.class, 5);
        if (roleDelete != null) {
            em.getTransaction().begin();
            em.remove(roleDelete);
            em.getTransaction().commit();
        }

        em.getTransaction().begin();
        Query query = em.createQuery("SELECT u FROM User u WHERE u.lastName = 'Kowalski'");
        List<User> kowalscy = query.getResultList();
        em.getTransaction().commit();

        System.out.println("Z nazwiskiem Kowalski:");
        for(User u : kowalscy) {
            System.out.println(u.getFirstName() + " " + u.getLastName());
        }

        em.getTransaction().begin();
        query = em.createQuery("SELECT u FROM User u WHERE u.sex = 'FEMALE'");
        List<User> kobiety = query.getResultList();
        em.getTransaction().commit();

        System.out.println("Wszystkie kobiety:");
        for(User u : kobiety) {
            System.out.println(u.getFirstName() + " " + u.getLastName());
        }

        User u6 = new User(null, "test_6","test_6","Adam",
                "Małysz", Sex.MALE);
        u6.addRole(r1);
        u6.addRole(r2);

        em.getTransaction().begin();
        em.persist(u6);
        em.getTransaction().commit();

        em.getTransaction().begin();
        UsersGroup g1 = new UsersGroup();
        UsersGroup g2 = new UsersGroup();
        g1.getUsers().add(u1);
        g1.getUsers().add(u2);
        g2.getUsers().add(u2);
        g2.getUsers().add(u3);
        em.persist(g1);
        em.persist(g2);
        em.getTransaction().commit();

        em.close();
        factory.close();
    }
}
