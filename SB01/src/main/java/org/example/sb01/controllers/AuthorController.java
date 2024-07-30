package org.example.sb01.controllers;

import lombok.AllArgsConstructor;
import org.example.sb01.entity.Authors;
import org.example.sb01.exeptions.NoAuthorExeption;
import org.example.sb01.exeptions.NoBookExeption;
import org.example.sb01.models.AuthorsModel;
import org.example.sb01.services.AuthorService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("authors")
public class AuthorController {
    private AuthorService authorService;

    //get - запросить инфу
    @GetMapping(path = "all")
    public List<AuthorsModel> getAllAuthors(){
        return authorService.getAllAuthors();
    }

    //get - запросить инфу
    @GetMapping(path = "author/{authorID}")
    public AuthorsModel getAuthor(@PathVariable("authorID") Long authorID){
        return authorService.getAuthor(authorID);
    }

    //post - создать инфу
    @PostMapping(path = "add")
    public ResponseEntity addAuthor(@RequestBody Authors author){
        try {
            authorService.addAuthor(author);
            return ResponseEntity.ok("Автор успешно добавлен");
        }
        catch (NoAuthorExeption e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    //put - апдейт
    @PutMapping(path = "path")
    public ResponseEntity updateAuthor(@RequestBody Authors author){
        try {
            authorService.updateAuthor(author);
            return ResponseEntity.ok("Автор успешно обновлен");
        }
        catch (NoAuthorExeption e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    @DeleteMapping(path = "delete/{authorID}")
    public ResponseEntity deleteAuthor(@PathVariable("authorID") Long authorID){
        try {
            authorService.deleteAuthors(authorID);
            return ResponseEntity.ok("Автор успешно удален");
        }
        catch (NoAuthorExeption e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    //@PatchMapping() - частичный апдейт
}
