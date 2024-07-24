package org.example.sb01.controllers;


import lombok.AllArgsConstructor;
import org.example.sb01.entity.Authors;
import org.example.sb01.repositories.AuthorsRepo;
import org.springframework.web.bind.annotation.*;

@AllArgsConstructor
@RestController
@RequestMapping("authors")
public class AuthorController {
    private AuthorsRepo authors;

    //get - запросить инфу
    @GetMapping(path = "all")
    public String getAllAuthors(){
        return "all Authors";
    }

    //get - запросить инфу
    @GetMapping(path = "author/{authorID}")
    public String getAuthor(@PathVariable("authorID") Long authorID){
        return "Authors " + authorID;
    }

    //post - создать инфу
    @PostMapping(path = "add")
    public void addAuthor(@RequestBody Authors author){

    }

    //put - апдейт
    @PutMapping(path = "path")
    public void updateAuthor(@RequestBody Authors author){

    }

    @DeleteMapping(path = "delete/{authorID}")
    public void deleteAuthor(@PathVariable("authorID") Long authorID){

    }

    //@PatchMapping() - частичный апдейт
}
