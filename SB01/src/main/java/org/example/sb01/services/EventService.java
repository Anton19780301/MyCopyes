package org.example.sb01.services;

import org.springframework.boot.context.event.ApplicationContextInitializedEvent;
import org.springframework.boot.context.event.ApplicationReadyEvent;
import org.springframework.boot.context.event.ApplicationStartedEvent;
import org.springframework.context.event.EventListener;
import org.springframework.stereotype.Component;

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
    @EventListener(ApplicationReadyEvent.class)
    void addNewEntity(){
        System.out.println("ready....");
    }

}
