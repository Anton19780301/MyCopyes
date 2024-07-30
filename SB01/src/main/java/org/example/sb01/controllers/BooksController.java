package org.example.sb01.controllers;

import lombok.AllArgsConstructor;
import org.example.sb01.entity.Books;
import org.example.sb01.exeptions.NoBookExeption;
import org.example.sb01.models.BookModel;
import org.example.sb01.services.BookService;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@AllArgsConstructor
@RestController
@RequestMapping("books")
public class BooksController {

    BookService bookService;
    //get - запросить инфу
    @GetMapping(path = "all")
    public List<BookModel> getAllBooks(){
        return bookService.getAllBooks();
    }

    //get - запросить инфу
    @GetMapping(path = "books/{bookID}")
    public BookModel getBook(@PathVariable("bookID") Long bookID){
        return bookService.getBook(bookID);
    }

    //post - создать инфу
    @PostMapping(path = "add")
    public ResponseEntity addBook(@RequestBody Books book){
        try {
            bookService.addBook(book);
            return ResponseEntity.ok("Книга успешно добавлена");
        }
        catch (NoBookExeption e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    //put - апдейт
    @PutMapping(path = "path")
    public ResponseEntity updateBook(@RequestBody Books book){
        try {
            bookService.updateBook(book);
            return ResponseEntity.ok("Книга успешно обновлена");
        }
        catch (NoBookExeption e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }

    @DeleteMapping(path = "delete/{bookID}")
    public ResponseEntity deleteBook(@PathVariable("bookID") Long bookID){
        try {
            bookService.deleteBook(bookID);
            return ResponseEntity.ok("Книга успешно удалена");
        }
        catch (NoBookExeption e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
        catch (Exception e){
            return ResponseEntity.badRequest().body(e.getMessage());
        }
    }
}