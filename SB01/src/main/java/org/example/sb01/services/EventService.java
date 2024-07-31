package org.example.sb01.services;

import org.example.sb01.entity.Authors;
import org.example.sb01.entity.AuthorsBooks;
import org.example.sb01.entity.Books;
import org.example.sb01.repositories.ABRepo;
import org.example.sb01.repositories.AuthorsRepo;
import org.example.sb01.repositories.BooksRepo;
import org.springframework.boot.CommandLineRunner;
import org.springframework.boot.context.event.ApplicationContextInitializedEvent;
import org.springframework.boot.context.event.ApplicationReadyEvent;
import org.springframework.boot.context.event.ApplicationStartedEvent;
import org.springframework.context.annotation.Bean;
import org.springframework.context.event.EventListener;
import org.springframework.stereotype.Component;

import java.util.List;
import java.util.Set;

/*
* первоначальная настройка, тут можно сразу запонить базу
* */

@Component
public class EventService {

    @EventListener(ApplicationContextInitializedEvent.class)
    void beefoStart(){
        System.out.println("attention");
    }

    @EventListener(ApplicationStartedEvent.class)
    void atStart(){
        System.out.println("ApplicationStartedEvent");
    }

    //добавим сущьностей

    @Bean
    public CommandLineRunner commandLineRunner(BooksRepo booksRepo,
                                               AuthorsRepo authorsRepo,
                                               ABRepo abRepo) {
        Books b1 = new Books( "Bible");
        Books b2 = new Books("Quran");
        Books b3 = new Books("Avesta");

        Authors a1 = new Authors( "Anton");
        Authors a2 = new Authors( "Zaratushtra");
        Authors a3 = new Authors( "Muhhamad");
        Authors a4 = new Authors( "Moses");

        return args -> {
            booksRepo.saveAll(List.of (b1, b2, b3));

            authorsRepo.saveAll(List.of(a1, a2, a3, a4));

            abRepo.saveAll(List.of(
                    new AuthorsBooks(new Long(1),a1,b1),
                    new AuthorsBooks(new Long(2),a4,b1),
                    new AuthorsBooks(new Long(3),a1,b2),
                    new AuthorsBooks(new Long(4),a3,b2),
                    new AuthorsBooks(new Long(5),a1,b3),
                    new AuthorsBooks(new Long(6),a2,b3)
                )
            );
        };
    }

    @EventListener(ApplicationReadyEvent.class)
    void addNewEntity(){
        System.out.println("ready....");
    }

}
