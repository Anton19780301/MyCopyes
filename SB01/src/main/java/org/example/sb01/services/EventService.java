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
        return args -> {
            booksRepo.saveAll(List.of(
                    new Books( "Bible"),
                    new Books("Quran"),
                    new Books("Avesta")
                )
            );

            authorsRepo.saveAll(List.of(
                    new Authors( "Anton"),
                    new Authors( "Zaratushtra"),
                    new Authors( "Muhhamad"),
                    new Authors( "Moses")
                )
            );

//            abRepo.saveAll(List.of(
//                    new AuthorsBooks(),
//                    new AuthorsBooks(),
//                    new AuthorsBooks()
//                )
//            );
        };
    }

    @EventListener(ApplicationReadyEvent.class)
    void addNewEntity(){
        System.out.println("ready....");
    }

}
