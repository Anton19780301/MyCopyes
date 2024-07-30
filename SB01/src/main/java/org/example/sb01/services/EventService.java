package org.example.sb01.services;

import org.springframework.boot.context.event.ApplicationContextInitializedEvent;
import org.springframework.boot.context.event.ApplicationReadyEvent;
import org.springframework.boot.context.event.ApplicationStartedEvent;
import org.springframework.context.event.EventListener;
import org.springframework.stereotype.Component;

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

//    @Bean
//    public CommandLineRunner commandLineRunner(BooksRepo booksRepo) {
//        return args -> {
//            booksRepo.saveAll(List.of(
//                    new Books(0,"Book1",[]),
//                    new Books(1,"Book2",[]),
//                    new Books(2,"Book3",[])));
//        };
//    }

    @EventListener(ApplicationReadyEvent.class)
    void addNewEntity(){
        System.out.println("ready....");
    }

}
