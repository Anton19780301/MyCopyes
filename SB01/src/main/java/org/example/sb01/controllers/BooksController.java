package org.example.sb01.controllers;

import lombok.AllArgsConstructor;
import org.example.sb01.entity.Books;
import org.example.sb01.models.BookModel;
import org.example.sb01.services.BookService;
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
    public void addBook(@RequestBody Books book){
        bookService.addBook(book);
    }

    //put - апдейт
    @PutMapping(path = "path")
    public void updateBook(@RequestBody Books book){
        bookService.updateBook(book);
    }

    @DeleteMapping(path = "delete/{bookID}")
    public void deleteBook(@PathVariable("bookID") Long bookID){
        bookService.deleteBook(bookID);
    }

}